#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h> // wiringPi 라이브러리 포함

#define DUST_LED_PIN 17 // 센서 LED 핀 정의

void initDustSensor(int nLedPin); // 센서 관련 함수 프로토타입 선언
float readDustSensor(int analogPin, int ledPin);
