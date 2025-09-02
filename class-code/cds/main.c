#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h> // 에러 처리 라이브러리 포함
#include <stdlib.h> // 프로세스 종료 라이브러리 포함
#include "cds.h" // 조도 센서 제어 헤더 파일 포함

int main(void) {
    int nLight = 200; // 센서 데이터 변수 선언

    if (wiringPiSetupGpio() == -1) { // wiringPi GPIO 초기화
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }

    if (wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED) == -1) { // wiringPi SPI 초기화
        fprintf(stdout, "wiringPiSPISetup Failed: %s\n", strerror(errno));
        return 1;
    }

    pinMode(CS_MCP3208, OUTPUT); // 센서 핀 출력 설정

    while (1) {
        delay(1000);
        nLight = readSensor(CDS_PIN); // 센서 값 수신
        printf("Illuminance = %d\n", nLight);
    }

    return 0;
}
