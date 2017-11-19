#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"
#include "autofunctions.h"
//fourbar down 510, up 260
void operatorControl() {

	float kp = 0.85; //
	float kd = 7;//6.8
	int tenError;
	int tenCurrent;
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
	int pid;
	int errorlast;
	int errordiff;
	int p;
	int d;
	bool liftADown;
	float tkp = 0.3;
	bool fourPU;
	bool fourPD;
	bool scoreOne;
	bool scoremg;

	encoderReset(encoderTen);
	tenTarget = encoderGet(encoderTen);
	twentyTarget = analogRead(1);

	while (1) {
		//lcd
		int L = analogRead(3);
		int R = encoderGet(encoderTen);
		lcdPrint(uart1, 1, "tenError%d", tenError);
		lcdPrint(uart1, 2, "mg%d", L);

	//%%%%%%%% JOYSTICK DEFINITIONS %%%%%%%%%//
	mgLiftUp = joystickGetDigital(1,6, JOY_UP);
	mgLiftDown = joystickGetDigital(1,6, JOY_DOWN);
	liftUp = joystickGetDigital(1,5, JOY_UP);
	liftDown = joystickGetDigital(1,5, JOY_DOWN); //out
	fourUp = joystickGetDigital(2,7, JOY_UP);
	fourDown = joystickGetDigital(2,7, JOY_DOWN);
	fourPU = joystickGetDigital(2,5, JOY_UP);
	fourPD = joystickGetDigital(2,5, JOY_DOWN);
	power = joystickGetAnalog(1,1);
	turn = joystickGetAnalog(1,3);
	rollUp = joystickGetDigital(2,6,JOY_UP);
	rollDown = joystickGetDigital(2,6,JOY_DOWN);
	scoreOne= joystickGetDigital(2,8,JOY_UP);
	scoremg = joystickGetDigital(1,8,JOY_DOWN);

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

	if(scoremg == 1){
		if(analogRead(3)<2650){
			mgSet(-90);
		}
		else{mgSet(0);}
	}
/*
if(scoreOne ==1){
scoreoneauto(5000);
}
*/
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
		twentyPower = twentyError*tkp;
		fourSet(twentyPower);
	}


	/////presets fourbar

	if(fourPU ==1 && fourPD ==0){
		twentyTarget = 1300;
	}
	if(fourPU ==0 && fourPD ==1){
		twentyTarget = 3200;
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
		p = tenError*kp;
errordiff = tenError - errorlast;
errorlast = tenError;
d = kd * errordiff;
pid = p +d;
		liftSet(pid);

	}
/*
////present double reverse down
if((liftADown == 1)){
	tenTarget = 0;
}
*/

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
	rollerSet(-14);

}
	delay(20);
	}
}
