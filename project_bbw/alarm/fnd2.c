#include "fnd.h"  // FND 제어 헤더 파일을 포함합니다.

const int FndSelectTable[MAX_FND_POSITION] = { // 세그먼트 위치 선택 테이블
    FND_SEL0, FND_SEL1, FND_SEL2, FND_SEL3, FND_SEL4, FND_SEL5
};

const int FndPinTable[MAX_FND_LED] = { // 세그먼트 데이터 핀 테이블
    FND_A, FND_B, FND_C, FND_D, FND_E, FND_F, FND_G, FND_DP
};

const int FndNumberTable[16] = { // 숫자 패턴 테이블
    A_BIT | B_BIT | C_BIT | D_BIT | E_BIT | F_BIT,       // '0'
    B_BIT | C_BIT,                                       // '1'
    A_BIT | B_BIT | D_BIT | E_BIT | G_BIT,               // '2'
    A_BIT | B_BIT | C_BIT | D_BIT | G_BIT,               // '3'
    B_BIT | C_BIT | F_BIT | G_BIT,                       // '4'
    A_BIT | C_BIT | D_BIT | F_BIT | G_BIT,               // '5'
    C_BIT | D_BIT | E_BIT | F_BIT | G_BIT,               // '6'
    A_BIT | B_BIT | C_BIT,                               // '7'
    A_BIT | B_BIT | C_BIT | D_BIT | E_BIT | F_BIT | G_BIT, // '8'
    A_BIT | B_BIT | C_BIT | F_BIT | G_BIT,               // '9'
    A_BIT | B_BIT | C_BIT | E_BIT | F_BIT | G_BIT,       // 'A'
    C_BIT | D_BIT | E_BIT | F_BIT | G_BIT,               // 'b'
    A_BIT | D_BIT | E_BIT | F_BIT,                       // 'C'
    B_BIT | C_BIT | D_BIT | E_BIT | G_BIT,               // 'd'
    A_BIT | D_BIT | E_BIT | F_BIT | G_BIT,               // 'E'
    A_BIT | E_BIT | F_BIT | G_BIT                        // 'F'
};

void initFnd() { // FND 초기화 함수
    for (int i = 0; i < MAX_FND_POSITION; i++) {
        pinMode(FndSelectTable[i], OUTPUT); // 세그먼트 위치 선택 핀 출력 설정
    }
    for (int i = 0; i < MAX_FND_LED; i++) {
        pinMode(FndPinTable[i], OUTPUT); // 세그먼트 데이터 핀 출력 설정
    }
}

void selectFnd(int Position) { // 세그먼트 위치 선택 함수
    for (int i = 0; i < MAX_FND_POSITION; i++) { // 세그먼트 위치에 출력
        digitalWrite(FndSelectTable[i], (Position & (1 << i)) ? LOW : HIGH);
    }
}

void offFnd() { // FND 모두 끄기
    for (int i = 0; i < MAX_FND_POSITION; i++) {
        digitalWrite(FndSelectTable[i], HIGH);
    }
}

void FndData(int position, long data1, long data2) {
    int fndData;
    for (int i = 0; i < MAX_FND_POSITION; i++) {
        if (i < 4) {
            // 시간 표시
            fndData = (data1 >> (8 * i)) & 0xFF;
        } else {
            // 분 표시
            fndData = (data2 >> (8 * (i - 4))) & 0xFF;
        }
        selectFnd(1 << i);
        for (int j = 0; j < MAX_FND_LED; j++) {
            digitalWrite(FndPinTable[j], (FndNumberTable[fndData & 0xF] & (1 << j)) ? HIGH : LOW);
        }
        delay(3);
    }
    offFnd(); // 모든 FND를 끕니다.
}
