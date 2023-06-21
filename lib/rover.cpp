#include "Rover.h"
#include <Arduino.h>
#include "Vector.h"
#include "MotorDriver.h"

Rover::Rover(MotorDriver left, MotorDriver right){
  MotorDriver l = left;
  Motordriver r = right;
}

void Rover::move(Vector v, bool p){

  // calibrating to see if we are in detail mode

  float f;
  if (p == True){
    f = v.forces /2;
  }
  else:{
    f = v.forces;
  }

// deciding which force to apply depending of the angle
float a = v.angle;
if (a == 0){
  l.move(f);
  r.move(f);
}
else if (a == 180){
  l.move(-f);
  r.move(-f);
}
else if (a < 90){
  r.move(f);
  a = map(v.angle, 0, 90, 0,100);
  l.move(a);
}
else if (a == 270){
  r.move(-f)
  l.move(f)
}

else if (a > 90 && a < 180){
  r.move(-f);
  a = map(v.angle, 0, 90, 0,100);
  l.move(-a);
}
else if (a > 180 && < 270){
l.move(f);
a = map(v.angle, 180, 270, 0, 100);
r.move(-a);
}
else {
l.move(f);
a = map(v.angle, 270, 360, 0, 100);
r.move(a);
}


}
