#include "motor.h"
#include <Arduino.h>

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
