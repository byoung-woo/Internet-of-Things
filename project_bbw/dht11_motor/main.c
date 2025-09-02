#include <stdio.h>      
#include <wiringPi.h>   
#include <string.h>     
#include <errno.h>      
#include <signal.h>     
#include <stdlib.h>     
#include "motor.h"      
#include "dht11.h"

void sig_handler(int sig); 

int gnTemp = 0; // Declare temperature sensor data variable
int gnHumi = 0;

int main(void) {
    signal(SIGINT, sig_handler);    

    if (wiringPiSetupGpio() == -1) {    
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));   // 초기화에 실패한 경우 오류 메시지를 출력합니다.
        return 1;
    }
    initMotor();    

    while (1) {
        
        readDht11(DHT_PIN);
        
        if(gnTemp>=26){
            controlMotor(ON, CLOCKWISE);
            printf("Temperature: %d°C\n", gnTemp);
            printf("air conditioning operation");
        }
        else if (gnTemp<18){
            controlMotor(ON, COUNTERCLOCKWISE);
            printf("Temperature: %d°C\n", gnTemp);
            printf("heater operation");
        }
        
        else {
            controlMotor(OFF, CLOCKWISE);
            printf("Temperature: %d°C\n", gnTemp);
        }
        delay(2000);    

    }
    return 0;
}

void sig_handler(int sig) {
    controlMotor(OFF, CLOCKWISE);   // 모터를 멈춥니다.
    exit(0);    // 프로세스를 종료합니다.
}
