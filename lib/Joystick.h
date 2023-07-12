#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

class Joystick{
 private:
  void get_angle();
  void get_forces();
  uint8_t pinx;
  uint8_t piny;
  uint8_t pinp;
  float xValue;
  float yValue;
  int clicked;

 public:
  Joystick(uint8_t pinX, uint8_t pinY, uint8_t pinP);
  float x;
  float y;
  bool p;
  float angle;
  float forces;
  void begin();
  void update();
  bool ispressed();
  bool isengaged();
  int countclick();
  void resetclick();

};
#endif
