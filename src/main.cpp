#include <Arduino.h>

const int buttonPin = 8;  // Pin voor de button om het terrein te betreden
const int buttonPin2 = 9; // Pin voor de button om het terrein te verlaten
const int ledPin = 4;     // PWM-compatibele pin voor de LED die moet faden
unsigned long peopleCount = 0; // Variabele om het aantal mensen bij te houden
const unsigned long debounceDelay = 200; // Debounce tijd in milliseconden

bool lastButtonState = HIGH;  // Vorige status van de button
bool lastButtonState2 = HIGH; // Vorige status van de button2

void setup() {
  // declare pin 9 to be an output:
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // Fade in from 0 to 255
  for (int brightness = 0; brightness <= 255; brightness += 5) {
    // set the brightness of pin 9 (PWM pin):
    analogWrite(ledPin, brightness);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // Fade out from 255 to 0
  for (int brightness = 255; brightness >= 0; brightness -= 5) {
    // set the brightness of pin 9 (PWM pin):
    analogWrite(ledPin, brightness);
    // wait for 40 milliseconds to see the dimming effect
    delay(40);
  }
}
