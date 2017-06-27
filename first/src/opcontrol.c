
#include "main.h"
#include "claw.h"
#include "lift.h"
#include "ports.h"
#include "arm.h"
#include "drive.h"

void operatorControl() {
	while (1) {
		int power, turn;
		power = joystickGetAnalog(1,1);
		turn = joystickGetAnalog(1,3);
		driveSet(power - turn, power + turn);
/*
		motorSet(DriveFL, -power -
		 turn);
		motorSet(DriveMBL, -power - turn);
		motorSet(DriveBL, -power - turn);
		motorSet(DriveBR, -power + turn);
		motorSet(DriveFR, -power + turn);
		motorSet(DriveMBR, -power + turn);
		*/
/*
int JoyL = joystickGetAnalog(1,3);
int JoyR = joystickGetAnalog(1,2);

motorSet(DriveFL, JoyL);
motorSet(DriveMBL, JoyL);
motorSet(DriveFR, -JoyR);
motorSet(DriveMBR, -JoyR);
*/
		if(joystickGetDigital(1,6,JOY_UP)){
			liftSet(-127);
		}
		else if(joystickGetDigital(1,6,JOY_DOWN)){
			liftSet(127);
		}
		else{
			liftSet(0);
		}

		clawSet(joystickGetAnalog(2,2));
		/*
		if(joystickGetDigital(1,5,JOY_UP)){
			clawSet(127);
		}
		else if(joystickGetDigital(1,5,JOY_DOWN)){
			clawSet(-127);
		}
		else{
			clawSet(0);
		}
		*/
		if(joystickGetDigital(1,5,JOY_UP)){
			armSet(-127);
		}
		else if(joystickGetDigital(1,5,JOY_DOWN)){
			armSet(127);
		}
		else{
			armSet(0);
		}
		delay(20);
	}
}
