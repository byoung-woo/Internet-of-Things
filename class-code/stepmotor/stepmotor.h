#include <wiringPi.h>       // wiringPi 라이브러리를 사용하기 위한 헤더 파일

// wiringPi 라이브러리 포함

#include <stdio.h>          // 표준 입력과 출력 함수를 사용하기 위한 헤더 파일

#define MOTOR_PIN1 20       // INA 핀을 정의합니다. (스텝 모터)
#define MOTOR_PIN2 21       // INB 핀을 정의합니다.
#define MOTOR_PIN3 19       // INC 핀을 정의합니다.
#define MOTOR_PIN4 26       // IND 핀을 정의합니다.
#define CLOCKWISE 1         // 시계 방향을 나타내는 정의입니다.
#define COUNTERCLOCKWISE 0  // 반시계 방향을 나타내는 정의입니다.
#define ON 1                // ON / OFF를 나타내는 정의입니다.
#define OFF 0               // ON / OFF를 나타내는 정의입니다.

void initStepMotor();               // 스텝 모터 초기화 함수의 프로토타입을 선언합니다.
void controlStepMotor(char cMotion, char cDirection);  // 스텝 모터 제어 함수의 프로토타입을 선언합니다.
void counterclockwise_2PhaseExcitation();             // 반시계 방향으로 2상여자를 활성화하는 함수의 프로토타입을 선언합니다.
void clockwise_2PhaseExcitation();                    // 시계 방향으로 2상여자를 활성화하는 함수의 프로토타입을 선언합니다.
