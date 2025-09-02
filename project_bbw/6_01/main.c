#include <stdio.h>          // 표준 입력과 출력 함수를 사용하기 위한 헤더 파일
#include <wiringPi.h>       // wiringPi 라이브러리를 사용하기 위한 헤더 파일
#include <string.h>         // 문자열 처리 함수를 사용하기 위한 헤더 파일
#include <errno.h>          // 오류 번호를 사용하기 위한 헤더 파일
#include "button.h"         // 버튼 제어 관련 헤더 파일을 포함합니다.
#include "fnd.h"            // 7세그먼트 디스플레이 제어 관련 헤더 파일 포함

int hours = 0;          // 시간 설정 변수
int minutes = 0;        // 분 설정 변수
int alarmHours = -1;    // 설정된 알람 시간 변수 (초기화는 -1)
int alarmMinutes = -1;  // 설정된 알람 분 변수 (초기화는 -1)
int alarmSet = 0;       // 알람 활성화 여부 변수

void displayTime() {
    displayHours(hours);   // 시간을 7세그먼트 디스플레이에 표시
    displayMinutes(minutes); // 분을 7세그먼트 디스플레이에 표시
}

void checkAlarm() {
    // 현재 시간과 알람 시간이 일치하면 알람을 울리는 코드
    if (alarmSet && hours == alarmHours && minutes == alarmMinutes) {
        // 알림 코드 호출 (추후 구현)
        printf("ALARM! ALARM!\n");
    }
}

int main(void) {
    int nButtonData = 0;    // 버튼 데이터 변수를 선언합니다.

    if (wiringPiSetupGpio() == -1) {   // WiringPi GPIO 초기화를 시도합니다.
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));   // 초기화 실패 시 오류 메시지를 출력합니다.
        return 1;
    }

    initButton();   // 버튼 초기화를 수행합니다.
    initFnd();      // FND 초기화를 수행합니다. // 수정: FND 초기화를 위해 추가된 코드

    while (1) {
        nButtonData = readButton();    // 버튼 입력을 읽어옵니다.

        if (nButtonData) {  // 버튼이 인식되었을 때만 해당 버튼 번호를 출력합니다.
            printf("BUTTON : %02X\n", nButtonData);  // 버튼 번호를 출력합니다.

            if (alarmSet) {
                switch (nButtonData) {
                    case 1: // 시간 설정 버튼
                        hours = (hours + 1) % 24;
                        displayTime();
                        break;
                    case 2: // 분 설정 버튼
                        minutes = (minutes + 1) % 60;
                        displayTime();
                        break;
                    case 3: // 알람 설정/저장 버튼
                        if (alarmHours == -1 && alarmMinutes == -1) {
                            alarmHours = hours;
                            alarmMinutes = minutes;
                            printf("Alarm set for %02d:%02d\n", alarmHours, alarmMinutes);
                        } else {
                            alarmHours = -1;
                            alarmMinutes = -1;
                            alarmSet = 0;
                            printf("Alarm cleared\n");
                        }
                        break;
                }
            } else {
                if (nButtonData == 3) {
                    alarmSet = 1;
                    printf("Alarm functionality activated\n");
                }
            }
        }

        checkAlarm(); // 알람 체크
        delay(1000);  // 1초 대기
    }

    return 0;
}
