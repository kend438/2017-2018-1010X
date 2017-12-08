#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"

//back drive is 1
//drive forwards is -1
// 1 is clockwise
//-1 is counterclockwise

 //mg all the way in 1820
 //mg all the way out 235
 //mg score 1400
 //mg pick up safe 800

// fourbar up is -127
//fourbar down is 127
//fourbar down 3200, up 1200

//double reverse all the way up -470, all the way down is 0
//double reverse up is negative, down is positive

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
lcdPrint(uart1, 1, "tics%d", tics);
      delay(20);
}
}

void gyroTurnPID(int direction, int targetTurn, int timeout, float kp, float kd)
{
gyroReset(gyro);

int error = 0;
int error_last = 0;
int error_diff = 0;
int error_sum = 0;
int pos =  0;
float ki = 0;
float p;
float d;
float i;
int drivepower;

int startTime = millis();
while((millis()-startTime)<timeout)
{
lcdPrint(uart1, 1, "error%d", error);
lcdPrint(uart1, 2, "power%d", drivepower);

pos = abs(gyroGet(gyro));
error =  targetTurn - pos;

error_diff = error - error_last;
error_last = error;
error_sum  += error; // same as errorsum  = errorsum + error

p = kp * error;

d  = kd * error_diff;
if(error < 5) //icap
{i = ki * error_sum;}

drivepower = p+i+d;
if(drivepower>90){drivepower = 90;}
if(drivepower<-90){drivepower = -90;}

int leftside = direction*drivepower;
int rightside = direction*drivepower;
driveSet(leftside, rightside);
delay(40);
}
lcdSetText(uart1,1,"done");
delay(20);
}

void gyroTurn(int direction, int targetTurn)
{
  int rightPower;
  int leftPower;
  int  gyroAverage = 0;
  gyroReset(gyro);
while(gyroAverage < targetTurn){
  gyroAverage = abs(gyroGet(gyro));
  lcdPrint(uart1, 2, "GyroPos%d", gyroAverage);
  if(gyroAverage < (0.6*targetTurn))
  {
    rightPower = 55;
    leftPower = 55;
  }
  else if(gyroAverage < targetTurn)
  {
    rightPower = 45;
    leftPower = 45;
  }
  driveSet(direction*leftPower, direction*rightPower);
  delay(20);
}
driveSet(-direction*15, -direction*15);
driveSet(0,0);
}
/*
void mobileGoalTen(int direction, int target){
int pos = encoderGet(encoderTen);
if(direction == 1){
pos= encoderGet(encoderTen);
while(pos>target)
{
pos = encoderGet(encoderTen);
if(pos>target){mgtenSet(-127);}
}
}
else{
  while(pos<target){
  pos = encoderGet(encoderTen);
  if(pos<target){mgtenSet(127);}
  }
}
mgtenSet(-30*direction);
}

*/
void mobileGoalTwenty(int direction, int target){
int pos = analogRead(3);
if(direction == 1){//out
 pos = analogRead(3);
 while(pos>target)//out
 {
   pos = analogRead(3);
   mgSet(-127);
 }
 }
else{
pos = analogRead(3);
 while(pos<target)
 {pos = analogRead(3);
  mgSet(127);}
}
mgSet(0);
}

void lift(int direction, int target){
int  pos = encoderGet(encoderTen);

///direction 1 is up, encoder decreases as lift moves up

if(direction == 1){
pos= encoderGet(encoderTen);
while(pos>target)
{
pos = encoderGet(encoderTen);
liftSet(-127);
delay(20);
}
}

if(direction == -1){
  while(pos<target){
  pos = encoderGet(encoderTen);
liftSet(127);
  delay(20);
  }
  }

liftSet(-20*direction); //-20*direction
}



void fourbar(int direction, int target){
  int pos = analogRead(1);
  if(direction == 1){
   pos = analogRead(1);
   while(pos>target)
   {
     pos = analogRead(1);
     fourSet(-127);
   }
   }
  else{
  pos = analogRead(1);
   while(pos<target)
   {pos = analogRead(1);
    fourSet(127);}
  }
  fourSet(0);
  }


///fourbar up and down

void fourAUp(){
fourbar(1,1300);
}

void fourADown(){
  fourbar(-1,3200);
  fourSet(20);
}

///positive is roller out

void rollOut(int timeout){
  int startTime = millis();
  while((millis()-startTime)<timeout){
    rollerSet(127);
  }
  rollerSet(127);
}

<<<<<<< HEAD
=======
void rollIn(int timeout){
  int startTime = millis();
  while((millis()-startTime)<timeout){
    rollerSet(-127);
  }
  rollerSet(0);
}

void scoreoneauto(int timeout){
	int startTime = millis();
	while((millis()-startTime)<timeout){
	lift(1,-50);
	fourbar(1,250);
	fourbar(-1,500);
}

}
>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)



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
