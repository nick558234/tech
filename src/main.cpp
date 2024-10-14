#include <Arduino.h>
#include <Display.h>

const int lightSensorPin = A2;  
const int potPin = A1;          
const int muteButtonPin = 8;    
const int buzzerPin = 3;        
const int ledPinRed = 4;        
const int ledPinYellow = 7;     
const int ledPinGreen = 5;  
const int ledPinBlue = 6;    
const float R25 = 10000;        
const float B = 3950;           
const float temperatureFudgeFactor = 3.5;
bool isMuted = false;             
int lightThreshold;               

void setup() {
    pinMode(buzzerPin, OUTPUT);
    pinMode(ledPinRed, OUTPUT);
    pinMode(ledPinYellow, OUTPUT);
    pinMode(ledPinGreen, OUTPUT);
    pinMode(ledPinBlue, OUTPUT);
    pinMode(muteButtonPin, INPUT_PULLUP); 
    Serial.begin(9600);
}

void loop() {
    int lightLevel = analogRead(lightSensorPin);
    int potValue = analogRead(potPin); 
    lightThreshold = map(potValue, 0, 1023, 100, 800); // Map to a range

    // Read button state (toggle mute on button press)
    if (digitalRead(muteButtonPin) == LOW) {
        isMuted = !isMuted; // Toggle mute state
        delay(200); // Debounce delay
    }

    // Read temperature from NTC thermistor
    int analogValue = analogRead(A1); // Read thermistor
    float resistance = (1023.0 / analogValue - 1) * R25; // Calculate resistance
    float temperature = (1.0 / (log(resistance / R25) / B + 1 / 298.15)) - 273.15 - temperatureFudgeFactor; // Convert to Celsius

    // Print light level and temperature
    Serial.print("Lichtniveau: ");
    Serial.print(lightLevel);
    Serial.print(" | Temperatuur: ");
    Serial.println(temperature);
    
    // Debugging: Print mute status
    Serial.print("Muted: ");
    Serial.println(isMuted);

    // Handle LED and buzzer behavior based on mute state and temperature
    if (isMuted) {
        // When muted, turn off all other LEDs and buzzer, turn on blue LED
        noTone(buzzerPin);            // Turn off the buzzer
        digitalWrite(ledPinRed, LOW);  
        digitalWrite(ledPinYellow, LOW);
        digitalWrite(ledPinGreen, LOW); 
        digitalWrite(ledPinBlue, HIGH); 
    } else {
        // When not muted, control LEDs and buzzer based on temperature
        digitalWrite(ledPinBlue, LOW); // Turn off blue LED (since not muted)
        
        if (temperature > 20) { // Above 20°C, red LED and buzzer on
            tone(buzzerPin, 10);     // Activate buzzer
            digitalWrite(ledPinRed, HIGH);   
            digitalWrite(ledPinYellow, LOW); 
            digitalWrite(ledPinGreen, LOW);  
        } else if (temperature > 19.75) { // Between 19.75°C and 20°C, yellow LED
            noTone(buzzerPin);          
            digitalWrite(ledPinRed, LOW);     
            digitalWrite(ledPinYellow, HIGH); 
            digitalWrite(ledPinGreen, LOW);   
        } else { // Below 19.75°C, green LED
            noTone(buzzerPin);           
            digitalWrite(ledPinRed, LOW);    
            digitalWrite(ledPinYellow, LOW); 
            digitalWrite(ledPinGreen, HIGH); 
        }
    }
    
    Display.show(temperature); // Display temperature on your display

    delay(500); // Short delay before next loop iteration
}
