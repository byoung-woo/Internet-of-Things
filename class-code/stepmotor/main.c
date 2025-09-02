#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h> // 에러 처리 라이브러리 포함
#include <signal.h> // 비동기 이벤트 라이브러리 포함
#include <stdlib.h> // 프로세스 종료 라이브러리 포함
#include "stepmotor.h" // 스텝 모터 제어 헤더파일 포함

void sig_handler(int sig); // 프로세스 종료 함수 선언

int main(void) {
    signal(SIGINT, sig_handler); // ^c 입력을 sig_handler 함수로 전달
    if (wiringPiSetupGpio() == -1) {
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    } 
    initStepMotor(); // 스텝 모터 초기화
    while (1) {
        for (int i = 0; i < 100; i++) {
            controlStepMotor(ON, CLOCKWISE);
        }
        for (int i = 0; i < 100; i++) {
            controlStepMotor(ON, COUNTERCLOCKWISE);
        }
    }
    return 0;
}

void sig_handler(int sig) {
    controlStepMotor(OFF, 0); // 스텝 모터 정지
    exit(0); // 프로세스 종료
}
