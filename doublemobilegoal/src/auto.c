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
case 1://pid skills
autoDrive(-1, 230);
delay(100);
mobileGoalTen(1,-400);
delay(100);
autoDrive(-1, 530);
delay(400);
mobileGoalTen(-1, -235);
delay(400);
autoDrive(1, 230);
delay(400);
//picked up ten
gyroTurnPID(-1,187,1500,4,5);
delay(400);
mobileGoalTwenty(-1,1545);
delay(400);
autoDrive(1,610);
delay(400);
mobileGoalTwenty(1, 10);
delay(400);
//picked up 20
autoDrive(1,800);
delay(100);
gyroTurnPID(-1,90,1500,4,5);
delay(100);
//first turn
autoDrive(1,337);
delay(100);
gyroTurnPID(1,90,1500,4,5);
delay(100);
//second turn
autoDrive(1,430);
delay(100);

mobileGoalTwenty(-1, 1545);
delay(100);
autoDrive(-1,80);
delay(400);
mobileGoalTwenty(1, 1000);
delay(100);
//scored 20
autoDrive(-1,220);
delay(100);
gyroTurnPID(-1,93,1500,4,5);
delay(100);
autoDrive(1,125);
gyroTurnPID(-1,90,1500,4,5);
delay(100);
autoDrive(-1,135);

mobileGoalTen(1,-420);
delay(100);
autoDrive(-1,100);
delay(100);
autoDrive(1,100);
delay(400);
mobileGoalTen(-1,-235);
//finished side one

mobileGoalTwenty(-1,1545);
delay(400);
autoDrive(1,450);
delay(400);
mobileGoalTwenty(1, 10);
delay(400);
//finish 20 #2

gyroTurnPID(-1,188,1500,4,5);
delay(400);
mobileGoalTen(1,-390);
autoDrive(-1, 1500);
delay(400);
mobileGoalTen(-1, -225);
delay(400);
//finished 10#2

autoDrive(-1,300);
delay(100);
gyroTurnPID(-1,87,1500,4,5);
delay(100);
autoDrive(-1,330);
delay(100);

gyroTurnPID(-1,87,1500,4,5);
delay(100);
autoDrive(1,400);
delay(100);
mobileGoalTwenty(-1, 1545);
delay(100);
autoDrive(-1,100);
delay(100);
mobileGoalTwenty(1, 10);
delay(100);

autoDrive(-1,300);
delay(100);
gyroTurnPID(-1,187,1500,4,5);
autoDrive(-1,200);
mobileGoalTen(1,-420);
delay(100);
autoDrive(-1,100);
delay(100);
autoDrive(1,200);
delay(400);
mobileGoalTen(-1,-235);


stop();
break;

case 2:
mobileGoalTwenty(-1,1545);
delay(100);
autoDrive(1,450);
delay(100);
mobileGoalTwenty(1, 10);
delay(100);
//got 20

gyroTurnPID(-1,184,1500,4,5);
delay(100);
///turn around

autoDrive(1,450);
delay(100);
mobileGoalTwenty(-1,1545);
delay(100);
autoDrive(-1,100);
delay(100);
mobileGoalTwenty(1, 10);


stop();
break;
case 3:
//target always positive!!!
gyroTurnPID(1,60, 3000, 4, 5);
delay(400);
gyroTurnPID(1,60, 3000, 4,6);
delay(400);
gyroTurnPID(1,60,3000,4,7);
delay(400);
gyroTurnPID(1,90, 3000, 4, 5);
delay(400);
gyroTurnPID(1,90, 3000, 4,6);
delay(400);
gyroTurnPID(1,90,3000,4,7);
stop();
break;
}
}
