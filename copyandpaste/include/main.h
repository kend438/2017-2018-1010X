#ifndef MAIN_H_
#define MAIN_H_
#include <API.h>
#ifdef __cplusplus
extern "C" {
#endif
void autonomous();
void initializeIO();
Encoder encoder;
Encoder encoder_L;
Encoder encoder_R;
Encoder encoderLift;

Gyro gyro;

int myauto;
void initialize();{
lcdPrint(uart1, 1, "%d", myauto);
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

void operatorControl();
#ifdef __cplusplus
}
#endif

#endif
