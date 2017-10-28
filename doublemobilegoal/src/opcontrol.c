#include "main.h"
#include "drive.h"
#include "mgten.h"
#include "mgtwenty.h"

void operatorControl() {

	float kp = 0.1;
	int tenError;
	int tenCurrent;
	int tenPower;
	int tenTarget;
	int twentyError;
	int twentyCurrent;
	int twentyPower;
	int twentyTarget;
	encoderReset(encoderTen);


	while (1) {

	//%%%%%%%% JOYSTICK DEFINITIONS %%%%%%%%%//
	int leftDrive = joystickGetAnalog(1,1);
	int rightDrive = joystickGetAnalog(1,3);
	bool tenLiftUp = joystickGetDigital(1,6, JOY_UP);
	bool tenLiftDown = joystickGetDigital(1,6, JOY_DOWN);
	bool twentyLiftUp = joystickGetDigital(1,5, JOY_UP);
	bool twentyLiftDown = joystickGetDigital(1,5, JOY_DOWN);

	//^^^^^^^^ MOBILE GOAL TEN ^^^^^^^^^^^//
	while(tenLiftUp == 1 && tenLiftDown == 0){
		mgtenSet(127);
	}
	while(tenLiftUp == 0 && tenLiftDown == 1){
		mgtenSet(-127);
	}
	while(tenLiftUp == 0 && tenLiftDown == 0){
		tenCurrent = encoderGet(encoderTen);
		tenError = tenTarget - tenCurrent;
		tenPower = tenError*kp;
		mgtenSet(tenPower);
	}
	//$$$$$$$$$ MOBILE GOAL TWENTY $$$$$$$$$//
	while(twentyLiftUp == 1 && twentyLiftDown == 0){
		mgtwentySet(127);
		twentyCurrent = analogRead(1);
	}
	while(twentyLiftUp == 0 && twentyLiftDown == 1){
		mgtwentySet(-127);
		twentyCurrent = analogRead(1);
	}
	while(twentyLiftUp == 0 && twentyLiftDown == 0){
		twentyCurrent = analogRead(1);
		twentyError = twentyTarget - twentyCurrent;
		twentyPower = twentyError*kp;
		mgtwentySet(twentyPower);
	}
	//******** DRIVE ********//
	driveSet(leftDrive-rightDrive, leftDrive+rightDrive);

		delay(20);
	}
}
