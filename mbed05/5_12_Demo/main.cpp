#include "mbed.h"

Ticker time_up;
DigitalOut BlueLED(LED3);

void blink(){
    BlueLED = !BlueLED;
}

int main(){
    time_up.attach(&blink, 0.5);
    while(1);    
}