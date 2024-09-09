#include <Arduino.h>

void setup() {
    Serial.begin(9600); // Initialize serial port.

    // Verschillende datatypes en hun waarden
    int intVar = 42;
    float floatVar = 3.0;
    double doubleVar = 3.0;
    char charVar = 'A';
    bool boolVar = true;
    unsigned int unsignedIntVar = 42;
    long longVar = 42;
    unsigned long unsignedLongVar = 42;

    // Print de binaire representatie van de waarden naar de seriële monitor
    Serial.println("Binaire representatie van verschillende datatypes in Arduino:");
    Serial.print("int: "); Serial.println(intVar, BIN);
    Serial.print("float: "); Serial.println(*(unsigned long*)&floatVar, BIN); // Cast float to unsigned long for binary representation
    Serial.print("double: "); 
    unsigned long* doublePtr = (unsigned long*)&doubleVar;
    Serial.print(doublePtr[1], BIN); // Print the first 32 bits
    Serial.print(" "); 
    Serial.println(doublePtr[0], BIN); // Print the second 32 bits
    Serial.print("char: "); Serial.println(charVar, BIN);
    Serial.print("bool: "); Serial.println(boolVar, BIN);
    Serial.print("unsigned int: "); Serial.println(unsignedIntVar, BIN);
    Serial.print("long: "); Serial.println(longVar, BIN);
    Serial.print("unsigned long: "); Serial.println(unsignedLongVar, BIN);
}

void loop() {
    // Nothing to do in the loop
}