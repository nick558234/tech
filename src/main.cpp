#include <Arduino.h>
#include <Display.h>

const int buttonPin = 8;  // Pin waar de button is verbonden
const int buttonPin2 = 9; // Pin waar de button is verbonden
const int ledPin = 4;     // Pin waar de LED is verbonden
const int ledPin2 = 6;    // Pin waar de LED is verbonden
int count = 3;
void setup()
{
  // Initialiseer de seriële poort
  Serial.begin(9600);

  // Initialiseer de LED pin als output
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // Initialiseer de button pin als input met pull-up weerstand
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

  // Initialiseer het display
  Display.show("Ready"); // Laat een startbericht zien
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

void loop()
{
  // Lees de status van de button
  int buttonState = digitalRead(buttonPin);
  int buttonState2 = digitalRead(buttonPin2);

  // Controleer of de button is ingedrukt
  if (buttonState == LOW)
  {
    for (int i = 0; i < count; i++)
    {
      turnLedOn();
    }
  }
  else if (buttonState2 == LOW)
  {
    for (int i = 0; i < count; i++)
    {
      turnLed2On();
    }
  }

  // Wacht een korte tijd om stuiteren van de button te voorkomen
  delay(50);
}