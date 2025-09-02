#include <stdio.h>          // 표준 입력과 출력 함수를 사용하기 위한 헤더 파일
#include <wiringPi.h>       // wiringPi 라이브러리를 사용하기 위한 헤더 파일
#include <string.h>         // 문자열 처리 함수를 사용하기 위한 헤더 파일
#include <errno.h>          // 오류 번호를 사용하기 위한 헤더 파일
#include "fan.h"            // FAN 제어 관련 헤더 파일을 포함합니다.

int main(void) {
    if (wiringPiSetupGpio() == -1) {   // WiringPi GPIO 초기화를 시도합니다.
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));   // 초기화 실패 시 오류 메시지를 출력합니다.
        return 1;
    }
    initFan();  // FAN을 초기화합니다.

    while (1) {
        controlFan(1);  // FAN을 켭니다.
        delay(3000);    // 3000 밀리초 (3초) 동안 대기합니다.
        controlFan(0);  // FAN을 끕니다.
        delay(1000);    // 1000 밀리초 (1초) 동안 대기합니다.
    }

    return 0;
}
