#include "fan.h"            // FAN 제어 헤더 파일을 포함합니다.

void initFan() {            // FAN 초기화 함수입니다.
    pinMode(FAN_PIN1, OUTPUT);  // FAN 핀을 출력으로 설정합니다.
    pinMode(FAN_PIN2, OUTPUT);  // FAN 핀을 출력으로 설정합니다.
    offFan();               // FAN을 끕니다.
}

void onFan() {              // FAN을 켜는 함수입니다.
    digitalWrite(FAN_PIN1, HIGH);  // FAN 핀1을 HIGH로 설정하여 켭니다.
    digitalWrite(FAN_PIN2, LOW);   // FAN 핀2를 LOW로 설정하여 켭니다.
}

void offFan() {             // FAN을 끄는 함수입니다.
    digitalWrite(FAN_PIN1, LOW);   // FAN 핀1을 LOW로 설정하여 끕니다.
    digitalWrite(FAN_PIN2, LOW);   // FAN 핀2를 LOW로 설정하여 끕니다.
}

void controlFan(char bMotion) {    // FAN을 제어하는 함수입니다.
    if (bMotion == 1) {     // bMotion이 1이면 FAN을 켭니다.
        onFan();
        printf("fan on\n");
    } else {                // 그렇지 않으면 FAN을 끕니다.
        offFan();
        printf("fan off\n");
    }
}
