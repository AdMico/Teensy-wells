//
// Brought to Teensy-wells v1.1.0 on Tue Nov 17 2026 by APM
//
// @developers: Adam Micolich
//
// Basic algorithm for testing one specific control relay.
// It will flip the relay to NO, pause, then flip the relay to NC (default).
// Has no interaction with PyNE-wells code, it's purely for hardware test, and should be used with the Teensy in the MuxBox.
//
// GPIO Mapping for Gen6 Box (V2+)
// W-EN1 = 1; W-EN2 = 2; W-A0 = 3; W-A1 = 4; W-A2 = 5; W-A3 = 6; B-EN1 = 7; B-EN2 = 8; B-A0 = 9; B-A1 = 10; B-A2 = 11; B-A3 = 12; 
// Bias Bits = 13; Bias Words (def) = 14; Word On = 15; Word Off (def) = 16; Bit On = 17; Bit Off (def) = 18; Gate TIA = 19; Hold TIA (def) = 20;
// Source Ext = 21; Source Int (def) = 22; Drain Ext = 23; Drain Int (def) = 24; Hold Ext = 25; Hold Int (def) = 26; Gate Ext = 27; Gate Int (def) = 28;
// V1-Pos = 29; V1-Neg (def) = 30; V2-Pos = 31; V2-Neg (def) = 32; I1-Hi = 33; I1-Lo (def) = 34; I2-Hi = 35; I2-Lo (def) = 36;
// I1-CSA = 37; I1-TIA (def) = 38; I2-CSA = 39; I2-TIA (def) = 40.

int led1Pin = 25; // Hold Ext
int led2Pin = 26; // Hold Int (def)
int wait1 = 100; // time in milliseconds
int wait2 = 100; // time in milliseconds
int wait3 = 500; //time in milliseconds
int count = 5; // Number of times to switch the relay
int counter = 0;
bool hasRun = false;

void setup() {
  //Serial.begin(9600);
  // initialize the digital pins as outputs
  pinMode(led1Pin,OUTPUT);
  pinMode(led2Pin,OUTPUT);
}

void loop() {
  if (!hasRun)  {

    delay(1000);

    //Serial.println("Relay to NO");
    digitalWriteFast(led1Pin,HIGH);
    delay(wait1);
    digitalWriteFast(led1Pin,LOW);
    delay(wait2);

    //Serial.println("Relay to NC");
    digitalWriteFast(led2Pin,HIGH);
    delay(wait1);
    digitalWriteFast(led2Pin,LOW);
    delay(wait3);

    counter++;

    if (counter >= count){
      hasRun = true;
    }
  }
}