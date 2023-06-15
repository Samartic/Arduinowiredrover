#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

class Joystick{
  private:
    float get_angles(float x, float y);
    float get_forces(float x, float y);

  public:
    Joystick(float x, float y);
    long x;
    long y;
    float angle;
    float forces;

};

#endif
