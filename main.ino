#include <Arduino.h>
#include "motor.h"
#include "ircodes.h"
#include <IRremote.h>

#define STATUS_LED 13
#define LEFT_EYE_LED 3
#define RIGHT_EYE_LED 4
#define IR_TOP 21
#define IR_REAR 7
#define SPEAKER 6
#define H_BRIDGE_TOP_ENABLE 15
#define H_BRIDGE_TOP_A 14
#define H_BRIDGE_TOP_B 5
#define H_BRIDGE_MVMT_ENABLE 8
#define H_BRIDGE_MVMT_A 17
#define H_BRIDGE_MVMT_B 16
#define DISTANCE_SENS 20

Motor headMotor;
Motor mvmtMotor;

IRrecv irrecvRear(IR_REAR);

unsigned long lastTickMillis = 0;
unsigned long last5Millis = 0;
unsigned long last10Millis = 0;
unsigned long last500Millis = 0;
boolean statusLedValue = LOW;
boolean frontBtnLastKnownValue = false;

void setup() {
  Serial.begin(9600);

  // All my outputs. Tons!!!
  pinMode(STATUS_LED, OUTPUT);
  pinMode(LEFT_EYE_LED, OUTPUT);
  pinMode(RIGHT_EYE_LED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
  pinMode(DISTANCE_SENS, INPUT);

  // Inputs. Wayyyy less.
  pinMode(IR_TOP, INPUT);
  pinMode(IR_REAR, INPUT);

  irrecvRear.enableIRIn();
  irrecvRear.blink13(true);

  // Own libraries
  // This also initializes the necessary pins to output.
  headMotor.init(H_BRIDGE_TOP_ENABLE, H_BRIDGE_TOP_A, H_BRIDGE_TOP_B);
  mvmtMotor.init(H_BRIDGE_MVMT_ENABLE, H_BRIDGE_MVMT_A, H_BRIDGE_MVMT_B);
  mvmtMotor.enable();

  // Set up some eyes
  analogWrite(LEFT_EYE_LED, 128);
  analogWrite(RIGHT_EYE_LED, 128);
}

// Is called as fast as possible with the delta the millisecond difference since last call.
// WARNING: the delta can be 0!
void tickDispatch(unsigned long delta) {
  lastTickMillis = millis();

  boolean motorShouldTurn = false;
  boolean eyesShouldLight = false;

  decode_results results;
  if (irrecvRear.decode(&results)) {
    if (results.value == IRR_Turn) {
      mvmtMotor.backwards();
      motorShouldTurn = true;
    }

    if (results.value == IRR_Forwards) {
      mvmtMotor.forwards();
      motorShouldTurn = true;
    }

    if (results.value == IRR_Eyes) {
      analogWrite(LEFT_EYE_LED, 400);
      analogWrite(RIGHT_EYE_LED, 400);
      eyesShouldLight = true;
    }

    irrecvRear.resume(); // Receive the next value
  }

  if (!motorShouldTurn) {
    mvmtMotor.stop();
  }
  if (!eyesShouldLight) {
    analogWrite(LEFT_EYE_LED, 128);
    analogWrite(RIGHT_EYE_LED, 128);
  }
}

void fiveMillisDispatch(unsigned long delta) {
  // placeholder
  last5Millis = millis();
}

void tenMillisDispatch(unsigned long delta) {
  //placeholder
  last10Millis = millis();
}

void halfSecondDispatch(unsigned long delta) {
  digitalWrite(STATUS_LED, !statusLedValue);
  statusLedValue = !statusLedValue;
  last500Millis = millis();
}

// This is a dispatch function.
// NOTHING should ever by directly here. Everything MUST be in a dispatch function.
void loop() {

  // the delta can't underflow since time travel hasn't been invented yet...
  tickDispatch(millis() - lastTickMillis);

  // This code WILL break after about 50 days due to `millis()` overflowing. Not an issue.
  // Additional dispatches may be added if necessary
  if (millis() >= last5Millis + 5) {
    fiveMillisDispatch(millis() - last5Millis);
  }
  if (millis() >= last10Millis + 10) {
    tenMillisDispatch(millis() - last10Millis);
  }
  if (millis() >= last500Millis + 500) {
    halfSecondDispatch(millis() - last500Millis);
  }
}
