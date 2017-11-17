#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"

void operatorControl() {
	/*
	float kp = 0.9;
	int tenError;
	int tenCurrent;
	int tenPower;
	int //tenTarget;*/
	bool mgLiftUp;
	bool mgLiftDown;
	bool liftUp;
	bool liftDown;
	bool fourUp;
	bool fourDown;

	encoderReset(encoderTen);
	////tenTarget = encoderGet(encoderTen);

	while (1) {
		//lcd
		int L = encoderGet(encoderTen);
		int R = encoderGet(encoderR);
		lcdPrint(uart1, 1, "ten%d", L);
		lcdPrint(uart1, 2, "encoderR%d", R);

	//%%%%%%%% JOYSTICK DEFINITIONS %%%%%%%%%//
	mgLiftUp = joystickGetDigital(2,6, JOY_UP);
	mgLiftDown = joystickGetDigital(2,6, JOY_DOWN);
	liftUp = joystickGetDigital(1,5, JOY_UP);
	liftDown = joystickGetDigital(1,5, JOY_DOWN); //out
	fourUp = joystickGetDigital(2,5, JOY_UP);
	fourDown = joystickGetDigital(2,5, JOY_DOWN);

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
	if((liftUp == 1 && liftDown == 0)){
		fourSet(127);
	//	twentyCurrent = analogRead(1);
	}
	else if((liftUp == 0 && liftDown == 1)){
		fourSet(-127);
	//	twentyCurrent = analogRead(1);
	}
	else if((liftUp == 0 && liftDown == 0)){
		fourSet(0);
	/*	twentyCurrent = analogRead(1);
		twentyError = twentyTarget - twentyCurrent;
		twentyPower = twentyError*kp;
		fourSet(twentyPower);*/
	}




	//******** DRIVE ********//
	int power, turn;
	power = joystickGetAnalog(1,1);
	turn = joystickGetAnalog(1,3);
	driveSet(power - turn, power + turn);





	////////////dr4b
	if((liftUp == 1 && liftDown == 0)){
		liftSet(127);
	//	twentyCurrent = analogRead(1);
	}
	else if((liftUp == 0 && liftDown == 1)){
		liftSet(-127);
	//	twentyCurrent = analogRead(1);
	}
	else if((liftUp == 0 && liftDown == 0)){
		liftSet(0);

	}
	delay(20);
	}
}
