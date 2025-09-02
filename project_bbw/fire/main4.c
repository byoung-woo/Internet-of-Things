#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h> // strerror()
#include <stdlib.h> // exit()
#include "dht11.h" // Include sensor control related header
#include "adc.h"   // Include ADC control related header
#include "led.h"   // Include LED control related header

#define SOME_THRESHOLD 500

int gnTemp = 0; // Declare temperature sensor data variable
int gnHumi = 0; // Declare humidity sensor data variable

void blinkLed(int pin, int durationMs) {
    for (int i = 0; i < durationMs / 500; i++) {
        digitalWrite(pin, HIGH);
        delay(250);
        digitalWrite(pin, LOW);
        delay(250);
    }
}

int main(void) {
    // Initialize WiringPi GPIO library
    if (wiringPiSetupGpio() == -1) {
        fprintf(stdout, "Unable to start wiringPi GPIO: %s\n", strerror(errno));
        return 1;
    }

    // Initialize LEDs
    initLed();

    // Set LED pin 8 as output
    pinMode(8, OUTPUT);

    unsigned long startTime = 0;
    int alarmActive = 0;

    // Main loop for reading sensor data
    while (1) {
        delay(1000); // Delay for stability

        // Read data from DHT11 sensor
        readDht11(DHT_PIN);

        // Read data from gas sensor
        int gasValue = readSensor(GAS_PIN);

        // Print temperature, humidity, and gas sensor readings
        printf("Temperature: %d°C\n", gnTemp);
        printf("Humidity: %d%%\n", gnHumi);
        printf("Gas Value: %d\n", gasValue);

        // Check for alarm condition
        if (gnTemp > 100 && gasValue > SOME_THRESHOLD) {
            if (!alarmActive) {
                startTime = millis(); // Record the start time of the alarm
                alarmActive = 1;
            }

            // Blink LED 8
            blinkLed(8, 1000); // Blink for 1 second
        } else {
            alarmActive = 0;
            digitalWrite(8, LOW); // Turn off LED 8
        }

        // Stop alarm after 1 minute or if conditions are no longer met
        if (alarmActive && (millis() - startTime > 60000 || !(gnTemp > 100 && gasValue > SOME_THRESHOLD))) {
            alarmActive = 0;
            digitalWrite(8, LOW); // Turn off LED 8
        }
    }

    return 0;
}
