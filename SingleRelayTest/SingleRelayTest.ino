//
// Brought to Teensy-wells v1.0.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// Basic algorithm for testing one specific control relays.
// It will flip the relay to NO, pause, then flip the relay to NC (default).
// Has no interaction with PyNE-wells code, it's purely for hardware test, and should be used with the Teensy in the MuxBox.
//

int led1Pin = 27; // Gate Ext
int led2Pin = 28; // Gate Int (def)

// Bias Bits = 13; Bias Words (def) = 14; Word On = 15; Word Off (def) = 16; Bit On = 17; Bit Off (def) = 18; +5V Active = 19; +5V GND (def) = 20;
// Source Ext = 21; Source Int (def) = 22; Drain Ext = 23; Drain Int (def) = 24; Hold Ext = 25; Hold Int (def) = 26; Gate Ext = 27; Gate Int (def) = 28;
// V1-NonInv = 29; V1-Inv (def) = 30; V2-NonInv = 31; V2-Inv (def) = 32; I1-Hi = 33; I1-Lo (def) = 34; I2-Hi = 35; I2-Lo (def) = 36;
// I1-CSA = 37; I1-TIA (def) = 38; I2-CSA = 39; I2-TIA (def) = 40.

int wait1 = 10;
int wait2 = 500;
bool hasRun = false;

void setup() {
  Serial.begin(9600);
  // initialize the digital pins as outputs
  pinMode(led1Pin,OUTPUT);
  pinMode(led2Pin,OUTPUT);
}

void loop() {
  if (!hasRun)  {
    Serial.println("Relay to NO");
    digitalWrite(led1Pin,HIGH);
    delay(wait1);
    digitalWrite(led1Pin,LOW);
    delay(wait2);

    Serial.println("Relay to NC");
    digitalWrite(led2Pin,HIGH);
    delay(wait1);
    digitalWrite(led2Pin,LOW);
    delay(wait2);

    hasRun = true;  
  }
}