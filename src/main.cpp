#include <Arduino.h>
#include <Display.h>

const int buttonPin = 8;
const int buttonPin2 = 9;
const int ledPin = 4;
const int ledPin2 = 6;
int count = 3;
int count2 = 5;
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
const unsigned long debounceDelay = 50;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  Display.show("Ready");
}

void turnLedOn()
{
  digitalWrite(ledPin, HIGH);
  Display.show("pres");
  delay(400);
  digitalWrite(ledPin, LOW);
  Display.show("off");
  delay(400);
}

void turnLed2On()
{
  digitalWrite(ledPin2, HIGH);
  Display.show("pres");
  delay(400);
  digitalWrite(ledPin2, LOW);
  Display.show("off");
  delay(400);
}

void turnbothLedOn()
{
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, HIGH);
  Display.show("pres");
  delay(400);
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, LOW);
  Display.show("off");
  delay(400);
}

bool buttonRead(int pin, unsigned long &lastDebounceTime)
{
  int reading = digitalRead(pin);
  if (reading == LOW)
  {
    if ((millis() - lastDebounceTime) > debounceDelay)
    {
      lastDebounceTime = millis();
      return true;
    }
  }
  return false;
}

void loop()
{
  if (buttonRead(buttonPin, lastDebounceTime1) && buttonRead(buttonPin2, lastDebounceTime2))
  {
    for (int i = 0; i < count2; i++)
    {
      turnbothLedOn();
    }
  }
  else if (buttonRead(buttonPin, lastDebounceTime1))
  {
    for (int i = 0; i < count; i++)
    {
      turnLedOn();
    }
  }
  else if (buttonRead(buttonPin2, lastDebounceTime2))
  {
    for (int i = 0; i < count; i++)
    {
      turnLed2On();
    }
  }
}