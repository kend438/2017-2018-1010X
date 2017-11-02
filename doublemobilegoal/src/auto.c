 #include "autofunctions.h"
 #include "main.h"
 #include "drive.h"
 #include "mgten.h"
 #include "mgtwenty.h"



void autonomous() {
  #define back 1;
  #define forward -1;
  switch(myauto){
case 1:
autoDrive(-1, 200);
gyroTurn(1,100);
stop();
break;

case 2:
mobileGoalTen(1,100);
stop();
break;
}
}
