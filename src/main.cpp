#include <Arduino.h>

int intVar;

void setup() {
    Serial.begin(9600); // Initialize serial port.
    for (intVar = 0; intVar <= 10; intVar++) { // Loop until intVar reaches 10
        Serial.print("binair getal voor intVar: "); // Add a colon after the message
        Serial.println(intVar, BIN); // Print the binary representation of intVar
        delay(1000); // Add a delay to slow down the loop
      
    }
}

void loop() {
    
}
