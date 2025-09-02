#include <stdio.h>      // 표준 입력 및 출력 함수를 사용하기 위한 헤더 파일
#include <wiringPi.h>   // wiringPi 라이브러리를 사용하기 위한 헤더 파일
#include <string.h>     // 문자열 처리 함수를 사용하기 위한 헤더 파일
#include <errno.h>      // 오류 번호를 사용하기 위한 헤더 파일
#include <signal.h>     // 비동기 이벤트 처리를 위한 헤더 파일
#include <stdlib.h>     // 프로세스 종료를 위한 헤더 파일
#include "motor.h"      // 모터 제어 헤더 파일을 포함합니다.

void sig_handler(int sig); // 프로세스 종료 함수를 선언합니다.

int main(void) {
    signal(SIGINT, sig_handler);    // ^C (Ctrl+C) 입력을 sig_handler 함수로 전달합니다.

    if (wiringPiSetupGpio() == -1) {    // WiringPi GPIO 초기화를 시도합니다.
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));   // 초기화에 실패한 경우 오류 메시지를 출력합니다.
        return 1;
    }
    initMotor();    // 모터를 초기화합니다.

    while (1) {
        // 모터를 시계 방향으로 회전하고 2초 동안 대기합니다.
        controlMotor(ON, CLOCKWISE);
        delay(2000);
        // 모터를 멈추고 4초 동안 대기합니다.
        controlMotor(OFF, CLOCKWISE);
        delay(4000);
        // 모터를 반시계 방향으로 회전하고 2초 동안 대기합니다.
        controlMotor(ON, COUNTERCLOCKWISE);
        delay(2000);
        // 모터를 멈추고 4초 동안 대기합니다.
        controlMotor(OFF, COUNTERCLOCKWISE);
        delay(4000);
    }
    return 0;
}

void sig_handler(int sig) {
    controlMotor(OFF, CLOCKWISE);   // 모터를 멈춥니다.
    exit(0);    // 프로세스를 종료합니다.
}
