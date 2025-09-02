#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h>
#include "led.h"

int main(void) {
    if (wiringPiSetupGpio() == -1) { // 라이브러리 초기화, 초기화 실패하면 오류메시지 출력
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }
    initLed();
    while(1) {
        controlLed(0x01);
        delay(500);
        controlLed(0x02);
        delay(500);
    }
    return 0;
}
