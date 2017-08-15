#ifndef MOTOR_H

// here be code
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

#endif
