#include <wiringPi.h>

#define LED1 5
#define LED2 6
#define LED_MAX 8
#define LED_POSITION 8

void initLed();
// ledPosition : 0x01~0xFF
void controlLed(int nLedPosition);
