#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"
#include "autofunctions.h"


void autonomous() {
 //back drive is 1
 //drive forwards is -1
 // 1 is clockwise
 //-1 is counterclockwise

//twenty all in out 4095
//twenty in 10
//ten out -490
//ten in-232

//mg20out -1
//mg20 in 1
 switch(myauto){
   case 1: //right blue coney preload stack
//fourbar(1,250);
  // fourbar(-1,500);
   lift(1,-130);
   mobileGoalTwenty(-1,4095);//out
   autoDrive(-1, 1280);
   delay(400);
   mobileGoalTwenty(1, 2200);
   delay(400);
   autoDrive(1,1000);
   gyroTurn(1,45);
   autoDrive(1,210);//was300
   gyroTurn(1,73);//78
   autoDrive(-1,100);
   mobileGoalTwenty(-1,4095);
   lift(-1,0);
   delay(100);
   rollerSet(90);
   delay(200);
   lift(1,-130);
   delay(200);
   autoDrive(-1,30);///////////////new
   autoDrive(1,220);
   mobileGoalTwenty(1, 2200);
   autoDrive(1,20);
   stop();
   break;

   case 2: //left blue coney preload stack
//fourbar(1,250);
  // fourbar(-1,500);
   lift(1,-130);
   mobileGoalTwenty(-1,4095);//out
   autoDrive(-1, 1280);
   delay(400);
   mobileGoalTwenty(1, 2200);
   delay(400);
   autoDrive(1,1000);
   gyroTurn(-1,45);
   autoDrive(1,210);//was300
   gyroTurn(-1,73);//78
   autoDrive(-1,100);
   mobileGoalTwenty(-1,4095);
   lift(-1,0);
   delay(100);
   rollerSet(90);
   delay(200);
   lift(1,-130);
   delay(200);
   autoDrive(-1,30);///////////////new
   autoDrive(1,220);
   mobileGoalTwenty(1, 2200);
   autoDrive(1,20);
   stop();
   break;
}
}
