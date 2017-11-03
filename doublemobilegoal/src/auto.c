 #include "autofunctions.h"
 #include "main.h"
 #include "drive.h"
 #include "mgten.h"
 #include "mgtwenty.h"



void autonomous() {
  //back drive is 1
  //drive forwards is -1
  // 1 is clockwise
  //-1 is counterclockwise

//twenty all in out 1545
//twenty in 10
//ten out -490
//ten in-232

//mg20out -1
//mg20 in 1
  switch(myauto){
case 1:
autoDrive(-1, 200);
mobileGoalTen(1,-480);
autoDrive(-1, 500);
delay(400);
mobileGoalTen(-1, -235);
delay(400);
mobileGoalTwenty(-1,1545);
delay(400);
gyroTurn(-1,60);
delay(400);
gyroTurn(1,8);
delay(400);
autoDrive(1,300);
delay(400);
mobileGoalTwenty(1, 10);
delay(400);
autoDrive(1,600);
mobileGoalTwenty(1, 10);
delay(100);
//finished 20 point
autoDrive(1,500);
delay(500);
mobileGoalTwenty(-1, 1545);
delay(500);
autoDrive(-1,100);
delay(500);
gyroTurn(-1, 45);
delay(500);
autoDrive(1,550);
delay(300);
mobileGoalTwenty(1, 10);
delay(500);
gyroTurn(1, 155);
delay(500);
autoDrive(1,500);
mobileGoalTwenty(-1, 1545);
autoDrive(1,100);///////////////new
autoDrive(1,200);
mobileGoalTwenty(1, 10);
gyroTurn(1, 45);
autoDrive(1,1700);
stop();
break;

case 2:
autoDrive(-1, 200);
mobileGoalTen(1,-480);
autoDrive(-1, 500);
delay(400);
mobileGoalTen(-1, -235);
delay(400);
mobileGoalTwenty(-1,1545);
delay(400);
gyroTurnPID(-1,60,1500,1);
delay(400);
gyroTurnPID(1,8,1500,1);
delay(400);
autoDrive(1,300);
delay(400);
mobileGoalTwenty(1, 10);
delay(400);
autoDrive(1,600);
mobileGoalTwenty(1, 10);
delay(100);
stop();
break;

case 3:
//target always positive!!!
gyroTurnPID(1,30, 3000, 1);
delay(400);
autoDrive(1,100);
delay(400);
gyroTurnPID(1,30,3000, 2);
delay(400);
autoDrive(1,100);
delay(400);
gyroTurnPID(1,30,3000, 0.1);
delay(400);
autoDrive(1,100);
delay(400);
gyroTurnPID(1,30, 3000, 4);
stop();
break;
}
}
