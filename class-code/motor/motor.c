#include "motor.h"          // 모터 제어 헤더 파일을 포함합니다.

void initMotor() {          // 모터 초기화 함수입니다.
    pinMode(MOTOR_CW_PIN, OUTPUT);     // 모터 IN1 핀을 출력으로 설정합니다.
    pinMode(MOTOR_CCW_PIN, OUTPUT);    // 모터 IN2 핀을 출력으로 설정합니다.
    controlMotor(OFF, 0);               // 모터를 꺼둡니다.
}

void controlMotor(char cMotion, char cDirection) {    // 모터 제어 함수입니다.
    if (cMotion == ON) {        // 모터가 켜져야 하는 경우
        if (cDirection == CLOCKWISE) {     // 시계 방향으로 회전해야 하는 경우
            digitalWrite(MOTOR_CW_PIN, HIGH);     // 모터 IN1을 HIGH로 설정하여 시계 방향으로 회전합니다.
            digitalWrite(MOTOR_CCW_PIN, LOW);     // 모터 IN2를 LOW로 설정하여 시계 방향으로 회전합니다.
            printf("motor on clockwise\n");       // 모터가 시계 방향으로 회전 중임을 출력합니다.
        } else if (cDirection == COUNTERCLOCKWISE) {     // 반시계 방향으로 회전해야 하는 경우
            digitalWrite(MOTOR_CW_PIN, LOW);      // 모터 IN1을 LOW로 설정하여 반시계 방향으로 회전합니다.
            digitalWrite(MOTOR_CCW_PIN, HIGH);     // 모터 IN2를 HIGH로 설정하여 반시계 방향으로 회전합니다.
            printf("motor on counterclockwise\n");    // 모터가 반시계 방향으로 회전 중임을 출력합니다.
        }
    } else if (cMotion == OFF) {   // 모터가 꺼져야 하는 경우
        digitalWrite(MOTOR_CW_PIN, LOW);      // 모터 IN1을 LOW로 설정하여 모터를 멈춥니다.
        digitalWrite(MOTOR_CCW_PIN, LOW);     // 모터 IN2를 LOW로 설정하여 모터를 멈춥니다.
        printf("motor off\n");      // 모터가 꺼졌음을 출력합니다.
    }
}
