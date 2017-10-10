
#include "main.h"
#include "claw.h"
#include "lift.h"
#include "ports.h"
#include "drive.h"

void operatorControl() {

	float pidError;
	float liftError;
	int liftCurrent;
	int pidArm;
	int pidLift;
	bool armRaise;
	bool armLower;
	bool armDown;
	bool sevenCone;
	bool preset;
	int SensorTargetValue;
	int SensorTargetLift;
	int current;
<<<<<<< HEAD
	bool liftUp;
	bool liftDown;

	float pid_Kp = 1.5;//was 0.5
	float pid_Kp_Lift = 1;

 SensorTargetValue = encoderGet(encoder);
 SensorTargetLift = encoderGet(encoderLift);
=======
<<<<<<< HEAD
<<<<<<< HEAD
	float pid_Kp = 0.5;
	/*int LiftUp;
	int LiftDown;
	int SensorTargetValue2;
*/
=======
	float pid_Kp = 1.5;//was 0.5
>>>>>>> fa57ca5fbcda22237cd8aead6fe641a2148af71e
=======
	float pid_Kp = 1.5;//was 0.5
>>>>>>> fa57ca5fbcda22237cd8aead6fe641a2148af71e

 SensorTargetValue = encoderGet(encoder);
 SensorTargetValue = encoderGet(encoderLift);
>>>>>>> 9f8e44f11a1bfd804fc125f0ccfe162a8a1ddf3c

	while (1) {

		armRaise = joystickGetDigital(2,5,JOY_UP);
		armLower = joystickGetDigital(2,5,JOY_DOWN);
		armDown = joystickGetDigital(2,7,JOY_DOWN);
		sevenCone = joystickGetDigital(2,7,JOY_UP);
		preset = joystickGetDigital(2,7,JOY_LEFT);
		liftUp = joystickGetDigital(1,6,JOY_UP);
		liftDown = (joystickGetDigital(1,6,JOY_DOWN));

		///********CLAW*********//
		clawSet(joystickGetAnalog(2,2));

		///***MOBILEGOAL***//
		if(liftUp == 1 && liftDown ==0)
		{
			liftSet(-127);
			SensorTargetLift = encoderGet(encoderLift);
		}
		else if(liftDown == 1 && liftUp == 0)
		{
			/*int currentLift = encoderGet(encoderLift);
			if(currentLift > 900)
			{
			liftSet(0);
		  }
			else if(currentLift < 900)
			{
				*/
			liftSet(127);
			//}
			SensorTargetLift = encoderGet(encoderLift);
		}

		if(liftUp==0 && liftDown == 0)
		{
				int currentLift = encoderGet(encoderLift);
						if(currentLift != SensorTargetLift)
						{
							//find encoder value now
						liftError =  SensorTargetLift - currentLift;
						  // calculate arm
					  int pidLift = (pid_Kp_Lift * liftError);

								  // limit arm
							 if( pidLift > 127 )
						 		 	 pidLift = 127;
							 if( pidLift < (-127) )
							 		 pidLift = (-127);
			 		 }
			liftSet(pidLift);
		}


		///*****ENCODERSLCD*****//
		/*int counts = encoderGet(encoder);
		lcdPrint(uart1, 1, "encoder%d", counts);
		lcdPrint(uart1, 2, "Target%d", SensorTargetValue);
<<<<<<< HEAD
*/
		int countsLift = encoderGet(encoderLift);
		lcdPrint(uart1, 1, "encoderLift%d", countsLift);
=======
<<<<<<< HEAD

		int countsLift = encoderGet(encoderLift);
		lcdPrint(uart1, 2, "encoderLift%d", countsLift);
		delay(20);
=======
>>>>>>> fa57ca5fbcda22237cd8aead6fe641a2148af71e
>>>>>>> 9f8e44f11a1bfd804fc125f0ccfe162a8a1ddf3c

		lcdPrint(uart1, 2, "targetLift%d", SensorTargetLift);

		//*****DRIVE*****//
		int power, turn;
		power = joystickGetAnalog(1,1);
		turn = joystickGetAnalog(1,3);
		driveSet(power - turn, power + turn);

		//********CHAINBARPID******//
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
							 if( pidArm > 127)
						 		 	 pidArm = 127;
							 if( pidArm < (-127))
							 		 pidArm = (-127);
			 		 }
				 motorSet(ArmT, pidArm);
				 motorSet(ArmLB, pidArm);
				 motorSet(ArmRB, pidArm);
		}

//arm goinng up
				else if(armRaise!=0 && armLower==0)
				{
					motorSet(ArmT, -127);
					motorSet(ArmLB, -127);
					motorSet(ArmRB, -127);
					//set the target value for PiD
					SensorTargetValue = encoderGet(encoder);
				}
//arm going down
				else if(armRaise==0 && armLower!=0)
				{
				 motorSet(ArmT, 127);
 				 motorSet(ArmLB, 127);
 				 motorSet(ArmRB, 127);
					SensorTargetValue = encoderGet(encoder);
				}
//other condition
				else
				{
					motorSet(ArmT, 0);
					motorSet(ArmLB, 0);
					motorSet(ArmRB, 0);
				}

 if(armDown == 1)
 {
	 SensorTargetValue = 470;
<<<<<<< HEAD
 }

 if(sevenCone == 1)
 {
	 SensorTargetValue = 245;
 }

 if(preset == 1)
 {
 	SensorTargetValue = 355;
 }
delay(20);
}

}
=======
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
<<<<<<< HEAD
<<<<<<< HEAD



		clawSet(joystickGetAnalog(2,2));
=======
>>>>>>> fa57ca5fbcda22237cd8aead6fe641a2148af71e

		delay(20);
	}
<<<<<<< HEAD



	/*if(SensorTargetValue2);

	encoder2 = 200
*/

}
=======
>>>>>>> fa57ca5fbcda22237cd8aead6fe641a2148af71e
=======

		delay(20);
	}
>>>>>>> fa57ca5fbcda22237cd8aead6fe641a2148af71e
>>>>>>> 9f8e44f11a1bfd804fc125f0ccfe162a8a1ddf3c
