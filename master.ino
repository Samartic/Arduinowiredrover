#include <Wire.h>
#include <stdio.h>
#include <stdlib.h>
//---------------------------------------------ADDRESS PARKING-----------------------------------

#define motorLeft 0
#define motorRight 1  // the adresse are fictive and should be really address before running
#define motorCamY 2
#define motorCamX 3

// rover
#define VRx A0
#define VRy A1
#define RSW 2

int RxPosition = 0;
int RyPosition = 0;

// camera

#define CRx 3
#define CRy 4
#define CSW 5

int CxPosition = 0;
int CyPosition = 0;

//-------------------------------------------STRUCT PARKING -----------------------------------------

typedef struct
{
  int direction = 0;
  int force = 0;
}
motion;

typedef struct
{
  int mapY = 0;
  int mapX = 0;
}
joystick;

//----------------------------------------FONCTION PARKING -- DEFINITION LINE 93 -----------------

joystick get_joystickRover(VRx, VRy, joystick rover);
joystick get_joystickCamera(CRx, CRy, joystick camera);
motion get_locomotion(joystick rover, motion Mrover);
motion get_cameramotion(joystick camera, motion Mcamera);
void moveRover(motion Mrover, motorLeft, motorRight);
void moveCamera(motion Mcamera, motorCamX, motorCamY);




void setup () //---------------------------------------INITIALISATION--------------------------------------------
{
  pinMode(motorLeft, OUTPUT);
  digitalWrite(motorLeft, LOW);

  pinMode(motorRight, OUTPUT);
  digitalWrite(motorRight, LOW);

  pinMode(motorCamY, OUTPUT);
  digitalWrite(motorCamY, LOW);

  pinMode(motorCamX, OUTPUT);
  digitalWrite(motorCamX, LOW);

  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);

  pinMode(CRx, INPUT);
  pinMode(CRy, INPUT);

}

void loop () //--------------------------------------ACTUAL PROGRAM -----------------------------------------------
{
  joystick rover;
  joystick camera;
  motion Mrover;
  motion Mcamera;
  rover = get_joystickRover(VRx, VRy, rover);
  camera = get_joystickCamera(CRx, CRy, camera);
  Mrover = get_locomotionrover(joystick rover, motion Mrover);
  Mcamera = get_cameramotion(joystick camera, motion Mcamera);
  moveRover(motion Mrover, motorLeft, motorRight);
  moveCamera(motion Mcamera, motorCamX, motorCamY);
}

//-----------------------------------------------------FONCTION DEFINITION------------------------------------------------
joystick get_joystickRover(VRx, VRy, joystick rover)
{
  RxPosition = analogRead(VRx);
  RyPosition = analogRead(VRy);
  rover.mapX = map(RxPosition, 0, 1023, -512, 512);
  rover.mapY = map(RyPosition, 0, 1023, -512, 512);

  return rover;
}

joystick get_joystickCamera(CRx, CRy, joystick camera)
{
  CxPosition = analogRead(CRx);
  CyPosition = analogRead(CRy);
  camera.mapX = map(CxPosition, 0, 1023, -512, 512);
  camera.mapY = map(CyPosition, 0, 1023, -512, 512);

  return camera;
}

