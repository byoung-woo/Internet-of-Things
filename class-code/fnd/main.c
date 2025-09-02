#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h> // 에러 처리 라이브러리 포함
#include <signal.h> // 비동기 이벤트 라이브러리 포함
#include <stdlib.h> // 프로세스 종료 라이브러리 포함
#include "fnd.h" // 세그먼트 제어 헤더파일 포함

void sig_handler(int sig); // 프로세스 종료 함수 선언

int main(void) {
    unsigned int unFndData1 = 0x04030201;
    unsigned int unFndData2 = 0x00000605;
    int nFndPosition = 0;
    signal(SIGINT, sig_handler); // ^c 입력을 sig_handler 함수로 전달
    if (wiringPiSetupGpio() == -1) {
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }
    initFnd(); // 세그먼트 초기화
    while (1) {
        FndData(nFndPosition, unFndData1, unFndData2);
        nFndPosition++;
        if (nFndPosition > 5) {
            nFndPosition = 0;
        }
    }
    return 0;
}

void sig_handler(int sig) {
    offFnd(); // 세그먼트 모두 끄기
    exit(0); // 프로세스 종료
}
