#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    potarmL,        sensorNone)
#pragma config(Sensor, in2,    potarmR,        sensorPotentiometer)
#pragma config(Sensor, in3,    gyro,           sensorNone)
#pragma config(Sensor, in8,    PEbatt,         sensorAnalog)
#pragma config(Sensor, dgtl1,  sArmLT,         sensorTouch)
#pragma config(Sensor, dgtl2,  sArmLB,         sensorTouch)
#pragma config(Sensor, dgtl3,  sArmRT,         sensorTouch)
#pragma config(Sensor, dgtl4,  sArmRB,         sensorTouch)
#pragma config(Sensor, dgtl5,  encoderL,       sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  encoderR,       sensorQuadEncoder)
#pragma config(Motor,  port1,           DriveBL,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           DriveFL,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           RollL,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           ArmLT,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           ArmLB,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           ArmRB,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           ArmRT,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RollR,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           DriveFR,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          DriveBR,       tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{

  bStopTasksBetweenModes = true;

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
///////////////////////////////////////////////////////////////////////////////
void autodrivestraight (float kp, int distics){

	int totaltics = 0;
	int error = 0;
	int Rpower = 100;
	int Lpower = 100;

	SensorValue[encoderL] = 0;
	SensorValue[encoderR] = 0;

	while (distics <= totaltics){
		motor[DriveBL] = motor[DriveFL] = Lpower;
		motor[DriveBR] = motor[DriveFR] = Rpower;

		error = SensorValue[encoderL] - SensorValue[encoderR];

		Lpower += -error * kp;//neg error for decrease when left side is too far

		Lpower = floor(Lpower);

		totaltics += (SensorValue[encoderL] + SensorValue[encoderR])/2;

		SensorValue[encoderL] = 0;
		SensorValue[encoderR] = 0;

		wait1Msec(100);


task autonomous()
{

autodrivestraight(1, 360);

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Remove this function call once you have "real" code.
    UserControlCodePlaceholderForTesting();
  }
}