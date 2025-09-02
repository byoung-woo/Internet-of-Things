#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>

#define CS_MCP3208 8 // SPI 통신 핀 정의
#define SPI_CHANNEL 0
#define SPI_SPEED 1000000
#define CDS_PIN 0 // 센서 핀 정의

int readAdc(unsigned char adcChannel); // 센서 관련 함수 프로토타입 선언
int readSensor(int nChannel);
