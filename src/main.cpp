#include <Arduino.h>
#include <limits.h>
#include <float.h>

void setup() {
    Serial.begin(9600); // Initialize serial port.

    // Verschillende datatypen en hun grenzen
    int intVar = 42;
    float floatVar = 3.14;
    double doubleVar = 3.1415926535;
    char charVar = 'A';
    bool boolVar = true;
    unsigned int unsignedIntVar = 100;
    long longVar = 1234567890;
    unsigned long unsignedLongVar = 1234567890;
    const int constVar = 10;

    // Print de grenzen van verschillende datatypen naar de seriële monitor
    Serial.println("Grenzen van verschillende datatypen in Arduino:");
    Serial.print("int: "); Serial.print(INT_MIN); Serial.print(" tot "); Serial.println(INT_MAX);
    Serial.print("float: "); Serial.print(FLT_MIN); Serial.print(" tot "); Serial.println(FLT_MAX);
    Serial.print("double: "); Serial.print(DBL_MIN); Serial.print(" tot "); Serial.println(DBL_MAX);
    Serial.print("char: "); Serial.print(CHAR_MIN); Serial.print(" tot "); Serial.println(CHAR_MAX);
    Serial.print("bool: "); Serial.print("0 tot 1"); Serial.println();
    Serial.print("unsigned int: "); Serial.print("0 tot "); Serial.println(UINT_MAX);
    Serial.print("long: "); Serial.print(LONG_MIN); Serial.print(" tot "); Serial.println(LONG_MAX);
    Serial.print("unsigned long: "); Serial.print("0 tot "); Serial.println(ULONG_MAX);
    Serial.print("const int: "); Serial.print("Constante waarde: "); Serial.println(constVar);

    // Voorbeeld van signed en unsigned
    signed int signedVar = -42;
    unsigned int unsignedVar = 42;

    Serial.println("Voorbeelden van signed en unsigned:");
    Serial.print("signed int: "); Serial.print(INT_MIN); Serial.print(" tot "); Serial.println(INT_MAX);
    Serial.print("unsigned int: "); Serial.print("0 tot "); Serial.println(UINT_MAX);

    // Probeer een waarde op te slaan die te groot is
    int overflowInt = INT_MAX + 1;
    unsigned int overflowUnsignedInt = UINT_MAX + 1;

    Serial.println("Voorbeelden van overflow:");
    Serial.print("int overflow: "); Serial.println(overflowInt);
    Serial.print("unsigned int overflow: "); Serial.println(overflowUnsignedInt);

    // Print het aantal bits voor elk datatype
    Serial.println("Aantal bits voor elk datatype:");
    Serial.print("int: "); Serial.print(sizeof(int) * 8); Serial.println(" bits");
    Serial.print("float: "); Serial.print(sizeof(float) * 8); Serial.println(" bits");
    Serial.print("double: "); Serial.print(sizeof(double) * 8); Serial.println(" bits");
    Serial.print("char: "); Serial.print(sizeof(char) * 8); Serial.println(" bits");
    Serial.print("bool: "); Serial.print(sizeof(bool) * 8); Serial.println(" bits");
    Serial.print("unsigned int: "); Serial.print(sizeof(unsigned int) * 8); Serial.println(" bits");
    Serial.print("long: "); Serial.print(sizeof(long) * 8); Serial.println(" bits");
    Serial.print("unsigned long: "); Serial.print(sizeof(unsigned long) * 8); Serial.println(" bits");
}

void loop() {
    // Niets te doen in de loop
}