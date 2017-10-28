#include "main.h"
#include "drive.h"

void driveSet(int leftPower, int rightPower)
{
  motorSet(DriveFL, leftPower*DriveFL_Dir);
  motorSet(DriveML, leftPower*DriveML_Dir);
  motorSet(DriveBL, leftPower*DriveBL_Dir);
  motorSet(DriveFR, rightPower*DriveFR_Dir);
  motorSet(DriveMR, rightPower*DriveMR_Dir);
  motorSet(DriveBR, rightPower*DriveBR_Dir);

}
