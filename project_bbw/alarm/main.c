#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include "fnd.h"
#include "button.h"
#include "buzzer.h" // 새로운 코드: 버저 헤더 파일 포함

void sig_handler(int sig);

int hours = 0;
int minutes = 0;
int alarmHours = -1;
int alarmMinutes = -1;
int mode = 0; // 0: normal, 1: setting hours, 2: setting minutes, 3: setting alarm
int alarmModeActive = 0; // 알람 모드 활성화 플래그
int alarmTriggered = 0; // 새로운 코드: 알람 울림 상태 플래그

void updateDisplay() {
    unsigned int unFndData1 = 0;
    unsigned int unFndData2 = 0;
    
    unFndData1 = (hours / 10) << 24 | (hours % 10) << 16;
    unFndData2 = (minutes / 10) << 8 | (minutes % 10);

    FndData(0, unFndData1, unFndData2);
}

int main(void) {
    int nButtonData = 0;
    signal(SIGINT, sig_handler);

    if (wiringPiSetupGpio() == -1) {
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }

    initFnd();
    initButton();
    initBuzzer(); // 새로운 코드: 버저 초기화

    while (1) {
        nButtonData = readButton();
        
        if (nButtonData) {
            if (alarmModeActive == 0) { // 알람 모드가 비활성화된 상태에서만 동작
                if (nButtonData & 0x04) { // 3번 버튼: 알람 모드 설정/저장
                    alarmModeActive = 1; // 알람 모드 활성화
                    mode = 1; // 시간 설정 모드로 진입
                    updateDisplay();
                }
            } else { // 알람 모드가 활성화된 상태에서만 1번, 2번 버튼 동작
                if (nButtonData & 0x01) { // 1번 버튼: 시간 설정
                    if (mode == 1) {
                        hours = (hours + 1) % 24;
                        if (hours == 0) hours = 1;
                        updateDisplay();
                    }
                }
                if (nButtonData & 0x02) { // 2번 버튼: 분 설정
                    if (mode == 2) {
                        minutes = (minutes + 10) % 60;
                        updateDisplay();
                    }
                }
                if (nButtonData & 0x04) { // 3번 버튼: 알람 모드 저장
                    if (mode == 3) {
                        alarmHours = hours;
                        alarmMinutes = minutes;
                        alarmModeActive = 0; // 알람 모드 비활성화
                        mode = 0; // 정상 모드로 복귀
                    } else {
                        mode++;
                    }
                    updateDisplay();
                }
            }

            if (nButtonData & 0x08) { // 4번 버튼: 알람 끄기
                if (alarmTriggered) { // 새로운 코드: 알람이 울리고 있을 때만
                    turnOffBuzzer(); // 새로운 코드: 버저 끄기
                    alarmTriggered = 0; // 새로운 코드: 알람 울림 상태 초기화
                }
            }
        }
        
        // 현재 시간 가져오기
        time_t now = time(NULL);
        struct tm *tm_now = localtime(&now);
        int currentHour = tm_now->tm_hour;
        int currentMinute = tm_now->tm_min;

        if (mode == 0) { // 정상 모드일 때만 현재 시간 표시
            hours = currentHour;
            minutes = currentMinute;
            updateDisplay();
        }

        // 알람 확인
        if (alarmHours == currentHour && alarmMinutes == currentMinute && !alarmTriggered) { // 새로운 코드: 알람 울림 확인
            controlBuzzer(ON); // 새로운 코드: 버저 켜기
            alarmTriggered = 1; // 새로운 코드: 알람 울림 상태 설정
        }
        
        delay(100); // 버튼 입력 지연 방지
    }
    return 0;
}

void sig_handler(int sig) {
    offFnd();
    controlBuzzer(OFF);
    exit(0);
}
