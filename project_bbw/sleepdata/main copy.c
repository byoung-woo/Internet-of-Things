#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h> // strerror(), exit()
#include <stdlib.h> // exit()
#include "adc.h" // 센서 제어 관련 헤더 포함

int calcDistance(int psdVal) {
    int distance;
    distance = (67870 / (psdVal - 3)) - 40; // 센서 데이터 값을 바탕으로 거리 계산
    
    if (distance > 80)
        distance = 80;
    else if (distance < 10)
        distance = 10;
    
    return distance; // 거리 값 반환
}

int main(void) {
    int nPsd = 0; // 센서 데이터 변수 선언
    int nDistance = 0;

    if (wiringPiSetupGpio() == -1) { // wiringPi GPIO 라이브러리 초기화
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }

    if (wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED) == -1) {
        fprintf(stdout, "wiringPiSPISetup Failed: %s\n", strerror(errno));
        return 1;
    }

    pinMode(CS_MCP3208, OUTPUT); // 센서 핀 출력 설정 
    
    while (1) {
        delay(1000);
        nPsd = readSensor(PSD_PIN); // 센서 값 read
        nDistance = calcDistance(nPsd); // 측정 거리 계산
        printf("Distance: %d (cm)\n", nDistance);
    }
    
    return 0;
}
