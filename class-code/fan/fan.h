#include <wiringPi.h>       // wiringPi 라이브러리를 사용하기 위한 헤더 파일

// wiringPi 라이브러리 포함

#include <stdio.h>          // 표준 입력과 출력 함수를 사용하기 위한 헤더 파일

#define FAN_PIN1 20         // 첫 번째 FAN 핀 정의
#define FAN_PIN2 21         // 두 번째 FAN 핀 정의

void initFan();             // FAN 초기화 함수의 프로토타입 선언
void onFan();               // FAN 켜는 함수의 프로토타입 선언
void offFan();              // FAN 끄는 함수의 프로토타입 선언
void controlFan(char bMotion);  // FAN을 제어하는 함수의 프로토타입 선언
