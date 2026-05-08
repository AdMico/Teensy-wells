//
// Brought to Teensy-wells v1.0.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// Basic algorithm for testing one specific control relays.
// It will flip the relay to NO, pause, then flip the relay to NC (default).
// Has no interaction with PyNE-wells code, it's purely for hardware test, and should be used with the Teensy in the MuxBox.
//
// APM 08MAY26 -- Need to fix GPIO map in future instance when I fix the BC847 issue on the MuxBox PCB.

int led1Pin = 21; // Gate Ext
int led2Pin = 22; // Gate Int (def)

// GPIO Mapping for V1 of Gen6 box
// Bias Words (def) = 13; Bias Bits = 14; Word Off (def) = 15; Word On = 16; Bit Off (def) = 17; Bit On = 18; +5V GND (def) = 19; +5V Active = 20;
// Source Int (def) = 21; Source Ext = 22; Drain Int (def) = 23; Drain Ext = 24; Hold Int (def) = 25; Hold Ext = 26; Gate Int (def) = 27; Gate Ext = 28;
// V1-Inv (def) = 29; V1-NonInv = 30; V2-Inv (def) = 31; V2-NonInv = 32; I1-Lo (def) = 33; I1-Hi = 34; I2-Lo (def) = 35; I2-Hi = 36;
// I1-TIA (def) = 37, I1-CSA = 38, I2-TIA (def) = 39; I2-CSA = 40.
//
// GPIO Mapping as designed for Gen6 Box (will end up here on V2 boards)
// Bias Bits = 13; Bias Words (def) = 14; Word On = 15; Word Off (def) = 16; Bit On = 17; Bit Off (def) = 18; +5V Active = 19; +5V GND (def) = 20;
// Source Ext = 21; Source Int (def) = 22; Drain Ext = 23; Drain Int (def) = 24; Hold Ext = 25; Hold Int (def) = 26; Gate Ext = 27; Gate Int (def) = 28;
// V1-NonInv = 29; V1-Inv (def) = 30; V2-NonInv = 31; V2-Inv (def) = 32; I1-Hi = 33; I1-Lo (def) = 34; I2-Hi = 35; I2-Lo (def) = 36;
// I1-CSA = 37; I1-TIA (def) = 38; I2-CSA = 39; I2-TIA (def) = 40.

int wait1 = 500;
int wait2 = 1500;
int count = 3; // Number of times to switch the relay
int counter = 0;
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

    counter++;

    if (counter >= count){
      hasRun = true;
    }
  }
}