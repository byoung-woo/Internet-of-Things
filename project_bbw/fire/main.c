#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h> // 에러 처리 라이브러리 포함
#include <stdlib.h> // 프로세스 종료 라이브러리 포함
#include "adc.h" // 가스 센서 제어 헤더파일 포함
#INCLUDE "led.h"
#include "dht11.h"

int main(void) {
    int gnGas = 0; // 센서 데이터 변수 선언
    int temperature = 0; // 온도 데이터 변수 선언
    int ledState = 0; // LED 상태 변수 선언
    int fireDetected = 0; // 화재 감지 변수 선언
    unsigned long startTime = 0; // LED 깜박임 시작 시간

    if (wiringPiSetupGpio() == -1) { // wiringPi GPIO 초기화
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }

    if (wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED) == -1) { // wiringPi SPI 초기화
        fprintf(stdout, "wiringPiSPISetup Failed: %s\n", strerror(errno));
        return 1;
    }

    pinMode(CS_MCP3208, OUTPUT); // 센서 핀 출력 설정
    pinMode(LED_PIN, OUTPUT); // LED 핀 출력 설정

    while (1) {
        delay(1000);
        gnGas = readSensor(GAS_PIN); // 가스 센서 값 수신
        temperature = readTemperature(TEMP_PIN); // 온도 센서 값 수신

        if (temperature >= 100 && gnGas > 0) { // 온도 100도 이상, 가스 검출
            if (!fireDetected) {
                fireDetected = 1; // 화재 감지 시작
                startTime = millis(); // 시작 시간 기록
            }
            // LED 깜박임
            ledState = !ledState;
            digitalWrite(LED_PIN, ledState);
        } else {
            fireDetected = 0; // 화재 감지 종료
            digitalWrite(LED_PIN, LOW); // LED 끄기
        }

        if (fireDetected && (millis() - startTime >= 60000)) { // 1분 경과
            fireDetected = 0; // 화재 감지 종료
            digitalWrite(LED_PIN, LOW); // LED 끄기
        }
    }

    return 0;
}
