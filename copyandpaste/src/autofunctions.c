#include "autofunctions.h"
#include "ports.h"
#include "main.h"



void autoDrive(int direction, int target){

  int leftPower;
  int rightPower;
  int tics;
  //int direction;
//  int target;
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

        motorSet(DriveFL, direction*-rightPower);
        motorSet(DriveBL, direction*rightPower);
        motorSet(DriveBR, direction*-leftPower);
        motorSet(DriveFR, direction*leftPower);

      delay(20);
}
}
