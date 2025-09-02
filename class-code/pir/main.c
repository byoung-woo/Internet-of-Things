#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h> // strerror()
#include <stdlib.h> // exit()

#include "pir.h" // Include sensor control related header

int main(void) {
    // Initialize WiringPi GPIO library
    if (wiringPiSetupGpio() == -1) {
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }
    
    // Initialize PIR sensor
    initPir(PIR_PIN);
    
    // Main loop for reading sensor value
    while (1) {
        readPir(PIR_PIN); // Read sensor value
    }
    
    return 0;
}
