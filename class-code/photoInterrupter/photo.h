#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>

#define PHOTO_INTERRUPTER_PIN 25

void initPhotoInterrupter(int nPin);

int readPhotoInterrupter(int nPin);