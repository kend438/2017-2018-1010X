#include "main.h"
#include "ports.h"
#include "autofunctions.h"

void initializeIO() {
}


void initialize() {
  lcdInit(uart1);
  lcdClear(uart1);
  lcdSetBacklight(uart1, 1);
encoder = encoderInit(1, 2, 0);
encoder_L = encoderInit(5, 6, 0);
encoder_R = encoderInit(7, 8, 0);
<<<<<<< HEAD
encoderLift = encoderInit(3, 4, 1);

=======
<<<<<<< HEAD
<<<<<<< HEAD
encoderLift = encoderInit(3, 4, 1);

=======
gyro = gyroInit(1,196);
>>>>>>> fa57ca5fbcda22237cd8aead6fe641a2148af71e
=======
>>>>>>> 9f8e44f11a1bfd804fc125f0ccfe162a8a1ddf3c
gyro = gyroInit(1,196);
>>>>>>> fa57ca5fbcda22237cd8aead6fe641a2148af71e
  lcdClear(uart1);
    lcdSetText(uart1, 1, "Ready");
}