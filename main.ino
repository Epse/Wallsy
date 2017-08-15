#include "motor.h"

#define STATUS_LED 13
#define LEFT_EYE_LED 3
#define RIGHT_EYE_LED 4
#define FRONT_BTN 2
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

unsigned long lastMillis;
boolean statusLedValue;

void setup() {
  // All my outputs. Tons!!!
  pinMode(STATUS_LED, OUTPUT);
  pinMode(LEFT_EYE_LED, OUTPUT);
  pinMode(RIGHT_EYE_LED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
  pinMode(DISTANCE_SENS, INPUT);

  // Inputs. Wayyyy less.
  pinMode(FRONT_BTN, INPUT);
  pinMode(IR_TOP, INPUT);
  pinMode(IR_REAR, INPUT);

  // Own libraries
  // This also initializes the necessary pins to output.
  headMotor.init(H_BRIDGE_TOP_ENABLE, H_BRIDGE_TOP_A, H_BRIDGE_TOP_B);
  mvmtMotor.init(H_BRIDGE_MVMT_ENABLE, H_BRIDGE_MVMT_A, H_BRIDGE_MVMT_B);
}

// Is called as fast as possible with the delta the millisecond difference since last call.
// WARNING: the delta can be 0!
void tickDispatch(unsigned long delta) {
  if (digitalRead(FRONT_BTN)) {
    //TODO: haven't got a clue what this is for.
  }
  // IR code should come here, too.
}

void 5MillisDispatch(unsigned long delta) {
  // placeholder
}

void 10MillisDispatch(unsigned long delta) {
  //placeholder
}

void halfSecondDispatch(unsigned long delta) {
  digitalWrite(STATUS_LED, !statusLedValue);
}



// This is a dispatch function.
// NOTHING should ever by directly here. Everything MUST be in a dispatch function.
void loop() {
  // the delta can't underflow since time travel hasn't been invented yet...
  tickDispatch(Millis() - lastMillis);

  // This code WILL break after about 50 days due to `Millis()` overflowing. Not an issue.
  // Additional dispatches may be added if necessary
  if (Millis() >= lastMillis + 5) {
    5MillisDispatch(Millis() - lastMillis);
  }
  if (Millis >= lastMillis + 10) {
    10MillisDispatch(Millis() - lastMillis);
  }
  if (Millis >= lastMillis + 500) {
    halfSecondDispatch(Millis() - lastMillis);
  }

  // I think this is obvious
  lastMillis = Millis();
}
