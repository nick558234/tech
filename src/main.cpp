#include <Arduino.h>
#include <Display.h>

const int buttonPin = 8; // Pin waar de button is verbonden
const int ledPin = 4;    // Pin waar de LED is verbonden


void setup() {
    // Initialiseer de seriële poort
    Serial.begin(9600);

    // Initialiseer de LED pin als output
    pinMode(ledPin, OUTPUT);

    // Initialiseer de button pin als input met pull-up weerstand
    pinMode(buttonPin, INPUT_PULLUP);

    // Initialiseer het display

    Display.show("Ready"); // Laat een startbericht zien
}

void loop() {
    // Lees de status van de button
    int buttonState = digitalRead(buttonPin);

    // Controleer of de button is ingedrukt
    if (buttonState == LOW) {
        // Button is ingedrukt, schakel de LED in en toon een bericht op het display
        digitalWrite(ledPin, HIGH);
        Display.show("pres");
    } else {
        // Button is niet ingedrukt, schakel de LED uit en toon een ander bericht op het display
        digitalWrite(ledPin, LOW);
        Display.show("not");
    }

    // Wacht een korte tijd om stuiteren van de button te voorkomen
    delay(50);
}