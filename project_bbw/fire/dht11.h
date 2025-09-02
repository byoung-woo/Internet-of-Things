#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <wiringPi.h> // Include WiringPi library

#define DHT_PIN 26   // Define GPIO pin for DHT11 sensor
#define TIMEOUT 10000 // Timeout for sensor reading

#define TEMP 0 // Index for temperature data in bits array
#define HUMI 1 // Index for humidity data in bits array

unsigned char bits[5]; // Data buffer for sensor reading

// Function prototypes
int readData(int pin);
int readDht11(int pin);