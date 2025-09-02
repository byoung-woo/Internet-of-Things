#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include "buzzer.h" // 센서 제어 관련 헤더 포함

void sig_handler(int sig); // 종료 프로세스 함수 선언

int main(void) {
    signal(SIGINT, sig_handler);

    if (wiringPiSetupGpio() == -1) { // wiringPi GPIO 초기화
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }

    initBuzzer(); // 버저 핀 초기화
    controlBuzzer(ON); // 센서 핀 출력 설정

    while (1) {}

    return 0;
}

void sig_handler(int sig) { // 프로세스 종료 시
    controlBuzzer(OFF);
    exit(0);
}
