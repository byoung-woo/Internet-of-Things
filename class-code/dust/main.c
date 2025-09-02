#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h> // strerror(), exit()
#include <stdlib.h> // exit()
#include "adc.h" // 센서 제어 관련 헤더 포함
#include "dust.h" // 센서 제어 관련 헤더 포함

int main(void) {
    float gfDust = 0; // 센서 데이터 변수
    
    if (wiringPiSetupGpio() == -1) { // wiringPi GPIO 초기화
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }
    
    if (wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED) == -1) { // wiringPi SPI GPIO 초기화
        fprintf(stdout, "wiringPiSPISetup Failed: %s\n", strerror(errno));
        return 1;
    }
    
    initDustSensor(DUST_LED_PIN); // 먼지 센서 LED 초기화
    pinMode(CS_MCP3208, OUTPUT); // 센서 핀 출력 설정
    
    while (1) {
        delay(1000);
        gfDust = readDustSensor(DUST_PIN, DUST_LED_PIN); // 센서 값 read
        printf("Dust : %f\n", gfDust);
    }
    
    return 0;
}