motion get_locomotion(joystick rover, motion Mrover)
{
  Mrover.direction = 0;
  Mrover.force = 0;
  //-------------------------------------condtion for Direction
  if (rover.mapX < 0) //     1 = up 2 = down 3 = left 4 = right 0= NUL
  {
    Mrover.direction = 3;
  }
  else if (rover.mapX > 0)
  {
    Mrover.direction = 4;
  }
  else if (rover.mapY < 0)
  {
    Mrover.direction = 2;
  }
  else if (rover.mapY > 0)
  {
    Mrover.direction = 1;
  }
  //---------------------------------condition for force

  if (rover.mapX == 0 && rover.mapY == 0)
  {
    Mrover.force = 0;
  }
  if (rover.mapX > -128 && rover.mapX < 128 && rover.mapY > -128 && rover.mapY < 128 )
  {
    Mrover.force = 1;
  }
  if (rover.mapX > -256 && rover.mapX < 256 && rover.mapY > -256 && rover.mapY < 256 && Mrover.force != 1)
  {
    Mrover.force = 2;
  }
  if (rover.mapX > -384 && rover.mapX < 384 && rover.mapY > -384 && rover.mapY < 384 && Mrover.force != 1 && Mrover.force != 2)
  {
    Mrover.force = 3;
  }
  if (rover.mapX > -512 && rover.mapX < 512 && rover.mapY > -512 && rover.mapY < 512 && Mrover.force != 1 && Mrover.force != 2 && Mrover.force != 3)
  {
    Mrover.force = 4;
  }

  return Mrover;
}
motion get_cameramotion(joystick camera, motion Mcamera)
{
  //------------------------------Condition Direction ------------------------------------
  if (camera.mapX < 0) //     1 = up 2 = down 3 = left 4 = right 0 = NUL
  {
    Mcamera.direction = 2;
  }
  else if (camera.mapX > 0)
  {
    Mcamera.direction = 3;
  }
  else if (camera.mapY < 0)
  {
    Mcamera.direction = 2;
  }
  else if (camera.mapY > 0)
  {
    Mcamera.direction = 0;
  }

    //-----------------------------------------Condition Force-----------------
  if (camera.mapX == 0 && camera.mapY == 0)
  {
    Mcamera.force = 0;
  }
  if (camera.mapX > -128 && camera.mapX < 128 && camera.mapY > -128 && camera.mapY < 128 )
  {
    Mcamera.force = 1;
  }
  if (camera.mapX > -256 && camera.mapX < 256 && camera.mapY > -256 && camera.mapY < 256 && Mcamera.force != 1)
  {
    Mcamera.force = 2;
  }
  if (camera.mapX > -384 && camera.mapX < 384 && camera.mapY > -384 && camera.mapY < 384 && Mcamera.force != 1 && Mcamera.force != 2)
  {
    Mcamera.force = 3;
  }
  if (camera.mapX > -512 && camera.mapX < 512 && camera.mapY > -512 && camera.mapY < 512 && Mcamera.force != 1 && Mcamera.force != 2 && Mcamera.force != 3)
  {
    Mcamera.force = 4;
  }

  return Mcamera;
}
void moveRover(motion Mrover, motorLeft, motorRight)
{
  int speed = 0;
  switch (Mrover.force)
  {
    case 1 :
      speed = 63;
      break;

    case 2 :
      speed = 126;
      break;

    case 3 :
      speed = 189;
      break;

    case 4 :
      speed = 254;
      break;

    default :
      speed = 0;

  }
  switch (Mrover.direction)
  {
    case 1 : // UP
      analogWrite(motorLeft, speed);
      analogWrite(motorRight, speed);
      break;

    case 2 : // Down
      analogWrite(motorLeft, (speed * -1));
      analogWrite(motorRight, (speed * -1));
      break;

    case 3 : // LEFT
      analogWrite(motorLeft, (speed * -1));
      analogWrite(motorRight, speed);
      break;

    case 4 : // RIGHT
      analogWrite(motorLeft, speed);
      analogWrite(motorRight, (speed * -1));
      break;

    default :
      delay(100);
  }
}
void moveCamera(motion Mcamera, motorCamX, motorCamY)
{
int speed = 0;
  switch (Mcamera.force)
  {
    case 1 :
      speed = 63;
      break;

    case 2 :
      speed = 126;
      break;

    case 3 :
      speed = 189;
      break;

    case 4 :
      speed = 254;
      break;

    default :
      speed = 0;

  }
  switch (Mcamera.direction)
  {
    case 1:   // UP
      analogWrite(motorCamY, speed);
      break;

    case 2:  // DOWN
      analogWrite(motorCamY, (speed * -1));
      break;

    case 3:  // LEFT
      analogWrite(motorCamX, (speed * -1));
      break;

    case 4:  // Right
      analogWrite(motorCamX, speed);
      break;

    default :
      delay(1000);
  }
}
