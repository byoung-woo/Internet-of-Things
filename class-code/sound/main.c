#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "sound.h"

int main(void) {
    if (wiringPiSetupGpio() == -1) {
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }
    
    initSound(SOUND_PIN);
    
    while (1) {
        delay(10);
        if (readSound(SOUND_PIN)) {
            printf("Sound detected.\n");
        }
    }
    
    return 0;
}
