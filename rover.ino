#include "camera.h"
#include "MotorDriver.h"
#include "Rover.h"
#include "Transmission.h"
#include "vector.h"

//Make sure

Motordriver Left(01, 02, 03);
Motordriver Right(04, 05, 06);
Motordriver Cx(07, 08,09);
Motordriver Cy(10, 11,12);

Rover rovy(Left, Right);
Camera cam(Cx, Cy);

void setup(){
  Serial.begin(115200);
  rovy.begin();
  cam.begin();
}

void loop(){
  Serial.read(Transmission t, len(t));
  t.update();
  Vector v(t.a, t.f);
  v.update();
  rover.move(v, t.rp);
  camera.move(t.x,t.y, t.cp);
  
}


