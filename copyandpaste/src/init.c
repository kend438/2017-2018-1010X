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
encoderLift = encoderInit(3, 4, 1);

myauto = 1;

gyro = gyroInit(1,196);
  lcdClear(uart1);
  lcdSetText(uart1, 1, "Ready");
delay(20);
  lcdClear(uart1);
  delay(20);
while(1){
  lcdClear(uart1);
lcdSetText(uart1, 2, "check");
delay(20);
lcdClear(uart1);
delay(20);
lcdPrint(uart1, 1, "myauto%d", myauto);
if(lcdReadButtons(uart1) == 1){ // changes auto
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(100); // btntime
        myauto = myauto-1;}
if(lcdReadButtons(uart1) == 4){ // changes auto
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(100);
        myauto = myauto+1;}
      }
      delay(20);
      lcdSetText(uart1, 1, "extraReady");
      delay(20);
    }
