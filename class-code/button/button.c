#include "button.h"         // button 헤더 파일을 포함합니다.

// button 헤더 파일 포함

const int ButtonTable[MAX_KEY_BT_NUM] = {   // 버튼 핀 테이블을 선언합니다.
    BUTTON_PIN1,
    BUTTON_PIN2,
};

void initButton() {
    int i;
    for (i = 0; i < MAX_KEY_BT_NUM; i++) {  // 버튼 핀을 입력으로 설정합니다.
        pinMode(ButtonTable[i], INPUT);
    }
}

int readButton() {                          // 버튼을 읽어오는 함수입니다.
    int i = 0;
    int buttonPin = 0;
    for (i = 0; i < MAX_KEY_BT_NUM; i++) {  // 버튼의 감지값을 저장합니다.
        if (!digitalRead(ButtonTable[i])) {
            buttonPin |= (1 << i);
        }
    }
    return buttonPin;                       // 버튼의 감지값을 반환합니다.
}

// initButton() 함수는 버튼 초기화를 위해 사용됩니다. 버튼 핀을 입력으로 설정합니다.
// readButton() 함수는 버튼의 입력을 읽어오는 함수입니다. 각 버튼 핀의 감지값을 읽어와 이진 플래그로 만든 후 반환합니다