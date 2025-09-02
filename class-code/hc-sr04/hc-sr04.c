#include "hc-sr04.h" // Include sensor-related header file

float getDistance(int trigPin, int echoPin) { // Distance detection function
    float distance; // Distance variable
    int startTime, endTime; // Time variables

    // Generate 10us ultrasonic signal
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Wait for ultrasonic input signal
    while (digitalRead(echoPin) == LOW);

    // Record start time of ultrasonic signal reception
    startTime = micros();

    // Wait until the ultrasonic signal is received
    while (digitalRead(echoPin) == HIGH);

    // Record end time of ultrasonic signal reception
    endTime = micros();

    // Calculate distance
    distance = (endTime - startTime) / 29. / 2.;

    return distance; // Return distance
}

void initUltra(int trigPin, int echoPin) { // Sensor initialization function
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}
