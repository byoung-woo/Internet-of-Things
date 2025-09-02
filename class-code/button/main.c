#include <stdio.h>          // 표준 입력과 출력 함수를 사용하기 위한 헤더 파일
#include <wiringPi.h>       // wiringPi 라이브러리를 사용하기 위한 헤더 파일
#include <string.h>         // 문자열 처리 함수를 사용하기 위한 헤더 파일
#include <errno.h>          // 오류 번호를 사용하기 위한 헤더 파일
#include "button.h"         // 버튼 제어 관련 헤더 파일을 포함합니다.

int main(void) {
    int nButtonData = 0;    // 버튼 데이터 변수를 선언합니다.

    if (wiringPiSetupGpio() == -1) {   // WiringPi GPIO 초기화를 시도합니다.
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));   // 초기화 실패 시 오류 메시지를 출력합니다.
        return 1;
    }

    initButton();   // 버튼 초기화를 수행합니다.

    while (1) {
        nButtonData = readButton();    // 버튼 입력을 읽어옵니다.

        if (nButtonData) {  // 버튼이 인식되었을 때만 해당 버튼 번호를 출력합니다.
            printf("BUTTON : %02X\n", nButtonData);  // 버튼 번호를 출력합니다.
        }
    }

    return 0;
}
