#include "main.h"
#include "ports.h"
//turning is good, forward/backwards is wrong
void driveSet(int left, int right){
  motorSet(DriveFL, left);
  motorSet(DriveBL, left);
  motorSet(DriveBR, right);
  motorSet(DriveFR, right);
}
