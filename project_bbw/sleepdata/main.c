#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h> // strerror()
#include <stdlib.h> // exit()

#include "hc-sr04.h" // Include sensor control related header

float gfDistance = 0.0; // Declare sensor data variable

int main(void) {
    if (wiringPiSetupGpio() == -1) { // Apply wiringPi GPIO library
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }

    initUltra(TP_PIN, EP_PIN); // Initialize sensor
    
    while (1) {
        delay(1000);
        gfDistance = getDistance(TP_PIN, EP_PIN); // Read sensor value
        
        if (gfDistance <= 500) {
            printf("Distance: %.2f(cm)\n", gfDistance);
        }
    }
    
    return 0;
}
