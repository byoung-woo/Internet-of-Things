#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h> // strerror()
#include <stdlib.h> // exit()

#include "dht11.h" // Include sensor control related header

int gnTemp = 0; // Declare temperature sensor data variable
int gnHumi = 0; // Declare humidity sensor data variable

int main(void) {
    // Initialize WiringPi GPIO library
    if (wiringPiSetupGpio() == -1) {
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }
    
    // Main loop for reading sensor data
    while (1) {
        delay(1000); // Delay for stability
        
        // Read data from DHT11 sensor
        readDht11(DHT_PIN);
        
        // Print temperature and humidity readings
        printf("Temperature: %d°C\n", gnTemp);
        printf("Humidity: %d%%\n", gnHumi);
    }
    
    return 0;
}
