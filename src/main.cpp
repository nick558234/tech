#include <Arduino.h>
#include <Display.h>

const int buttonPin = 8;                 // Pin waar de button is verbonden
const int buttonPin2 = 9;                // Pin waar de button is verbonden
const int ledPin = 4;                   // Pin voor het rode lampje (LED)
unsigned int peopleCount = 0;            // Variabele om het aantal mensen bij te houden
const unsigned int maxPeople = 5;        // Het maximale aantal mensen
const unsigned long debounceDelay = 200; // Debounce tijd in milliseconden

bool lastButtonState = HIGH;  // Vorige status van de button
bool lastButtonState2 = HIGH; // Vorige status van de button2

void setup()
{
    // Initialiseer de seriële poort
    Serial.begin(9600);

    // Initialiseer de button pinnen als input met pull-up weerstand
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);

    // Initialiseer de ledPin als output
    pinMode(ledPin, OUTPUT);

    // Zet het LED uit (initiale staat)
    digitalWrite(ledPin, LOW);

    // Print een startbericht naar de seriële monitor
    Serial.println("Festival People Counter Initialized");
}

void loop()
{
    // Lees de status van de buttons
    bool buttonState = digitalRead(buttonPin);
    bool buttonState2 = digitalRead(buttonPin2);

    // Controleer of de button is ingedrukt (LOW) en de status is veranderd
    if (buttonState == LOW && lastButtonState == HIGH)
    {
        // Verhoog de mensen teller
        peopleCount++;

        // Print het aantal mensen naar de seriële monitor
        Serial.print("Person entered at: ");
        Serial.print(millis() / 1000); // Tijd in seconden
        Serial.print(" seconds. Total people: ");
        Serial.println(peopleCount);

        // Controleer of het maximale aantal mensen is bereikt
        if (peopleCount >= maxPeople)
        {
            Serial.println("Max people reached! Blinking red LED...");

            // Rood lampje 3 keer laten knipperen
            int blinkCount = 0;
            while (blinkCount < 3)
            {
                digitalWrite(ledPin, HIGH); // Zet het LED aan
                delay(500);                 // Wacht 500 milliseconden
                digitalWrite(ledPin, LOW);  // Zet het LED uit
                delay(500);                 // Wacht 500 milliseconden
                blinkCount++;
            }
        }

        // Wacht een korte tijd om stuiteren van de button te voorkomen
        delay(debounceDelay);
    }

    // Controleer of de button2 is ingedrukt (LOW) en de status is veranderd
    if (buttonState2 == LOW && lastButtonState2 == HIGH)
    {
        // Verlaag de mensen teller alleen als het aantal mensen groter is dan 0
        if (peopleCount > 0)
        {
            peopleCount--;

            // Print het aantal mensen naar de seriële monitor
            Serial.print("Person left at: ");
            Serial.print(millis() / 1000); // Tijd in seconden
            Serial.print(" seconds. Total people: ");
            Serial.println(peopleCount);

            // Wacht een korte tijd om stuiteren van de button te voorkomen
            delay(debounceDelay);
        }
    }

    // Toon het aantal mensen op het display
    Display.show((int)(peopleCount)); // Converteer peopleCount naar int voor weergave

    // Update de laatste button status
    lastButtonState = buttonState;
    lastButtonState2 = buttonState2;
}
