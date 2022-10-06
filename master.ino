#include <wire.h>

//---------------------------------------------ADDRESS PARKING-----------------------------------

#define motorLeft  = 0
#define motorRight = 1  // the adresse are fictive and should be really address before running
#define motorCamY  = 2
#define motorCamX  = 3

#define joystickmotion = 4
#define joystickcam = 5

//----------------------------------------FONCTION PARKING -- DEFINITION LINE 64 -----------------

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


pinMode(joystickmotion, INPUT);
  // joystick initialisation TO ADD
pinMode(joystickcam, INPUT);
  // joystick initialisation TO ADD

}

int loop (void) //--------------------------------------ACTUAL PROGRAM -----------------------------------------------
{
  onReceiveEven();
  locomotion = get_locomotion(mapX, mapY);
  cameramotion = get_cameramotion(mapCx, mapCy);
  moveRover(locomotion);
  moveCamera(cameramotion);
}

//-----------------------------------------------------FONCTION DEFINITION------------------------------------------------
int get_locomotion(mapX, mapY)
{
  // TO DO
  return locomotion;
}
int get_cameramotion(mapCx, mapCy)
{
  // TO DO 
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

