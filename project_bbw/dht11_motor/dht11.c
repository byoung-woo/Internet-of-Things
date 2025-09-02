#include "dht11.h" // Include sensor-related header file

extern int gnTemp; // External declaration of global temperature variable
extern int gnHumi; // External declaration of global humidity variable

int readData(int nPin) { // Data read function
    unsigned char cnt = 7; // Initialize data receiving variables
    unsigned char idx = 0;
    int i;
    
    // Initialize buffer
    for (i = 0; i < 5; i++)
        bits[i] = 0;
    
    // Sample request
    pinMode(nPin, OUTPUT);
    digitalWrite(nPin, LOW);
    delay(20);
    digitalWrite(nPin, HIGH);
    delayMicroseconds(40);
    pinMode(nPin, INPUT);

    // Wait for ACK or timeout
    unsigned int loopCnt = TIMEOUT;
    while (digitalRead(nPin) == LOW) {
        if (loopCnt-- == 0) {
            return -2; // Timeout error
        }
    }
    loopCnt = TIMEOUT;
    while (digitalRead(nPin) == HIGH) {
        if (loopCnt-- == 0) {
            return -2; // Timeout error
        }
    }
    
    // Read sensor data
    for (i = 0; i < 40; i++) {
        // Wait for data transmission
        loopCnt = TIMEOUT;
        while (digitalRead(nPin) == LOW) {
            if (loopCnt-- == 0)
                return -2; // Timeout error
        }
        unsigned long t = micros();
        loopCnt = TIMEOUT;
        while (digitalRead(nPin) == HIGH) {
            if (loopCnt-- == 0)
                return -2; // Timeout error
        }
        // Parse received data
        if ((micros() - t) > 40) {
            bits[idx] |= (1 << cnt);
        }
        if (cnt == 0) {
            cnt = 7; // Reset count
            idx++;
        } else {
            cnt--;
        }
    }
    return 0;
}

int readDht11(int nPin) { // Sensor data read function
    int rv = readData(nPin); // Read sensor input data
    if (rv != 0)
        return rv; // Return sensor value
    gnHumi = bits[0]; // Parse humidity data
    gnTemp = bits[2]; // Parse temperature data
    return 0;
}
