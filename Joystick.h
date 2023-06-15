#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

class Joystick{
 private:
  void get_angle();
  void get_forces();
  uint8_t pinx;
  uint8_t piny;

 public:
  Joystick(uint8_t pinX, uint8_t pinY);
  float x;
  float y;
  float angle;
  float forces;
  void begin();
  void update();

};
#endif
