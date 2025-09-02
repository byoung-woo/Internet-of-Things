#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>

#define SOUND_PIN 18

void initSound(int nPin);
int readSound(int nPin);
