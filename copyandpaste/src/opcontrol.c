
#include "main.h"
#include "claw.h"
#include "lift.h"
#include "ports.h"
#include "drive.h"

void operatorControl() {

	float pidError;
	int pidArm;
	bool armRaise;
	bool armLower;
	bool armDown;
	bool sevenCone;
	bool preset;
	int SensorTargetValue;
	int current;
	float pid_Kp = 1.5;//was 0.5

 SensorTargetValue = encoderGet(encoder);

	while (1) {

		clawSet(joystickGetAnalog(2,2));

		if(joystickGetDigital(1,6,JOY_UP)){
			liftSet(-127);
		}
		else if(joystickGetDigital(1,6,JOY_DOWN)){
			liftSet(127);
		}
		else{
			liftSet(0);
		}


		int counts = encoderGet(encoder);
		lcdPrint(uart1, 1, "encoder%d", counts);
		delay(20);
		lcdPrint(uart1, 2, "Target%d", SensorTargetValue);


		int power, turn;
		power = joystickGetAnalog(1,1);
		turn = joystickGetAnalog(1,3);
		driveSet(power - turn, power + turn);

		armRaise = joystickGetDigital(2,5,JOY_UP);
		armLower = joystickGetDigital(2,5,JOY_DOWN);
		armDown = joystickGetDigital(2,7,JOY_DOWN);
	  sevenCone = joystickGetDigital(2,7,JOY_UP);
		preset = joystickGetDigital(2,7,JOY_LEFT);
				//if no buttons are pressed, activate PID
				if(armRaise==0 && armLower == 0)
				{

									current = encoderGet(encoder);
									if(current<701)
									{
									//find encoder value now
									pidError =  SensorTargetValue - current;
								  // calculate arm
								  pidArm = (pid_Kp * pidError);

								  // limit arm
								  if( pidArm > 127 )
								 		 pidArm = 127;
								  if( pidArm < (-127) )
								 		 pidArm = (-127);
}
										 motorSet(ArmT, pidArm);
										 motorSet(ArmLB, pidArm);
										 motorSet(ArmRB, pidArm);
}

//pid goes here

//arm goinng up
				else if(armRaise!=0 && armLower==0)
				{
					motorSet(ArmT, -127);
					motorSet(ArmLB, -127);
					motorSet(ArmRB, -127);
					SensorTargetValue = encoderGet(encoder);
				}
//arm going down
				else if(armRaise==0 && armLower!=0)
				{
				 motorSet(ArmT, 127);
 				 motorSet(ArmLB, 127);
 				 motorSet(ArmRB, 127);
					SensorTargetValue = encoderGet(encoder);
					lcdPrint(uart1, 2, "Target%d", SensorTargetValue);
				}
//other condition
				else
				{
					motorSet(ArmT, 0);
					motorSet(ArmLB, 0);
					motorSet(ArmRB, 0);
				}
//466 8D

 if(armDown !=0){
	 SensorTargetValue = 470;
	 /*
	int arm = encoderGet(encoder);
	int armError =  466 - arm;
	float armDown = (pid_Kp * armError);

	// limit arm
	if( armDown > 127 )
		 armDown = 127;
	if( armDown < (-127) )
		 armDown = (-127);

	motorSet(ArmT, armDown);
	motorSet(ArmLB, armDown);
	motorSet(ArmRB, armDown);
*/}


 if(sevenCone != 0){

	 SensorTargetValue = 245;}

	 if(preset != 0){

	 	SensorTargetValue = 355;}

	 /*
	int arm = encoderGet(encoder);
	int armError =  280 - arm;
	float armDown = (pid_Kp * armError);

	// limit arm
	if( armDown > 127 )
		 armDown = 127;
	if( armDown < (-127) )
		 armDown = (-127);

	motorSet(ArmT, armDown);
	motorSet(ArmLB, armDown);
	motorSet(ArmRB, armDown);
*/}


/* used to be arm without pid
		if(joystickGetDigital(2,5,JOY_UP)){
<<<<<<< HEAD
			motorSet(arm,-127);
		}
		else if(joystickGetDigital(2,5,JOY_DOWN)){
			motorSet(arm,127);
		}
		else{
			motorSet(arm,0);
=======
			liftSet(-127);
		}
		else if(joystickGetDigital(2,5,JOY_DOWN)){
			liftSet(127);
		}
		else{
			liftSet(0);
>>>>>>> 7df428b869349c7d5171e3a44def7603c892dae8
		}
		*/

		delay(20);
	}
