//
// Brought to Teensy-wells v1.0.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// Basic algorithm for testing all 27 Word relays only.
// It will cycle through bringing each relay one by one first to active, then back to hold (default)
// Has no interaction with PyNE-wells code, it's purely for hardware test, and should be used with the Teensy in the MuxBox PCB.
//
// APM 08MAY26 -- Need to fix GPIO map in future instance when I fix the BC847 issue on the MuxBox PCB.

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

int count = 1; // Number of times to switch the relay set
int counter = 0;
int wait1 = 100; // Time relay coil is active
int wait2 = 100; // Time between on and off
int wait3 = 1000; // Time before the next relay
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
  pinMode(15,OUTPUT); // Word Off (def)
  pinMode(16,OUTPUT); // Word On
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
    digitalWriteFast(15,LOW);
    digitalWriteFast(16,LOW);
    
    // Make sure the 5V power line is active, otherwise the other relays won't switch.
    //Serial.println("+5V Active");
    digitalWriteFast(20,HIGH);
    delay(wait1);
    digitalWriteFast(20,LOW);
    delay(wait3);

    //Serial.println("W-1");
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

    //Serial.println("W-2");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
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

    //Serial.println("W-3");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,HIGH);
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

    //Serial.println("W-4");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,HIGH);
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

    //Serial.println("W-5");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-6");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-7");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-8");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-9");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-10");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-11");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-12");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-13");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-14");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-15");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
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

    //Serial.println("W-16");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,HIGH);
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

    //Serial.println("W-17");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,HIGH);
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

    //Serial.println("W-18");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,HIGH);
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

    //Serial.println("W-19");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-20");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-21");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-22");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-23");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-24");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-25");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-26");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-27");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait2);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait3);

    //Serial.println("W-Deactivate");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,LOW);
    digitalWriteFast(16,LOW);
    digitalWriteFast(15,LOW);

    counter++;
    delay(3000); // wait 3 seconds between sets

    if (counter >= count){
      hasRun = true;
    }  
  }
}