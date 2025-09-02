#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h> // Include WiringPi GPIO library

#define PIR_PIN 27 // Define GPIO pin for PIR sensor

// Function prototypes
void initPir(int nPin); // Initialize PIR sensor
int readPir(int nPin); // Read PIR sensor