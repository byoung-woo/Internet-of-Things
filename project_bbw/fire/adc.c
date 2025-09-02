#include "adc.h" //가스 센서 제어 헤더파일 포함

int readAdc(unsigned char adcChannel) //ADC Read 함수
{
    unsigned char buff[3]; //통신 데이터 버퍼
    int nAdcValue = 0;
    buff[0] = 0x06 | ((adcChannel & 0x07) >> 2);
    buff[1] = ((adcChannel & 0x07)<<6);
    buff[2] = 0x00;
    digitalWrite(CS_MCP3208, 0); //SPI Chip Select 신호 출력 설정
    wiringPiSPIDataRW(SPI_CHANNEL, buff, 3); //SPI 통신 채널 설정
    buff[1] = 0x0F & buff[1]; //수신되는 센서 데이터 값
    nAdcValue = (buff[1]<<8) | buff[2];
    digitalWrite(CS_MCP3208, 1); //SPI Chip Select 신호 출력 설정
    return nAdcValue;
}

int readSensor(int nChannel) //센서 값 read
{
    int nSensorVal = 0;
    nSensorVal = readAdc(nChannel); //해당 채널의 센서값 read
    return nSensorVal;
}
