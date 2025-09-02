#include "stepmotor.h"      // 스텝 모터 제어 헤더 파일을 포함합니다.

int motorSpeed = 5;         // 스텝 모터 속도 변수를 정의하고 초기화합니다.

void initStepMotor() {      // 스텝 모터 초기화 함수입니다.
    pinMode(MOTOR_PIN1, OUTPUT);    // 모터 핀들을 출력으로 설정합니다.
    pinMode(MOTOR_PIN2, OUTPUT);
    pinMode(MOTOR_PIN3, OUTPUT);
    pinMode(MOTOR_PIN4, OUTPUT);
}

void controlStepMotor(char cMotion, char cDirection) {   // 스텝 모터 제어 함수입니다.
    if (cMotion == OFF) {       // 모터를 끄는 경우
        digitalWrite(MOTOR_PIN1, LOW);     // 각 핀에 LOW 값을 설정하여 모터를 멈춥니다.
        digitalWrite(MOTOR_PIN2, LOW);
        digitalWrite(MOTOR_PIN3, LOW);
        digitalWrite(MOTOR_PIN4, LOW);
    } else {                    // 모터를 켜는 경우
        if (cDirection == CLOCKWISE) {     // 시계 방향으로 회전해야 하는 경우
            clockwise_2PhaseExcitation();  // 시계 방향으로 2상여자를 활성화합니다.
        } else if (cDirection == COUNTERCLOCKWISE) {    // 반시계 방향으로 회전해야 하는 경우
            counterclockwise_2PhaseExcitation();    // 반시계 방향으로 2상여자를 활성화합니다.
        }
    }
}

void counterclockwise_2PhaseExcitation() { // 반 시계 방향(2상여자)
    // 1
    digitalWrite(MOTOR_PIN4, HIGH);
    digitalWrite(MOTOR_PIN3, HIGH);
    digitalWrite(MOTOR_PIN2, LOW);
    digitalWrite(MOTOR_PIN1, LOW);
    delay(motorSpeed);
    // 2
    digitalWrite(MOTOR_PIN4, LOW);
    digitalWrite(MOTOR_PIN3, HIGH);
    digitalWrite(MOTOR_PIN2, HIGH);
    digitalWrite(MOTOR_PIN1, LOW);
    delay(motorSpeed);
    // 3
    digitalWrite(MOTOR_PIN4, LOW);
    digitalWrite(MOTOR_PIN3, LOW);
    digitalWrite(MOTOR_PIN2, HIGH);
    digitalWrite(MOTOR_PIN1, HIGH);
    delay(motorSpeed);
    // 4
    digitalWrite(MOTOR_PIN4, HIGH);
    digitalWrite(MOTOR_PIN3, LOW);
    digitalWrite(MOTOR_PIN2, LOW);
    digitalWrite(MOTOR_PIN1, HIGH);
    delay(motorSpeed);
}

void clockwise_2PhaseExcitation() { // 시계 방향(2상여자)
    // 1
    digitalWrite(MOTOR_PIN1, HIGH);
    digitalWrite(MOTOR_PIN2, HIGH);
    digitalWrite(MOTOR_PIN3, LOW);
    digitalWrite(MOTOR_PIN4, LOW);
    delay(motorSpeed);
    // 2
    digitalWrite(MOTOR_PIN1, LOW);
    digitalWrite(MOTOR_PIN2, HIGH);
    digitalWrite(MOTOR_PIN3, HIGH);
    digitalWrite(MOTOR_PIN4, LOW);
    delay(motorSpeed);
    // 3
    digitalWrite(MOTOR_PIN1, LOW);
    digitalWrite(MOTOR_PIN2, LOW);
    digitalWrite(MOTOR_PIN3, HIGH);
    digitalWrite(MOTOR_PIN4, HIGH);
    delay(motorSpeed);
    // 4
    digitalWrite(MOTOR_PIN1, HIGH);
    digitalWrite(MOTOR_PIN2, LOW);
    digitalWrite(MOTOR_PIN3, LOW);
    digitalWrite(MOTOR_PIN4, HIGH);
    delay(motorSpeed);
}
