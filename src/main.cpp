#include <Arduino.h>

const int buttonPin = 8;  // Pin voor de button om het terrein te betreden
const int buttonPin2 = 9; // Pin voor de button om het terrein te verlaten
const int ledPins[] = {4, 5, 6, 7}; // Pinnen voor de LEDs
const int numLeds = 4; // Aantal LEDs
unsigned long peopleCount = 0; // Variabele om het aantal mensen bij te houden
const unsigned long debounceDelay = 200; // Debounce tijd in milliseconden

bool lastButtonState = HIGH;  // Vorige status van de button
bool lastButtonState2 = HIGH; // Vorige status van de button2

void setup() {
  // Initialiseer de seriële poort
  Serial.begin(9600);

  // Initialiseer de button pinnen als input met pull-up weerstand
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  
  // Initialiseer de LED pinnen als output
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Zet alle LEDs uit
  }

  // Print een startbericht naar de seriële monitor
  Serial.println("Festival lights");
}

void loop() {
  // Lees de status van de buttons
  bool buttonState = digitalRead(buttonPin);
  bool buttonState2 = digitalRead(buttonPin2);

  // LED fade logica voor elke LED
  for (int i = 0; i < numLeds; i++) {
    // Fade in from 0 to 255
    for (int brightness = 0; brightness <= 255; brightness += 5) {
      analogWrite(ledPins[i], brightness);
      delay(30); // wait for 30 milliseconds to see the dimming effect
    }

    // Fade out from 255 to 0
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
      analogWrite(ledPins[i], brightness);
      delay(30); // wait for 30 milliseconds to see the dimming effect
    }
  }
}