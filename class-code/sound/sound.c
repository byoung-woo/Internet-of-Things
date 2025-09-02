#include "sound.h"

void initSound(int nPin) {
    pinMode(nPin, INPUT);
}

int readSound(int nPin) {
    int nSoundDetect = 0;
    for (int i = 0; i < 1000; i++) {
        if (digitalRead(nPin) == LOW) {
            ++nSoundDetect;
        }
        delay(1);
    }
    if (nSoundDetect > 0) {
        return HIGH;
    } else {
        return LOW;
    }
}
