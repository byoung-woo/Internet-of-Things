#include "led.h"

const char LedPinTable[LED_MAX] = {LED1, LED2};

void initLed() {
    int i;
    for (i = 0; i < LED_MAX; i++) {
        pinMode(LedPinTable[i], OUTPUT); //LED PORT SET
        digitalWrite(LedPinTable[i], LOW); //LED OFF
    }
}
// 이 함수는 LED_MAX만큼 반복하면서 각 LED 핀을 출력으로 설정하고, LOW 상태로 초기화합니다. 이는 LED를 초기에 모두 꺼진 상태로 설정하는 것입니다.

// LED를 제어하기 전에 initLed() 함수를 호출하여 LED를 적절히 초기화해야 합니다. LED를 켜고 끄기 전에 이 초기화 단계가 필요합니다.


void controlLed(int nLedPosition) {
    int i;
    for (i = 0; i < LED_MAX; i++) {
        if (nLedPosition & (1 << i)) {
            digitalWrite(LedPinTable[i], HIGH);
        } else {
            digitalWrite(LedPinTable[i], LOW);
        }
    }
}

// 이 함수는 하나의 매개변수 nLedPosition을 받습니다. 이 매개변수는 LED의 상태를 나타내는 비트 패턴입니다. 예를 들어, 0x01은 첫 번째 LED를 켜고 나머지는 끈 상태를 나타냅니다. 
// 0x02는 두 번째 LED를 켜고 나머지는 끈 상태를 나타냅니다. 이처럼 LED의 위치에 해당하는 비트가 1인 경우에는 LED를 켜고, 0인 경우에는 LED를 끕니다.
// 해당 함수는 LED_MAX만큼 반복하면서 nLedPosition에 따라 LED를 켜거나 끕니다. nLedPosition에서 각 비트를 검사하여 해당 위치의 LED를 켜거나 끄는 동작을 수행합니다.

// 이 함수를 호출할 때는 켜고자 하는 LED의 위치를 비트 패턴으로 전달하여 LED를 켜고 끌 수 있습니다.