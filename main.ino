#DEFINE STATUS_LED 13
#DEFINE LEFT_EYE_LED 3
#DEFINE RIGHT_EYE_LED 4
#DEFINE FRONT_BTN 2
#DEFINE IR_TOP 21
#DEFINE IR_REAR 7
#DEFINE SPEAKER 6
#DEFINE H-BRIDGE_TOP_ENABLE 15
#DEFINE H-BRIDGE_TOP_A 14
#DEFINE H-BRIDGE_TOP_B 5
#DEFINE H-BRIDGE_MVMT_ENABLE 8
#DEFINE H-BRIDGE_MVMT_A 17
#DEFINE H-BRIDGE_MVMT_B 16
#DEFINE DISTANCE_SENS 20

class Motor {
private:
  int enablePin;
  int aPin;
  int bPin;

public:
  Motor(initEnablePin, initAPin, initBPin) {
    enablePin = initEnablePin;
    aPin = initAPin;
    bPin = initBPin;

    pinMode(enablePin, OUTPUT);
    pinMode(aPin, OUTPUT);
    pinMode(bPin, OUTPUT);
  }

  void disable() {
    digitalWrite(enablePin, LOW);
  }

  void enable() {
    digitalWrite(enablePin, HIGH);
  }

  void forwards() {
    digitalWrite(aPin, LOW);
    digitalWrite(bPin, HIGH);
  }

  void backwards() {
    digitalWrite(aPin, HIGH);
    digitalWrite(bPin, LOW);
  }

  void stop() {
    digitalWrite(aPin, LOW);
    digitalWrite(bPin, LOW);
  }
}

Motor headMotor;
Motor mvmtMotor;

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
  headMotor.init(H-BRIDGE_TOP_ENABLE, H-BRIDGE_TOP_A, H-BRIDGE_TOP_B);
  mvmtMotor.init(H-BRIDGE_MVMT_ENABLE, H-BRIDGE_MVMT_A, H-BRIDGE_MVMT_B);
}

void loop() {
}
