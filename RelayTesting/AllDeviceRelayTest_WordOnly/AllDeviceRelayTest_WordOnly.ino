//
// Brought to Teensy-wells v1.1.0 on Wed Nov 18 2026 by APM
//
// @developers: Adam Micolich
//
// Basic algorithm for testing all 27 Word relays only.
// It will cycle through bringing each relay one by one first to active, then back to hold (default)
// Has no interaction with PyNE-wells code, it's purely for hardware test, and should be used with the Teensy in the MuxBox PCB.
//
// GPIO Mapping for Gen6 Box (V2+)
// W-EN1 = 1; W-EN2 = 2; W-A0 = 3; W-A1 = 4; W-A2 = 5; W-A3 = 6; B-EN1 = 7; B-EN2 = 8; B-A0 = 9; B-A1 = 10; B-A2 = 11; B-A3 = 12; 
// Bias Bits = 13; Bias Words (def) = 14; Word On = 15; Word Off (def) = 16; Bit On = 17; Bit Off (def) = 18; Gate TIA = 19; Hold TIA (def) = 20;
// Source Ext = 21; Source Int (def) = 22; Drain Ext = 23; Drain Int (def) = 24; Hold Ext = 25; Hold Int (def) = 26; Gate Ext = 27; Gate Int (def) = 28;
// V1-Pos = 29; V1-Neg (def) = 30; V2-Pos = 31; V2-Neg (def) = 32; I1-Hi = 33; I1-Lo (def) = 34; I2-Hi = 35; I2-Lo (def) = 36;
// I1-CSA = 37; I1-TIA (def) = 38; I2-CSA = 39; I2-TIA (def) = 40.

int count = 1; // Number of times to switch the relay set
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
  pinMode(15,OUTPUT); // Word On
  pinMode(16,OUTPUT); // Word Off (def)
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
    
    //Serial.println("W-1");
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

    //Serial.println("W-2");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
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

    //Serial.println("W-3");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,HIGH);
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

    //Serial.println("W-4");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,HIGH);
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

    //Serial.println("W-5");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-6");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-7");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-8");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-9");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-10");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-11");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-12");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-13");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-14");
    digitalWriteFast(1,HIGH);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-15");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
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

    //Serial.println("W-16");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,HIGH);
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

    //Serial.println("W-17");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,HIGH);
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

    //Serial.println("W-18");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,HIGH);
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

    //Serial.println("W-19");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-20");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-21");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-22");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,LOW);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-23");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-24");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-25");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-26");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,HIGH);
    digitalWriteFast(4,HIGH);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-27");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,HIGH);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,HIGH);
    digitalWriteFast(6,HIGH);
    digitalWriteFast(15,HIGH);
    delay(wait1);
    digitalWriteFast(15,LOW);
    delay(wait2);
    digitalWriteFast(16,HIGH);
    delay(wait1);
    digitalWriteFast(16,LOW);
    delay(wait3);

    //Serial.println("W-Deactivate");
    digitalWriteFast(1,LOW);
    digitalWriteFast(2,LOW);
    digitalWriteFast(3,LOW);
    digitalWriteFast(4,LOW);
    digitalWriteFast(5,LOW);
    digitalWriteFast(6,LOW);
    digitalWriteFast(15,LOW);
    digitalWriteFast(16,LOW);

    counter++;
    delay(3000); // wait 3 seconds between sets

    if (counter >= count){
      hasRun = true;
    }  
  }
}