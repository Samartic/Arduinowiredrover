#include "joystick.h"
#include "transmission.h"

Joystick rover(A0, A2, 01); // must be validated
Joystick camera(A4, A5, 02); // must be validated


void setup() {
  rover.begin();
  camera.begin();
  Serial.begin(115200);
}

void loop() {
  
  rover.update();
  camera.update();
  Transmission t(rover.angle, rover.forces, rover.isengage(), camera.x, camera.y, camera.isengage());
  Serial.write(t, len(t));

}
 
