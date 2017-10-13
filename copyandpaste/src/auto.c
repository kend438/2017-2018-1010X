#include "main.h"
#include "autofunctions.h"
#include "lift.h"
#include "claw.h"
#include "drive.h"
#include "ports.h"

#define INSIDE 1
#define OUTSIDE -1

void autonomous() {

switch(myauto){

case 1: //rightside red
  armDown(470,OUTSIDE);
  mobileGoalOut(1200);
  autoDrive(-1, 1280);
  delay(400);
  mobileGoalIn(1100);
  delay(400);
  autoDrive(1,600);
  gyroTurn(1,140);
  autoDrive(-1,500);
  gyroTurn(-1,20);
  autoDrive(-1,20);///////////////new
  mobileGoalOut(1200);
  autoDrive(-1,20);///////////////new
  autoDrive(1,40);
  mobileGoalIn(300);
  autoDrive(1,100);
  stop();
break;

case 2: // leftside red
armDown(470,1);
mobileGoalOut(1200);
autoDrive(-1, 1280);
delay(400);
mobileGoalIn(1100);
delay(400);
autoDrive(1,600);
gyroTurn(-1,140);
autoDrive(-1,500);
gyroTurn(1,20);
autoDrive(-1,20);
mobileGoalOut(1200);
autoDrive(-1,20);///////////////new
autoDrive(1,40);
mobileGoalIn(300);
autoDrive(1,100);
stop();
break;

case 3: //right blue coney
armDown(470,1);
mobileGoalOut(1200);
autoDrive(-1, 1280);
delay(400);
autoDrive(-1, 200);
mobileGoalIn(1100);
delay(400);
autoDrive(1,800);
gyroTurn(1,140);
autoDrive(-1,500);
gyroTurn(-1,20);
autoDrive(-1,20);///////////////new
mobileGoalOut(1200);
autoDrive(-1,20);///////////////new
autoDrive(1,40);
mobileGoalIn(300);
autoDrive(1,100);
stop();
break;

case 4: //left red coney
armDown(470,1);
mobileGoalOut(1200);
autoDrive(-1, 1280);
delay(400);
autoDrive(-1, 200);
mobileGoalIn(1100);
delay(400);
autoDrive(1,800);
gyroTurn(-1,140);
autoDrive(-1,500);
gyroTurn(-1,20);
autoDrive(-1,20);///////////////new
mobileGoalOut(1200);
autoDrive(-1,20);///////////////new
autoDrive(1,40);
mobileGoalIn(300);
autoDrive(1,100);
stop();
break;

case 5: //hold mobile goal
armDown(470,1);
mobileGoalOut(1200);
autoDrive(-1, 1280);
delay(400);
autoDrive(-1, 200);
mobileGoalIn(1100);
break;

case 6://stack preload red right
armDown(90,OUTSIDE);
mobileGoalOut(1200);
autoDrive(-1, 1280);
delay(400);
mobileGoalIn(1100);
armUp(70,INSIDE);
clawOpenIt(1800);
armDown(450,OUTSIDE);
autoDrive(1,600);
gyroTurn(1,140);
autoDrive(-1,500);
gyroTurn(-1,20);
autoDrive(-1,20);///////////////new
mobileGoalOut(1200);
autoDrive(-1,20);///////////////new
autoDrive(1,40);
mobileGoalIn(300);
autoDrive(1,100);
stop();
break;

default:
myauto = 1;
break;
}
}
