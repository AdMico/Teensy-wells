//
// Brought to Teensy-wells v1.1.0 on Wed Nov 18 2026 by APM
//
// @developers: Adam Micolich
//
// Basic algorithm for testing all 27 Bit relays only.
// It will cycle through bringing each relay one by one first to active, then back to hold (default)
// Has no interaction with PyNE-wells code, it's purely for hardware test, and should be used with the Teensy in the MuxBox PCB.
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

int count = 1; // Number of times to switch the relay set
int counter = 0;
int wait1 = 2; // Time relay coil is active
int wait2 = 100; // Time between on and off
int wait3 = 500; // Time before the next relay
bool hasRun = false;

void setup() {
  //Serial.begin(9600);
  // initialize the digital pins as outputs
  pinMode(7,OUTPUT); // B-EN1
  pinMode(8,OUTPUT); // B-EN2
  pinMode(9,OUTPUT); // B-A0
  pinMode(10,OUTPUT); // B-A1
  pinMode(11,OUTPUT); // B-A2
  pinMode(12,OUTPUT); // B-A3
  pinMode(17,OUTPUT); // Bit Off (def) -- V2 board only, fix later APM 19NOV26
  pinMode(18,OUTPUT); // Bit On -- V2 board only, fix later APM 19NOV26
}

void loop() {
  if (!hasRun)  {

    // Set all control bits to OFF
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,LOW);
    digitalWriteFast(17,LOW);
    digitalWriteFast(18,LOW);
    
    //Serial.println("B-1");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-2");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-3");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,HIGH);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-4");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,HIGH);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-5");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,HIGH);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-6");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,HIGH);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-7");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,HIGH);
    digitalWriteFast(11,HIGH);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-8");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,HIGH);
    digitalWriteFast(11,HIGH);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-9");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,HIGH);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-10");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,HIGH);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-11");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,HIGH);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,HIGH);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-12");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,HIGH);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,HIGH);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-13");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,HIGH);
    digitalWriteFast(12,HIGH);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-14");
    digitalWriteFast(7,HIGH);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,HIGH);
    digitalWriteFast(12,HIGH);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-15");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-16");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-17");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,HIGH);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-18");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,HIGH);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-19");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,HIGH);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-20");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,HIGH);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-21");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,HIGH);
    digitalWriteFast(11,HIGH);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-22");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,HIGH);
    digitalWriteFast(11,HIGH);
    digitalWriteFast(12,LOW);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-23");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,HIGH);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-24");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,HIGH);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-25");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,HIGH);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,HIGH);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-26");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,HIGH);
    digitalWriteFast(10,HIGH);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,HIGH);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-27");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,HIGH);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,HIGH);
    digitalWriteFast(12,HIGH);
    digitalWriteFast(18,HIGH);
    delay(wait1);
    digitalWriteFast(18,LOW);
    delay(wait2);
    digitalWriteFast(17,HIGH);
    delay(wait1);
    digitalWriteFast(17,LOW);
    delay(wait3);

    //Serial.println("B-Deactivate");
    digitalWriteFast(7,LOW);
    digitalWriteFast(8,LOW);
    digitalWriteFast(9,LOW);
    digitalWriteFast(10,LOW);
    digitalWriteFast(11,LOW);
    digitalWriteFast(12,LOW);
    digitalWriteFast(17,LOW);
    digitalWriteFast(18,LOW);

    counter++;
    delay(3000); // wait 3 seconds between sets

    if (counter >= count){
      hasRun = true;
    }  
  }
}