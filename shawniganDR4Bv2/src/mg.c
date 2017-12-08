#include "main.h"
#include "mg.h"

void mgSet(int power){
  motorSet(mg,power);
}

void mgTask (void*ignore){
  bool mgLiftUp;
  bool mgLiftDown;
  bool scoremg;
  bool safemg;
  int pos = analogRead(3);
  while(true){
    if(!isEnabled()){break;} // when disabled, arm task ends - allows for new tassk ot be started when enabled

///controller

scoremg = joystickGetDigital(1,8,JOY_DOWN);
safemg = joystickGetDigital(1,8,JOY_UP);
mgLiftUp = joystickGetDigital(1,6, JOY_UP);
mgLiftDown = joystickGetDigital(1,6, JOY_DOWN);



    //^^^^^^^^ MOBILE GOAL TEN ^^^^^^^^^^^//
if(mgLiftUp == 1 && mgLiftDown == 0){mgSet(127);}
else if(mgLiftUp == 0 && mgLiftDown == 1){mgSet(-127);}
else if(mgLiftUp == 0 && mgLiftDown == 0){mgSet(0);}

	if(safemg == 1){
		if(analogRead(3)<1000){mgSet(127);}
	else{mgSet(0);}
  	}

  if(scoremg == 1){
  	if(analogRead(3)>1000){mgSet(-90);}
  else{mgSet(0);}
  	}

if(isAutonomous()){motorset_arm( PID_cal(&pidarm_auto, arm_target_global, arm_pos_global) );} // arm pid calculate for auto
else{motorset_arm( PID_cal(&pidarm_op, arm_target_global, arm_pos_global) );} // else, arm pid calculate for op_control

    delay(20);

    }

  mgSet(0);
  taskDelete(mgTask); // when loop break (i.e robot not enabled)
  }
    //////////////////////////////////////////////
    // arm task works by changing target value by buttons, then updating a pid loop to the new target
    // min and max values limit error and target values
    // loop is broken and task ended when robot is disabled
    //////////////////////////////////////////////

  //arm pid loops terms init
  PID_init(&pidarm_auto, 0.8, 0, 0, 0); // was 0.4
  PID_init(&pidarm_op, 0.8, 0, 0, 0);
  arm_target_global = encoderGet(encoder_ARM); // difference set to zero

  while(true){
    if(!isEnabled()){break;} // when disabled, arm task ends - allows for new tassk ot be started when enabled

    // unused - purpose was to predict vel of arm and reduced op_control lag
    int arm_pos_last = arm_pos_global;
    int arm_vel = abs(arm_pos_global - arm_pos_last);

    arm_pos_global = encoderGet(encoder_ARM); // arm position update

// LARGE IF TREE - gives prioity to arm control

// controller main
if(joystickGetDigital(1, 6, JOY_UP)){  arm_target_global = arm_target_global + 10;} // was 12
  else if(joystickGetDigital(1, 6, JOY_DOWN)) { arm_target_global = arm_target_global- 10;} // was 12 //CHECKK: speed free, speed load


//if(joystickGetDigital(2, 6, JOY_UP)) {  arm_target_global = arm_target_global + 13;}
//if(joystickGetDigital(2, 6, JOY_DOWN)) { arm_target_global = arm_target_global- 13;}


//limits error, and therefore power, supplied to arm
// parameter for the else if is = error - maxpower*kp
//kp is 0.8, should be changed to varible
  else if((((arm_target_global-arm_pos_global)) > (MAX_POWER_ARM/0.8))&&!isAutonomous()){ // positive over shoot
    arm_target_global = arm_pos_global + (MAX_POWER_ARM/0.8);}
  else if((((arm_target_global-arm_pos_global)) < -(MAX_POWER_ARM/0.8))&&!isAutonomous()){ // negitive over shoot
    arm_target_global = arm_pos_global - (MAX_POWER_ARM/0.8);}

//arm max down
//else if is allowing joystick holding
if((arm_target_global < -30 )&&(!joystickGetDigital(1, 7, JOY_DOWN))) {  arm_target_global  = -30; }
  else if((arm_target_global< -150)){  arm_target_global = -150;}

//arm max up
if(arm_target_global > 657)  {  arm_target_global  = 657; }



if(isAutonomous()){motorset_arm( PID_cal(&pidarm_auto, arm_target_global, arm_pos_global) );} // arm pid calculate for auto
else{motorset_arm( PID_cal(&pidarm_op, arm_target_global, arm_pos_global) );} // else, arm pid calculate for op_control

    delay(20);

    }

  motorset_arm(0);
  taskDelete(arm_task); // when loop break (i.e robot not enabled)
  }
