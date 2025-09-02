#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include "button.h" // 버튼 제어 헤더파일 포함
#include "fnd.h" // 세그먼트 제어 헤더파일 포함

void sig_handler(int sig); // 프로세스 종료 함수 선언

int main(void) {
    unsigned int count = 0; // 카운트 변수
    int buttonState = 0; // 버튼 상태 변수
    int previousButtonState = 0; // 이전 버튼 상태 변수

    signal(SIGINT, sig_handler); // ^C 입력을 sig_handler 함수로 전달
    
    if (wiringPiSetupGpio() == -1) {
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }
    
    initButton(); // 버튼 초기화
    initFnd(); // 세그먼트 초기화
    
    while (1) {
        buttonState = readButton(); // 버튼 입력을 읽어옵니다
        
        if ((buttonState & 0x01) && !(previousButtonState & 0x01)) { // 1번 버튼이 눌렸을 때
            count = (count + 1) % 25; // 0~24까지 카운트
            int tens = count / 10; // 5번째 자리
            int ones = count % 10; // 4번째 자리
            FndData(4, 0, ones); // 4번째 자리에 출력
            FndData(5, 0, tens); // 5번째 자리에 출력
        }
        
        previousButtonState = buttonState; // 이전 버튼 상태 업데이트
        delay(100); // 버튼 입력을 읽는 주기를 조정
    }
    
    return 0;
}

void sig_handler(int sig) {
    offFnd(); // 세그먼트 모두 끄기
    exit(0); // 프로세스 종료
}
