#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

void autoDrive(int direction, int target);

void gyroTurn(int direction, int targetTurn);

void gyroTurnPID(int direction, int targetTurn, int timeout, float kp, float kd);

void mobileGoalTen(int direction, int target);

void mobileGoalTwenty(int direction, int target);

void lift(int direction, int target);

void fourbar(int direction, int target);

void scoreoneauto(int timeout);

void fourAUp();

void fourADown();

<<<<<<< HEAD
void stackTask(void*ignore);

TaskHandle stackAutoTask;
=======
void rollOut(int timeout);

void rollIn(int timeout);
>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)

void stop();
#endif
