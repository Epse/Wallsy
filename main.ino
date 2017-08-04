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
#DEFINE H-BRIDGE_MVMT_ENABLE 21
#DEFINE H-BRIDGE_MVMT_A 17
#DEFINE H-BRIDGE_MVMT_B 16

void setup() {
  // All my outputs. Tons!!!
  pinMode(STATUS_LED, OUTPUT);
  pinMode(LEFT_EYE_LED, OUTPUT);
  pinMode(RIGHT_EYE_LED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
  pinMode(H-BRIDGE_TOP_ENABLE, OUTPUT);
  pinMode(H-BRIDGE_TOP_A, OUTPUT);
  pinMode(H-BRIDGE_TOP_B, OUTPUT);
  pinMode(H-BRIDGE_MVMT_ENABLE, OUTPUT);
  pinMode(H-BRIDGE_MVMT_A, OUTPUT);
  pinMode(H-BRIDGE_MVMT_B, OUTPUT);

  // Inputs. Wayyyy less.
  pinMode(FRONT_BTN, INPUT);
  pinMode(IR_TOP, INPUT);
  pinMode(IR_REAR, INPUT);
}

void loop() {
}