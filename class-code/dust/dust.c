#include "dust.h" // 센싱 관련 헤더 파일 포함
#include "adc.h" // ADC 관련 헤더 파일 포함

float Vo_Val = 0; // 관련 변수 선언
float Voltage = 0;
float dustDensity = 0;
int samplingTime = 280; // 0.28ms
int delayTime = 40; // 0.04ms
int offTime = 9680; // 9.68ms

void initDustSensor(int nLedPin) // 먼지 센서 초기화 함수
{
    pinMode(nLedPin, OUTPUT); // 먼지 센서 LED 핀 출력 설정
}

float readDustSensor(int analogPin, int ledPin) // 센서 값 read 함수
{
    digitalWrite(ledPin, LOW); // LED 켜기
    delayMicroseconds(samplingTime); // 0.28ms 지연
    
    Vo_Val = readAdc(analogPin); // 센서값 read
    printf("Vo_Val : %f, ", Vo_Val);
    
    delayMicroseconds(delayTime); // 0.04ms 지연
    
    digitalWrite(ledPin, HIGH); // LED 끄기
    delayMicroseconds(offTime); // 9.68ms 지연
    
    Voltage = Vo_Val * 4.1 / 4096; // 전압 계산
    dustDensity = (Voltage - 0.4) / 0.005; // 먼지 수치 계산
    
    printf("Voltage : %f, ", Voltage);
    printf(" Value : %f(ug/m3)\n", dustDensity);
    
    return dustDensity; // 먼지 수치 반환
}
