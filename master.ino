#include <Wire.h>

//---------------------------------------------ADDRESS PARKING-----------------------------------

#define motorLeft  = 0
#define motorRight = 1  // the adresse are fictive and should be really address before running
#define motorCamY  = 2
#define motorCamX  = 3

// rover 
#define VRx = A0
#define VRy = A1
#define RSW = 2

int RxPosition = 0;
int RyPosition = 0;

// camera

#define CRx = 3
#define CRy = 4
#define CSW = 5

int CxPosition = 0;
int CyPosition = 0;


//----------------------------------------FONCTION PARKING -- DEFINITION LINE 93 -----------------

int get_joystickRover(VRx, VRy);
int get_joystickCamera(CRx, CRy);
int get_locomotion(mapX, mapY);
int get_cameramotion(mapCx, mapCy);
void moveRover(Mrover);
void moveCamera(Mcamera);


//-------------------------------------------STRUCT PARKING -----------------------------------------

type def struct 
{
 int direction;
 int force;
}
motion; 

tydef struct 
{
    int mapY = 0;
    int mapX = 0;
}
joystick;


int setup (void) //---------------------------------------INITIALISATION--------------------------------------------
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

int loop (void) //--------------------------------------ACTUAL PROGRAM -----------------------------------------------
{
 joystick rover;
 joystick camera;
 motion Mrover;
 motion Mcamera;
 rover = get_joystickRover(VRx, VRy);
 camera = get_joystickCamera(CRx, CRy);
 Mrover = get_locomotion(rover);
 Mcamera = get_cameramotion(camera);
 moveRover(Mrover);
 moveCamera(Mcamera);
}

//-----------------------------------------------------FONCTION DEFINITION------------------------------------------------
int get_joystickRover(VRx, VRy, joystick rover)
{
    RxPosition = analogRead(VRx);
    RyPosition = analogRead(VRy);
    rover.mapX = map(RxPosition, 0, 1023, -512, 512);
    rover.mapY = map(RyPosition, 0, 1023, -512, 512);

    return rover;
}

int get_joystickCamera(CRx, CRy, joystick camera);
{
    CxPosition = analogRead(CRx);
    CyPosition = analogRead(CRy);
    camera.mapX = map(CxPosition, 0, 1023, -512, 512);
    camera.mapY = map(CyPosition, 0, 1023, -512, 512);

    return camera;
}

int get_locomotion(joystick rover, motion Mrover)
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
  if (rover.mapX > -256 && rover.mapX < 256 && rover.mapY > -256 && rover.mapY < 256 && Mrover.force =! 1)
  {
    Mrover.force = 2;
  }
  if (rover.mapX > -384 && rover.mapX < 384 && rover.mapY > -384 && rover.mapY < 384 && Mrover.force != 1 && Mrover.force != 2)
  {
    Mrover.force = 3;
  }
  if (rover.mapX > -512 && rover.mapX < 512 && rover.mapY > -512 && rover.mapY < 512 && Mrover.force != 1 && Mrover.force != 2 && Mrover.force != 3)
  {
    Mrover.force = 4
  }

  return Mrover;
}
int get_cameramotion(joystick camera, motion Mcamera)
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
    Mcamera.direction = 0
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
  if (camera.mapX > -256 && camera.mapX < 256 && camera.mapY > -256 && camera.mapY < 256 && Mcamera.force =! 1)
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
void moveRover(get_locomotion)
{
  //TO DO 
}
void moveCamera(get_cameramotion)
{
// TO DO
}
