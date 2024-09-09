#include <Arduino.h>

void setup() {
    Serial.begin(9600); // Initialize serial port.

    // Verschillende datatypen
    int intVar = 42; // Voor het bijhouden van een leeftijd
    float floatVar = 3.14; // Voor het bijhouden van een pi-waarde
    double doubleVar = 3.1415926535; // Voor het bijhouden van een nauwkeurige pi-waarde
    char charVar = 'A'; // Voor het bijhouden van een enkel karakter
    bool boolVar = true; // Voor het bijhouden van een waar/onwaar waarde
    unsigned int unsignedIntVar = 100; // Voor het bijhouden van een positief getal
    long longVar = 1234567890; // Voor het bijhouden van een groot getal
    unsigned long unsignedLongVar = 1234567890; // Voor het bijhouden van een groot positief getal
    const int constVar = 10; // Voor het bijhouden van een constante waarde

    // Print de waarden naar de seriële monitor
    Serial.println("Voorbeelden van verschillende datatypen in Arduino:");
    Serial.print("int: "); Serial.println(intVar);
    Serial.print("float: "); Serial.println(floatVar);
    Serial.print("double: "); Serial.println(doubleVar);
    Serial.print("char: "); Serial.println(charVar);
    Serial.print("bool: "); Serial.println(boolVar);
    Serial.print("unsigned int: "); Serial.println(unsignedIntVar);
    Serial.print("long: "); Serial.println(longVar);
    Serial.print("unsigned long: "); Serial.println(unsignedLongVar);
    Serial.print("const int: "); Serial.println(constVar);

    // Voorbeeld van signed en unsigned
    signed int signedVar = -42; // Voor het bijhouden van een negatief getal
    unsigned int unsignedVar = 42; // Voor het bijhouden van een positief getal

    Serial.println("Voorbeelden van signed en unsigned:");
    Serial.print("signed int: "); Serial.println(signedVar);
    Serial.print("unsigned int: "); Serial.println(unsignedVar);
}

void loop() {
    // Niets te doen in de loop
}