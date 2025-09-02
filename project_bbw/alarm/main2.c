#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include "fnd.h"
#include "button.h"  // 버튼 제어 관련 헤더 파일 포함

void sig_handler(int sig); // 프로세스 종료 함수 선언

int currentNumber = 1;  // 현재 표시할 숫자

void displayNumber(int number) {
    unsigned int data1 = 0;
    unsigned int data2 = 0;

    if (number < 10) {
        data1 = number;
    } else {
        data1 = number % 10;
        data2 = number / 10;
    }

    FndData(0, data1, data2);  // 숫자 표시
}

int main(void) {
    int nButtonData = 0;

    signal(SIGINT, sig_handler); // ^C 입력을 sig_handler 함수로 전달
    if (wiringPiSetupGpio() == -1) {
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }

    initFnd();  // FND 초기화
    initButton();  // 버튼 초기화

    while (1) {
        nButtonData = readButton();  // 버튼 입력 읽기

        if (nButtonData) {
            currentNumber++;  // 숫자 증가
            if (currentNumber > 24) {
                currentNumber = 1;  // 24 초과 시 1로 돌아가기
            }
            displayNumber(currentNumber);  // 숫자 표시
            delay(500);  // 버튼이 여러 번 인식되지 않도록 지연
        }
    }

    return 0;
}

void sig_handler(int sig) {
    offFnd();  // 세그먼트 모두 끄기
    exit(0);  // 프로세스 종료
}
