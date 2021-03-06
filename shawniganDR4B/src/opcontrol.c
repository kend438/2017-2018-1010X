#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"
#include "autofunctions.h"
void operatorControl() {

	//mg all the way in 1820
	//mg all the way out 235
	//mg score 1400
	//mg pick up safe 800
//fourbar down 3200, up 1200
//double reverse all the way up -470, all the way down is 0
//double reverse up is negative, down is positive
	float kp = 5; //
	float kd = 0;//6.8
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
	bool safemg;
	bool reset;
	bool cancel;

	encoderReset(encoderTen);
	tenTarget = encoderGet(encoderTen);
	twentyTarget = analogRead(1);
int armtar = 0;
	while (1) {

		//lcd
		tenTarget = encoderGet(encoderTen);
		//int L = analogRead(3);
		lcdPrint(uart1, 1, "dr%d", tenTarget);
		lcdPrint(uart1, 2, "armtar%d", armtar);

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
	reset = joystickGetDigital(2,8,JOY_UP);
	scoremg = joystickGetDigital(1,8,JOY_DOWN);
	safemg = joystickGetDigital(1,8,JOY_UP);
	cancel = joystickGetDigital(2,7,JOY_RIGHT);

/*
//// auto stack testing
if(reset == 1){
	if(cancel == 1){break;}
	int armpos = encoderGet(encoderTen);
	lift(1,(armpos-50));
	fourAUp();
	lift(-1,(armpos+30));
	rollerSet(127);
	delay(350);
	lift(1, (armpos-50));
  twentyTarget = 3200;
	delay(60);
	fourADown();
	delay(10);
	lift(-1,20);

}
*/
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

	if(safemg == 1){
		if(analogRead(3)<1000){
			mgSet(127);
		}
		else{mgSet(0);}
	}

if(scoremg == 1){
	if(analogRead(3)>1000){
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
