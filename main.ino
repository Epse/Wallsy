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

class Motor {
  int enablePin;
  int aPin;
  int bPin;

public:
  void init(int initEnablePin, int initAPin, int initBPin);
  void disable();
  void enable();
  void forwards();
  void backwards();
  void stop();
};

void Motor::init(int initEnablePin, int initAPin, int initBPin) {
  enablePin = initEnablePin;
  aPin = initAPin;
  bPin = initBPin;

  pinMode(enablePin, OUTPUT);
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}
void Motor::disable() {
  digitalWrite(enablePin, LOW);
}
void Motor::enable() {
  digitalWrite(enablePin, HIGH);
}
void Motor::forwards() {
  digitalWrite(aPin, LOW);
  digitalWrite(bPin, HIGH);
}
void Motor::backwards() {
  digitalWrite(aPin, HIGH);
  digitalWrite(bPin, LOW);
}
void Motor::stop() {
  digitalWrite(aPin, LOW);
  digitalWrite(bPin, LOW);
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
  headMotor.init(H_BRIDGE_TOP_ENABLE, H_BRIDGE_TOP_A, H_BRIDGE_TOP_B);
  mvmtMotor.init(H_BRIDGE_MVMT_ENABLE, H_BRIDGE_MVMT_A, H_BRIDGE_MVMT_B);
}

void loop() {
}
