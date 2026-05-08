//
// Brought to Teensy-wells v1.0.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// Teensy 4.1 Test Program to change the on-board LED flash time
//

const int ledPin = LED_BUILTIN; // Pin 13
int blinkTime = 150; //blink time in milliseconds

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn LED on
  delay(blinkTime); // Wait
  digitalWrite(ledPin, LOW); // Turn LED off
  delay(blinkTime); // Wait
}
