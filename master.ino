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


//----------------------------------------FONCTION PARKING -- DEFINITION LINE 92 -----------------

int get_joystickRover(VRx, VRy);
int get_joystickCamera(CRx, CRy);
int get_locomotion(mapX, mapY);
int get_cameramotion(mapCx, mapCy);
void moveRover(get_locomotion);
void moveCamera(get_cameramotion);


//-------------------------------------------STRUCT PARKING -----------------------------------------

struct locomotion 
{
 int direction;
 int force;
}
struct cameramotion
{
  int direction;
  int force;
}
struct joystickRover
{
    int mapY = 0;
    int mapX = 0;
}
struct joystickCameera
{
    int mapY = 0;
    int mapX = 0;
}

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
 joystickRover = get_joystickRover(VRx, VRy);
 joystickCamera = get_joystickCamera(CRx, CRy);
 rovermotion = get_rovermotion(joystickRover);
 cameramotion = get_cameramotion(joystickCamera);
 moveRover(locomotion);
 moveCamera(cameramotion);
}

//-----------------------------------------------------FONCTION DEFINITION------------------------------------------------
int get_joystickRover(VRx, VRy)
{
    RxPosition = analogRead(VRx);
    RyPosition = analogRead(VRy);
    joystickRover.mapX = map(RxPosition, 0, 1023, -512, 512);
    joystickRover.mapY = map(RyPosition, 0, 1023, -512, 512);

    return joystickRover;
}

int get_joystickCamera(CRx, CRy);
{
    CxPosition = analogRead(CRx);
    CyPosition = analogRead(CRy);
    joystickCamera.mapX = map(CxPosition, 0, 1023, -512, 512);
    joystickCamera.mapY = map(CyPosition, 0, 1023, -512, 512);

    return joystickRover;
}

int get_locomotion(joystickmotion)
{
 // to do
  return locomotion;
}
int get_cameramotion(joystickcamera)
{
    // to do
  return cameramotion;
}
void moveRover(get_locomotion)
{
  //TO DO 
}
void moveCamera(get_cameramotion
{
// TO DO
}

