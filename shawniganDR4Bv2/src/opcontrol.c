#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"

void operatorControl() {

	float kp = 0.8;
	int tenError;
	int tenCurrent;
	int tenPower;
	int tenTarget;
	int twentyError;
	int twentyCurrent;
	int twentyPower;
	int twentyTarget;
	bool mgLiftUp;
	bool mgLiftDown;
	bool liftUp;
	bool liftDown;
	bool fourUp;
	bool fourDown;
	int power, turn;
	bool rollUp;
	bool rollDown;
	float twentykp = 0.05;

	encoderReset(encoderTen);
	tenTarget = encoderGet(encoderTen);
	twentyTarget = analogRead(1);

	while (1) {
		//lcd
		int L = encoderGet(encoderTen);
		int R = analogRead(1);
		lcdPrint(uart1, 1, "dr4b%d", L);
		lcdPrint(uart1, 2, "fourbar%d", R);

	//%%%%%%%% JOYSTICK DEFINITIONS %%%%%%%%%//
	mgLiftUp = joystickGetDigital(1,6, JOY_UP);
	mgLiftDown = joystickGetDigital(1,6, JOY_DOWN);
	liftUp = joystickGetDigital(1,5, JOY_UP);
	liftDown = joystickGetDigital(1,5, JOY_DOWN); //out
	fourUp = joystickGetDigital(2,5, JOY_UP);
	fourDown = joystickGetDigital(2,5, JOY_DOWN);
	power = joystickGetAnalog(1,1);
	turn = joystickGetAnalog(1,3);
	rollUp = joystickGetDigital(2,6,JOY_UP);
	rollDown = joystickGetDigital(2,6,JOY_DOWN);

	//^^^^^^^^ MOBILE GOAL TEN ^^^^^^^^^^^//
	if(mgLiftUp == 1 && mgLiftDown == 0){
		mgSet(127);
		//tenTarget = encoderGet(encoderTen);
	}
	else if(mgLiftUp == 0 && mgLiftDown == 1){
		mgSet(-127);
		//tenTarget = encoderGet(encoderTen);
	}
	else if(mgLiftUp == 0 && mgLiftDown == 0){
		/*
		tenCurrent = encoderGet(encoderTen);
		tenError = //tenTarget - tenCurrent;
		tenPower = tenError*kp;
		mgSet(tenPower);
		*/
		mgSet(0);
	}



	//$$$$$$$$$ fourbar $$$$$$$$$//
	if((fourUp == 1 && fourDown == 0)){
		fourSet(-127);
		twentyTarget = analogRead(1);
	}
	else if((fourUp == 0 && fourDown == 1)){
		fourSet(127);
		twentyTarget = analogRead(1);
	}
	else if((fourUp == 0 && fourDown == 0)){
		twentyCurrent = analogRead(1);
		twentyError = twentyTarget - twentyCurrent;
		twentyPower = twentyError*kp;
		fourSet(0);
	}




	//******** DRIVE ********//
	driveSet(power - turn, power + turn);





	////////////dr4b
	if((liftUp == 1 && liftDown == 0)){
		liftSet(-127);
	tenTarget = encoderGet(encoderTen);
	}
	else if((liftUp == 0 && liftDown == 1)){
		liftSet(127);
	tenTarget = encoderGet(encoderTen);
	}
	else if((liftUp == 0 && liftDown == 0)){
		tenCurrent = encoderGet(encoderTen);
		tenError = tenTarget - tenCurrent;
		tenPower = tenError*kp;
		liftSet(tenPower);

	}


////////rollers
if((rollUp == 1 && rollDown == 0)){
	rollerSet(-127);
//	twentyCurrent = analogRead(1);
}
else if((rollUp == 0 && rollDown == 1)){
	rollerSet(127);
//	twentyCurrent = analogRead(1);
}
else if((rollUp == 0 && rollDown == 0)){
	rollerSet(-20);

}
	delay(20);
	}
}
