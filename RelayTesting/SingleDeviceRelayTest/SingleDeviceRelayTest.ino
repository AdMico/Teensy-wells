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
//
// For V2 boards Word On = 16; Word Off (def) = 15; Bit On = 18; Bit Off (def) = 17 this is a correction for an issue in Nets D-W1, D-W2, D-B1 and D-B2 for this version.
// Problem is resolved on V2a+ boards, and the assignments 15 vs 16 and 17 vs 18 will be fixed in a future software update when V2a boards are made -- APM 19Nov26. 

int count = 5; // Number of times to switch the relay
int counter = 0;
int wait1 = 2; // Time relay coil is active
int wait2 = 100; // Time between on and off
int wait3 = 500; // Time before the next relay
bool hasRun = false;

void setup() {
  //Serial.begin(9600);
  // initialize the digital pins as outputs
  pinMode(1,OUTPUT); // W-EN1
  pinMode(2,OUTPUT); // W-EN2
  pinMode(3,OUTPUT); // W-A0
  pinMode(4,OUTPUT); // W-A1
  pinMode(5,OUTPUT); // W-A2
  pinMode(6,OUTPUT); // W-A3
  pinMode(7,OUTPUT); // B-EN1
  pinMode(8,OUTPUT); // B-EN2
  pinMode(9,OUTPUT); // B-A0
  pinMode(10,OUTPUT); // B-A1
  pinMode(11,OUTPUT); // B-A2
  pinMode(12,OUTPUT); // B-A3
  pinMode(15,OUTPUT); // Word Off (def) -- V2 board only, fix later APM 19NOV26
  pinMode(16,OUTPUT); // Word On -- V2 board only, fix later APM 19NOV26
  pinMode(17,OUTPUT); // Bit Off (def) -- V2 board only, fix later APM 19NOV26
  pinMode(18,OUTPUT); // Bit On -- V2 board only, fix later APM 19NOV26
}

void loop() {
  if (!hasRun)  {

    // Set all control bits to OFF
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,LOW);
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,LOW);

    //Serial.println("Word-1"); -- Adjust to which ever relay you need to test.
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,LOW);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    // Set all control bits to OFF
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,LOW);
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,LOW);

    counter++;

    if (counter >= count){
      hasRun = true;
    }
  }
}