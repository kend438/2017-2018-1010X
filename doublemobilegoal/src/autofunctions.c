#include "autofunctions.h"
#include "main.h"
#include "drive.h"
#include "mgten.h"
#include "mgtwenty.h"


void autoDrive(int direction, int target){

  int leftPower;
  int rightPower;
  int tics;
  int ticsL;
  int ticsR;

  tics = 0;
  encoderReset(encoderL);
  encoderReset(encoderR);

while(tics < target){

  ticsL = encoderGet(encoderL);
  ticsR = encoderGet(encoderR);
  tics = (abs(ticsL) + abs(ticsR))/2;


if(tics < target){
      leftPower = -127;
      rightPower = 127;}
    else{
      leftPower = 0;
      rightPower = 0;}
    // checking R
driveSet(direction*rightPower,direction*leftPower);
      delay(20);
}
}
/*
void gyroTurn(int direction, int targetTurn, int timeout)
{
gyroReset(gyro);

int error = 0;
int error_last = 0;
int error_diff = 0;
int error_sum = 0;
int pos =  abs(gyroGet(gyro));
int kp = 0.1;
int ki = 0;
int kd = 0;
int p;
int d;
int i;
int startTime = millis();
while((millis()-startTime)<timeout)
{
lcdPrint(uart1, 1, "pos%d", pos);

int startTime = millis();
if((millis()-startTime) > timeout){break;}

pos = abs(gyroGet(gyro));
error =  targetTurn - pos;

error_diff = error - error_last;
error_last = error;
error_sum  += error; // same as errorsum  = errorsum + error

p = kp * error;

d  = kd * error_diff;
if(error < 5) //icap
{i = ki * error_sum;}

int power = p+i+d;

driveSet(direction*p, direction*p);
delay(20);
}
}
*/
void gyroTurn(int direction, int targetTurn)
{
  int rightPower;
  int leftPower;
  int  gyroAverage = 0;
  gyroReset(gyro);
while(gyroAverage < targetTurn){
  gyroAverage = abs(gyroGet(gyro));
  lcdPrint(uart1, 2, "GyroPos%d", gyroAverage);
  if(gyroAverage < targetTurn)
  {
    rightPower = 45;
    leftPower = 45;
  }
  else if(gyroAverage < (0.75*targetTurn))
  {
    rightPower = 90;
    leftPower = 90;
  }
    else
  {
  rightPower = 0;
  leftPower = 0;
  }
  driveSet(direction*leftPower, direction*rightPower);
  delay(20);
}
}

void mobileGoalTen(int direction, int target){
int pos = encoderGet(encoderTen);
int liftPower;
if(direction == 1){
while(pos<target)
{
pos = encoderGet(encoderTen);
if(pos < target){liftPower = 127;}
}
if(direction == -1){
  while(pos > target){
  pos = encoderGet(encoderTen);
  if(pos > target){liftPower = -127;}
  }
}
else{liftPower = 0;}
mgtenSet(liftPower);
delay(20);
}
}

void stop()
{
  while (1) {
  motorSet(1, 0);
  motorSet(2, 0);
  motorSet(3, 0);
  motorSet(4, 0);
  motorSet(5, 0);
  motorSet(6, 0);
  motorSet(7, 0);
  motorSet(8, 0);
  motorSet(9, 0);
  motorSet(10, 0);
}
}
