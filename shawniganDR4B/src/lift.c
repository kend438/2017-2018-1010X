#include "main.h"
#include "lift.h"

void liftSet(int power){
  motorSet(liftT,power);
  motorSet(liftB, power);
}
