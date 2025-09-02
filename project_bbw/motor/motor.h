#include <wiringPi.h>       // wiringPi 라이브러리를 사용하기 위한 헤더 파일

// wiringPi 라이브러리 포함

#include <stdio.h>          // 표준 입력과 출력 함수를 사용하기 위한 헤더 파일

#define MOTOR_CW_PIN 20     // 모터 IN1 핀을 정의합니다.
#define MOTOR_CCW_PIN 21    // 모터 IN2 핀을 정의합니다.
#define CLOCKWISE 1         // 시계 방향을 나타내는 상수를 정의합니다.
#define COUNTERCLOCKWISE 0  // 반시계 방향을 나타내는 상수를 정의합니다.
#define ON 1                // 모터를 켜는 상수를 정의합니다.
#define OFF 0               // 모터를 끄는 상수를 정의합니다.

void initMotor();           // 모터 초기화 함수의 프로토타입을 선언합니다.
void controlMotor(char cMotion, char cDirection);   // 모터 제어 함수의 프로토타입을 선언합니다.
