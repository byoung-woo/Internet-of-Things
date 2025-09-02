#include <stdio.h>          // 표준 입력과 출력 함수를 사용하기 위한 헤더 파일
#include <string.h>         // 문자열 처리 함수를 사용하기 위한 헤더 파일
#include <errno.h>          // 오류 번호를 사용하기 위한 헤더 파일
#include <wiringPi.h>       // wiringPi 라이브러리를 사용하기 위한 헤더 파일

// wiringPi 라이브러리 포함

#define BUTTON_PIN1 23      // 첫 번째 버튼 핀 정의
#define BUTTON_PIN2 24      // 두 번째 버튼 핀 정의
#define BUTTON_PIN3 25      // 세 번째 버튼 핀 정의
#define BUTTON_PIN4 20      // 네 번째 버튼 핀 정의
#define MAX_KEY_BT_NUM 4    // 버튼 개수의 최대값 정의

// BUTTON 관련 함수의 프로토타입 선언
void initButton();
int readButton();
