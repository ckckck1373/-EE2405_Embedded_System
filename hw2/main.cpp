#include "mbed.h"
#include <math.h>

Serial pc (USBTX, USBRX);
// Out
DigitalOut redLED(LED1);
DigitalOut greenLED(LED2);
AnalogOut Aout(DAC0_OUT);

// In
DigitalIn Switch(SW3);
AnalogIn Ain(A0);
BusOut display(D6, D7, D9, D10, D11, D5, D4, D8);

// Other

char table[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int sample = 1000;
float ADCdata[1000]; 
int i;
float j;
float frequency_float;
int frequency;
int count_start=0;

bool flag=0;

int main(){
    redLED = 1;
    greenLED = 1;
    
    for(i=0;i< sample;i++){
        // Aout=Ain;
        ADCdata[i]=Ain;
        wait(1./1000);
    }

    //find the peak 
    for(i=0;i<sample;i++){
        if(i!=0 && i!=sample-1 && ADCdata[i]>ADCdata[i+1] && ADCdata[i]>ADCdata[i-1] && flag==0){
            count_start = i;
            flag=1;
        }else if(i!=0 && i!=sample-1 && ADCdata[i]>ADCdata[i+1] && ADCdata[i]>ADCdata[i-1] && flag==1){
            count_start = i-count_start;
            break;
        }
    }

    for(i=0;i<sample;i++){
        pc.printf("%1.3f\r\n", ADCdata[i]);
        wait(0.01);
    }

    frequency = 1000/count_start;
    while(1){
        // Aout = 0.5*sin(2*3.1415*frequency*i)+0.5;
        // pc.printf("%1.3f\r\n", Aout);
        // i=i+0.001;
        // wait(0.001);
 
        

       
        // no press
        if(Switch == 1){
            // Led: RED
            redLED = 0;
            greenLED = 1;

            // 7Seg: off
            display = 0x00;

            for(j=0;j<2;j+=0.05){
                Aout = 0.5+0.5*sin(3.1415*j);
                wait(1./(40*frequency));
            }

        }else{//press
            // Led: GREEN
            redLED = 1;
            greenLED = 0;
            

            

            // 7Seg: on
            display = table[(frequency/100)%10];
            wait(0.5);
            display = table[(frequency/10)%10];
            wait(0.5);
            display = table[frequency%10];
            display[7]=1;
            wait(0.5);
        }
    }

}