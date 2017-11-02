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
mobileGoalTwenty(-1,1445);
autoDrive(1, 1100);
delay(400);
mobileGoalTwenty(1, 10);
delay(200);
autoDrive(1,100);
gyroTurn(1,10);
autoDrive(1,750);
gyroTurn(1,10);
autoDrive(1,550);
gyroTurn(-1,10);
autoDrive(1,550);///////////////new
/////mobile goal scoring
mobileGoalTwenty(-1, 1545);
autoDrive(1,40);///////////////new
autoDrive(1,100);
mobileGoalTwenty(1, 10);
delay(100);
//finished 20 point
autoDrive(1,250);
delay(500);
gyroTurn(-1, 50);
delay(500);
mobileGoalTwenty(-1, 1545);
delay(500);
autoDrive(1,100);
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
mobileGoalTwenty(-1,1545);
mobileGoalTen(1,-200);
stop();
break;

case 3:
gyroTurnPID(1,150, 2000);
autoDrive(1,700);
stop();
break;
}
}
