#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"
#include "autofunctions.h"
<<<<<<< HEAD
#include "stack.h"
=======
//fourbar down 510, up 260
>>>>>>> parent of 682d7b6... ok look at this cool
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
<<<<<<< HEAD
	float p;
	float d;
=======
	int p;
	int d;
	bool liftADown;
>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)
	float tkp = 0.3;
	bool fourPU;
	bool fourPD;
	bool scoreOne;
	bool scoremg;
<<<<<<< HEAD
	bool safemg;
	//bool reset;
	bool cancel;
<<<<<<< HEAD
	int rollSet;
	//bool liftUpP;
	//bool liftDownP;
	int liftJoy;
	int driverStackingOn = 0;
=======
=======
>>>>>>> parent of 682d7b6... ok look at this cool

>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)
	encoderReset(encoderTen);
	tenTarget = encoderGet(encoderTen);
	twentyTarget = analogRead(1);

<<<<<<< HEAD
<<<<<<< HEAD
TaskHandle driverStackAutoTask = taskCreate(driverStackTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

=======
>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)
		//lcd
		tenTarget = encoderGet(encoderTen);
		//int L = analogRead(3);
		lcdPrint(uart1, 1, "dr%d", tenTarget);
		lcdPrint(uart1, 2, "driveStacking%d", driverStackingOn);
=======
	while (1) {
		//lcd
		int L = analogRead(3);
		int R = encoderGet(encoderTen);
		lcdPrint(uart1, 1, "tenError%d", tenError);
		lcdPrint(uart1, 2, "mg%d", L);
>>>>>>> parent of 682d7b6... ok look at this cool

	//%%%%%%%% JOYSTICK DEFINITIONS %%%%%%%%%//
	mgLiftUp = joystickGetDigital(1,6, JOY_UP);
	mgLiftDown = joystickGetDigital(1,6, JOY_DOWN);
	liftUp = joystickGetDigital(1,5, JOY_UP);
	liftDown = joystickGetDigital(1,5, JOY_DOWN); //out
<<<<<<< HEAD
	fourUp = joystickGetDigital(2,7, JOY_LEFT);
	fourDown = joystickGetDigital(2,7, JOY_RIGHT);
=======
	fourUp = joystickGetDigital(2,7, JOY_UP);
	fourDown = joystickGetDigital(2,7, JOY_DOWN);
>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)
	fourPU = joystickGetDigital(2,5, JOY_UP);
	fourPD = joystickGetDigital(2,5, JOY_DOWN);
	power = joystickGetAnalog(1,1);
	turn = joystickGetAnalog(1,3);
	rollUp = joystickGetDigital(2,6,JOY_UP);
	rollDown = joystickGetDigital(2,6,JOY_DOWN);
<<<<<<< HEAD
	scoreOne= joystickGetDigital(2,7,JOY_DOWN);
	//reset = joystickGetDigital(2,8,JOY_UP);
	scoremg = joystickGetDigital(1,8,JOY_DOWN);
	safemg = joystickGetDigital(1,8,JOY_UP);
	cancel = joystickGetDigital(2,7,JOY_RIGHT);
	liftJoy = joystickGetAnalog(1,3);

	if(scoreOne ==1){
		delay(20);
	driverStackingOn = 1;
		twentyTarget = analogRead(1);
			tenTarget = encoderGet(encoderTen);
	}

	if(cancel ==1){driverStackingOn =0;}

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
=======
	scoreOne= joystickGetDigital(2,8,JOY_UP);
	scoremg = joystickGetDigital(1,8,JOY_DOWN);
>>>>>>> parent of 682d7b6... ok look at this cool

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
<<<<<<< HEAD

if(scoremg == 1){
	if(analogRead(3)>1000){
		mgSet(-90);
	}
	else{mgSet(0);}
	}
<<<<<<< HEAD


	//******** DRIVE ********//
	driveSet(power - turn, power + turn);

=======
=======
>>>>>>> parent of 682d7b6... ok look at this cool
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
>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)



<<<<<<< HEAD
=======
	if(fourPU ==1 && fourPD ==0){
		twentyTarget = 1300;
	}
	if(fourPU ==0 && fourPD ==1){
		twentyTarget = 3200;
	}
>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)





////turning off fourbar, dr4b, and rollers when autostacking
if(driverStackingOn ==0){

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
			rollSet = -15;
		}
		if(fourPU ==0 && fourPD ==1){
			twentyTarget = 3200;
		}


	////////////dr4b
<<<<<<< HEAD
	if(liftUp == 1){
		liftSet(-127);
		rollSet=-15;
	tenTarget = encoderGet(encoderTen);
	}

	if(liftJoy>15){
=======
	if((liftUp == 1 && liftDown == 0)){
>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)
		liftSet(-127);
	tenTarget = encoderGet(encoderTen);
	}
<<<<<<< HEAD

	if(liftDown == 1){
		liftSet(127);
	tenTarget = encoderGet(encoderTen);
	}

	if(liftJoy <-15){
		liftSet(127);
	tenTarget = encoderGet(encoderTen);
	}

	else{
=======
	else if((liftUp == 0 && liftDown == 1)){
		liftSet(127);
	tenTarget = encoderGet(encoderTen);
	}
	else if((liftUp == 0 && liftDown == 0)){
>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)
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
<<<<<<< HEAD
}*/
}



=======
	}
>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)
}
