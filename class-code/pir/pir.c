#include "pir.h" // Include sensor-related header file

int gnPirState = LOW; // Define motion sensor state variable

void initPir(int nPin) { // Sensor initialization function
    pinMode(nPin, INPUT); // Set sensor pin mode to input
}

int readPir(int nPin) { // Sensor reading function
    int nPirVal = 0; // Define sensor value variable
    
    nPirVal = digitalRead(nPin); // Read sensor value
    
    // Check if motion is detected
    if (nPirVal == HIGH) {
        if (gnPirState == LOW) { // Motion detected
            printf("Motion detected!\n");
            gnPirState = HIGH; // Update sensor state
        }
    } else {
        if (gnPirState == HIGH) { // Motion ended
            printf("Motion ended!\n");
            gnPirState = LOW; // Update sensor state
        }
    }
    
    return nPirVal; // Return sensor value
}
