#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>

// Define GPIO pins for ultrasonic sensor
#define TRIG_PIN 12
#define ECHO_PIN 16

// Function prototypes
void initUltra(int trigPin, int echoPin); // Initialize ultrasonic sensor
float getDistance(int trigPin, int echoPin); // Measure distance