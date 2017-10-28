#include "main.h"

void initializeIO() {
}

void initialize() {

  lcdInit(uart1);
  lcdClear(uart1);
  lcdSetBacklight(uart1, 1);

encoderTen = encoderInit(1, 2, 0);
}
