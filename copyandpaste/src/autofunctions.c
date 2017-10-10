#include "autofunctions.h"
#include "ports.h"
#include "main.h"
#include "drive.h"
#include "lift.h"


void autoDrive(int direction, int target){

  int leftPower;
  int rightPower;
  int tics;
  int ticsL;
  int ticsR;

  tics = 0;
  encoderReset(encoder_L);
  encoderReset(encoder_R);

while(tics < target){

  ticsL = encoderGet(encoder_L);
  ticsR = encoderGet(encoder_R);
  tics = (ticsL + ticsR)/2;

  lcdPrint(uart1, 1, "encoder%d", tics);


if(tics < target){
      leftPower = -127;
      rightPower = 127;}
    else{
      leftPower = 0;
      rightPower = 0;}
    // checking R
driveSet(direction*leftPower,direction*rightPower);
      /*  motorSet(DriveFL, direction*-rightPower);
        motorSet(DriveBL, direction*rightPower);
        motorSet(DriveBR, direction*-leftPower);
        motorSet(DriveFR, direction*leftPower);
*/
      delay(20);
}
//
}
void gyroTurn(int direction, int targetTurn)
{
  int rightPower;
  int leftPower;
  int gyroAverage = 0;
  gyroReset(gyro);

  while(gyroAverage < targetTurn)
  {
    gyroAverage = gyroGet(gyro); // gyro position update (using util function)

    if(gyroAverage < targetTurn){
      rightPower = 127;
      leftPower = 127;}
    else if (gyroAverage > targetTurn){
      rightPower = 127;
      leftPower = 127;}
    else{
      rightPower = 0;
      leftPower = 0;}

    driveSet(direction*leftPower, direction*rightPower);
      delay(20);
  }


}

void mobileGoalOut(int target){
int autoEncoderLift = encoderGet(encoderLift);
if(autoEncoderLift < target)
{
liftSet(127);
}
}
void mobileGoalIn(int target)
{
int liftPower;
int autoEncoderLift = encoderGet(encoderLift);
if(autoEncoderLift > target)
{
liftSet(-127);
}
}
