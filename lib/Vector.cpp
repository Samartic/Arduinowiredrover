#include "Vector.h"

#include <Arduino.h>

Vector::Vector(float Angle, float Forces){
  float angle = Angle;
  float force = Forces;
}
void Vector::set(float a, float f){
  #if (a > 360)
  #error "Not a valid Angle!"
  #endif

  angle = a;
  force = f;
}
