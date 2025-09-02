#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h> //wiringPi 라이브러리 포함
#include <wiringPiSPI.h> //wiringPiSPI 라이브러리 포함

#define CS_MCP3208 8 //SPI 통신 핀 정의
#define SPI_CHANNEL 0
#define SPI_SPEED 1000000
#define GAS_PIN 2 //센서 핀 정의

int readAdc(unsigned char adcChannel); //센서 관련 함수 프로토타입 선언
int readSensor(int nChannel);
