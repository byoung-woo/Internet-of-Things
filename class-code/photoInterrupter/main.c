#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "photo.h"

int main(void) {
    int nPhoto = 0;
    if (wiringPiSetupGpio() == -1) {
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    } 
    initPhotoInterrupter(PHOTO_INTERRUPTER_PIN);
    while (1) {
        delay(1000);
        nPhoto = readPhotoInterrupter(PHOTO_INTERRUPTER_PIN);
        if (nPhoto == 1) {
            printf("Detected!\n");
        }
    }
    return 0;
}
