
#include "main.h"
#include "claw.h"
#include "lift.h"
#include "ports.h"
#include "drive.h"

void operatorControl() {

	float pidError;
	int countsLift;
	int liftCurrent;
	int pidArm;
	bool armRaise;
	bool armLower;
	bool armDown;
	bool sevenCone;
	bool preset;
	int SensorTargetValue;
	int current;
	bool liftUp;
	bool liftDown;
	bool liftScore;

	float pid_Kp = 1.5;//was 0.5

 SensorTargetValue = encoderGet(encoder);

	while (1) {

		armRaise = joystickGetDigital(2,5,JOY_UP);
		armLower = joystickGetDigital(2,5,JOY_DOWN);
		armDown = joystickGetDigital(2,7,JOY_DOWN);
		sevenCone = joystickGetDigital(2,7,JOY_UP);
		preset = joystickGetDigital(2,7,JOY_LEFT);
		liftUp = joystickGetDigital(1,6,JOY_UP);
		liftDown = joystickGetDigital(1,6,JOY_DOWN);
		liftScore = joystickGetDigital(1,7,JOY_DOWN);

		///********CLAW*********//
		clawSet(joystickGetAnalog(2,2));

		///***MOBILEGOAL***//
		if(liftUp == 1 && liftDown ==0 && liftScore == 0){liftSet(-127);}

		else if(liftDown == 1 && liftUp == 0 && liftScore == 0){liftSet(127);}

		else if(liftDown == 0 && liftUp == 0 && liftScore == 1)
		{
			liftCurrent = encoderGet(encoderLift);
			if(liftCurrent > 470){liftSet(0);}

			if(liftCurrent < 470){liftSet(127);}
		}

		else{liftSet(0);}

		///*****ENCODERSLCD*****//
		countsLift = encoderGet(encoderLift);
		lcdPrint(uart1, 2, "targetLift%d", countsLift);

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

 if(armDown == 1){SensorTargetValue = 470;}

 if(sevenCone == 1){SensorTargetValue = 245;}

 if(preset == 1){SensorTargetValue = 355;}

	delay(20);
}
}
