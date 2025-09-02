#include "lcd.h" // LCD 헤더파일 포함

const int LcdDataPinTable[8] = { // LCD 데이터 핀 테이블
    LCD_DB_D0, LCD_DB_D1, LCD_DB_D2, LCD_DB_D3,
    LCD_DB_D4, LCD_DB_D5, LCD_DB_D6, LCD_DB_D7
};

const int LcdControlPinTable[3] = { // LCD 제어 핀 테이블
    LCD_CD_RS, LCD_CD_RW, LCD_CD_EN
};

void write_Data(unsigned char data) { // 데이터 신호 출력 함수
    digitalWrite(LCD_CD_RS, LOW);
    digitalWrite(LCD_CD_RW, LOW);
    digitalWrite(LCD_CD_EN, LOW);
    digitalWrite(LCD_CD_RS, HIGH); 
    int i;
    for (i = 0; i < 8; i++) {
        if (data & (1 << i)) {
            digitalWrite(LcdDataPinTable[i], HIGH); // 데이터 핀에 HIGH 출력
        } else {
            digitalWrite(LcdDataPinTable[i], LOW); // 데이터 핀에 LOW 출력
        }
    }
    digitalWrite(LCD_CD_EN, HIGH);
    delayMicroseconds(110);
    digitalWrite(LCD_CD_EN, LOW);
    delayMicroseconds(50); // 필수 지연 시간
}

void printString(char *string) { // 문자열 출력 함수
    while (*string != '\0') { // 문자열의 끝이 아니라면
        write_Data(*string); // 문자열 데이터 출력
        string++;
    }
}

void write_Command(unsigned char command) { // 제어명령 신호 출력 함수
    digitalWrite(LCD_CD_RS, LOW);
    digitalWrite(LCD_CD_RW, LOW);
    digitalWrite(LCD_CD_EN, LOW);
    int i;
    for (i = 0; i < 8; i++) {
        if (command & (1 << i)) {
            digitalWrite(LcdDataPinTable[i], HIGH); // 데이터 핀에 HIGH 출력
        } else {
            digitalWrite(LcdDataPinTable[i], LOW); // 데이터 핀에 LOW 출력
        }
    }
    delayMicroseconds(20);
    digitalWrite(LCD_CD_EN, HIGH);
    delayMicroseconds(300);
    digitalWrite(LCD_CD_EN, LOW);
    delayMicroseconds(20);
}

void initLcd(void) { // LCD 초기화 함수
    int i;
    for (i = 0; i < LCD_CD_PIN_NUM; i++) {
        pinMode(LcdControlPinTable[i], OUTPUT); // LCD 데이터 핀 출력 설정
        digitalWrite(LcdControlPinTable[i], LOW); // 데이터 핀에 LOW 출력
    }
    for (i = 0; i < LCD_DB_PIN_NUM; i++) {
        pinMode(LcdDataPinTable[i], OUTPUT); // LCD 제어 핀 출력 설정
        digitalWrite(LcdDataPinTable[i], LOW); // 제어 핀에 LOW 출력
    }
    delayMicroseconds(20);
    digitalWrite(LCD_CD_EN, LOW);
    delayMicroseconds(20);
    write_Command(0x38); // Function set
    delayMicroseconds(45);
    write_Command(0x38); // Function set
    delayMicroseconds(45);
    write_Command(0x0F); // Display ON
    delayMicroseconds(45);
    write_Command(0x01); // Clear Display
    delay(2);
    write_Command(0x06); // Entry mode set
    delayMicroseconds(45);
}

void setDDRAMAddress() {
    write_Command(0x80); // Set DDRAM Address
    delayMicroseconds(110);
}

void move2ndLine() {
    write_Command(0xC0); // Move to 2nd Line
    delayMicroseconds(110);
}
