//
// Brought to Teensy-wells v1.0.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// Basic algorithm for testing one specific control relay.
// It will flip the relay to NO, pause, then flip the relay to NC (default).
// Has no interaction with PyNE-wells code, it's purely for hardware test, and should be used with the Teensy in the MuxBox.
//
// APM 08MAY26 -- Need to fix GPIO map in future instance when I fix the BC847 issue on the MuxBox PCB.

// GPIO Mapping for V1 of Gen6 box
// Bias Words (def) = 13; Bias Bits = 14; Word On = 15; Word Off (def) = 16; Bit On = 17; Bit Off (def) = 18; +5V GND (def) = 19; +5V Active = 20;
// Source Int (def) = 21; Source Ext = 22; Drain Int (def) = 23; Drain Ext = 24; Hold Int (def) = 25; Hold Ext = 26; Gate Int (def) = 27; Gate Ext = 28;
// V1-Inv (def) = 29; V1-NonInv = 30; V2-Inv (def) = 31; V2-NonInv = 32; I1-Lo (def) = 33; I1-Hi = 34; I2-Lo (def) = 35; I2-Hi = 36;
// I1-TIA (def) = 37, I1-CSA = 38, I2-TIA (def) = 39; I2-CSA = 40.
//
// GPIO Mapping as designed for Gen6 Box (will end up here on V2 boards)
// Bias Bits = 13; Bias Words (def) = 14; Word Off (def) = 15; Word On = 16; Bit Off (def) = 17; Bit On = 18; +5V Active = 19; +5V GND (def) = 20;
// Source Ext = 21; Source Int (def) = 22; Drain Ext = 23; Drain Int (def) = 24; Hold Ext = 25; Hold Int (def) = 26; Gate Ext = 27; Gate Int (def) = 28;
// V1-NonInv = 29; V1-Inv (def) = 30; V2-NonInv = 31; V2-Inv (def) = 32; I1-Hi = 33; I1-Lo (def) = 34; I2-Hi = 35; I2-Lo (def) = 36;
// I1-CSA = 37; I1-TIA (def) = 38; I2-CSA = 39; I2-TIA (def) = 40.

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
  pinMode(15,OUTPUT); // Word On
  pinMode(16,OUTPUT); // Word Off (def)
  pinMode(17,OUTPUT); // Bit On
  pinMode(18,OUTPUT); // Bit Off (def)
  pinMode(20,OUTPUT); // +5V Active
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

    // Make sure the 5V power line is active, otherwise the other relays won't switch.
    //Serial.println("+5V Active");
    digitalWriteFast(20,HIGH);
    delay(wait1);
    digitalWriteFast(20,LOW);
    delay(wait3);

    //Serial.println("Word-1"); -- Adjust to which ever relay you need to test.
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,LOW);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
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