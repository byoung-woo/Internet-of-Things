#include <wiringPi.h> // wiringPi 라이브러리 포함
#include <stdio.h>
#include <string.h>

#define LCD_CD_RS 2   // LCD 핀 정의
#define LCD_CD_RW 3
#define LCD_CD_EN 4
#define LCD_DB_D0 18
#define LCD_DB_D1 23
#define LCD_DB_D2 24
#define LCD_DB_D3 25
#define LCD_DB_D4 7
#define LCD_DB_D5 12
#define LCD_DB_D6 16
#define LCD_DB_D7 22
#define LCD_DB_PIN_NUM 8
#define LCD_CD_PIN_NUM 3

void write_Data(unsigned char data);  // LCD 관련 함수 프로토타입 선언
void printString(char *string);
void write_Command(unsigned char command);
void initLcd();
void setDDRAMAddress();
void move2ndLine();
