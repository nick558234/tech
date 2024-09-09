#include <Arduino.h>

int count = 0; // Variabele voor het tellen

void setup() {
    Serial.begin(9600); // Initialize serial port.
}

void loop() {
    // Verhoog de count variabele met 1 elke seconde
    count++;
    Serial.println(count);
    delay(1000); // Wacht 1 seconde
}