#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h> // 에러 처리 라이브러리 포함
#include <signal.h> // 비동기 이벤트 라이브러리 포함
#include <stdlib.h> // 프로세스 종료 라이브러리 포함
#include "lcd.h" // Text LCD 제어 헤더파일 포함

void sig_handler(int sig); // 프로세스 종료 함수 선언

int main(void) {
    signal(SIGINT, sig_handler); // ^c 입력을 sig_handler 함수로 전달
    if (wiringPiSetupGpio() == -1) {
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }
    delay(50);
    initLcd();
    delay(50);
    printString("Hello World!");
    setDDRAMAddress();
    move2ndLine();
    printString("Raspberry Pi");
    while (1) {}
    return 0;
}

void sig_handler(int sig) {
    initLcd(); // Text LCD 초기화
    exit(0); // 프로세스 종료
}
