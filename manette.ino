#include "joystick.h"
#include "transmission.h"

Joystick rover(A0, A2, 01); // must e validated
Joystick camera(A4, A5, 02); // must e validated


void setup() {
  rover.begin();
  camera.begin();
  Serial.begin(115200);
  // put your setup code here, to run once:

}

void loop() {
  
  rover.update();
  camera.update();
  Transmission t = [rover.angle
                        , rover.forces
                        , rover.ispress()
                        , camera.x
                        , camera.y
                        , camera.ispress()
                        ];

  Serial.write(t, len(t));


 
