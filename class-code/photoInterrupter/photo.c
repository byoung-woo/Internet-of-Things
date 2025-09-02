#include "photo.h"

void initPhotoInterrupter(int nPin) {
    pinMode(nPin, INPUT);
}

int readPhotoInterrupter(int nPin) {
    int nPhotolIntVal = 0;
    int nPhotoIntVal = digitalRead(nPin);
    return nPhotoIntVal;
}
