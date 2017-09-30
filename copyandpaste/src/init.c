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

  lcdClear(uart1);
    lcdSetText(uart1, 1, "Ready");
}
