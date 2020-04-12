// uLCD-144-G2 basic text demo program for uLCD-4GL LCD driver library

//

#include "mbed.h"

#include "uLCD_4DGL.h"

Serial pc( USBTX, USBRX );
uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
PwmOut PWM1(D6);
// PwmOut PWM_out(D7);
// DigitalOut PWM_out(D7);
// AnalogIn Ain(A0);

int i=0;
int main(){
    
    uLCD.background_color(0xFFFFFF);
    uLCD.cls();

    uLCD.color(BLUE);
    uLCD.printf("\n106011206\n"); //Default Green on black text


    uLCD.text_width(4); //4X size text

    uLCD.text_height(4);
    uLCD.locate(50,80);
    uLCD.line(5, 5, 8, 5, 0xFF56FF);
    uLCD.line(5, 5, 5, 8, 0xFF56FF);
    uLCD.line(5, 8, 8, 8, 0xFF56FF);
    uLCD.line(8, 5, 8, 8, 0xFF56FF);
    
    /***********************************/
    //part2


    PWM1.period(0.001);
    PWM1=0.5;
    for(i=0;i<5;i++){
        PWM1 = PWM1 + 0.1;
        wait(0.1);
    }

    while(1){
        // PWM_out = Ain;
        for(i=0;i<10;i++){
            PWM1 = PWM1 - 0.1;
            // pc.printf("%1.3f\r\n", PWM_out);
            wait(0.1);
        }

        for(i=0;i<10;i++){
            PWM1 = PWM1 + 0.1;
            // pc.printf("%1.3f\r\n", PWM_out);
            wait(0.1);
        }
    }

    

}