//
// Brought to Teensy-wells v1.0.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// Basic algorithm for testing all 16 control relays.
// It will cycle through bringing each relay one by one first to NO, then back to NC (default)
// Has no interaction with PyNE-wells code, it's purely for hardware test, and should be used with the Teensy in the MuxBox PCB.
//
// Note: You will only hear 12 relay rollovers because one GPIO pair has six relays on it rather than only two.
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
int wait1 = 2; // Time relay coil is active
int wait2 = 100; // Time between on and off
int wait3 = 500; // Time before the next relay
bool hasRun = false;

void setup() {
  //Serial.begin(9600);
  // initialize the digital pins as outputs
  pinMode(13,OUTPUT); // Bias Words (def)
  pinMode(14,OUTPUT); // Bias Bits
  pinMode(19,OUTPUT); // +5V GND (def)
  pinMode(20,OUTPUT); // +5V Active
  pinMode(21,OUTPUT); // Source Int (def)
  pinMode(22,OUTPUT); // Source Ext
  pinMode(23,OUTPUT); // Drain Int (def)
  pinMode(24,OUTPUT); // Drain Ext
  pinMode(25,OUTPUT); // Hold Int (def)
  pinMode(26,OUTPUT); // Hold Ext
  pinMode(27,OUTPUT); // Gate Int (def)
  pinMode(28,OUTPUT); // Gate Ext
  pinMode(29,OUTPUT); // V1-Inv (def)
  pinMode(30,OUTPUT); // V1-NonInv
  pinMode(31,OUTPUT); // V2-Inv (def)
  pinMode(32,OUTPUT); // V2-NonInv
  pinMode(33,OUTPUT); // I1-Lo (def)
  pinMode(34,OUTPUT); // I1-Hi
  pinMode(35,OUTPUT); // I2-Lo (def)
  pinMode(36,OUTPUT); // I2-Hi
  pinMode(37,OUTPUT); // I1-TIA (def)
  pinMode(38,OUTPUT); // I1-CSA
  pinMode(39,OUTPUT); // I2-TIA (def)
  pinMode(40,OUTPUT); // I2-CSA
}

void loop() {
  if (!hasRun)  {

    // Make sure the 5V power line is active, otherwise the other relays won't switch.
    //Serial.println("+5V Active");
    digitalWriteFast(20,HIGH);
    delay(wait1);
    digitalWriteFast(20,LOW);
    delay(wait3);

    //Serial.println("Bias Bits");
    digitalWriteFast(14,HIGH);
    delay(wait1);
    digitalWriteFast(14,LOW);
    delay(wait2);
    //Serial.println("Bias Words (def)");
    digitalWriteFast(13,HIGH);
    delay(wait1);
    digitalWriteFast(13,LOW);
    delay(wait3);

    // Run these two reversed to ensure that all following relay tests run
    //Serial.println("+5V GND (def)");
    digitalWriteFast(19,HIGH);
    delay(wait1);
    digitalWriteFast(19,LOW);
    delay(wait2);
    //Serial.println("+5V Active");
    digitalWriteFast(20,HIGH);
    delay(wait1);
    digitalWriteFast(20,LOW);
    delay(wait3);

    //Serial.println("Source Ext");
    digitalWriteFast(22,HIGH);
    delay(wait1);
    digitalWriteFast(22,LOW);
    delay(wait2);
    //Serial.println("Source Int (def)");
    digitalWriteFast(21,HIGH);
    delay(wait1);
    digitalWriteFast(21,LOW);
    delay(wait3);

    //Serial.println("Drain Ext");
    digitalWriteFast(24,HIGH);
    delay(wait1);
    digitalWriteFast(24,LOW);
    delay(wait2);
    //Serial.println("Drain Int (def)");
    digitalWriteFast(23,HIGH);
    delay(wait1);
    digitalWriteFast(23,LOW);
    delay(wait3);

    //Serial.println("Hold Ext");
    digitalWriteFast(26,HIGH);
    delay(wait1);
    digitalWriteFast(26,LOW);
    delay(wait2);
    //Serial.println("Hold Int (def)");
    digitalWriteFast(25,HIGH);
    delay(wait1);
    digitalWriteFast(25,LOW);
    delay(wait3);

    //Serial.println("Gate Ext");
    digitalWriteFast(28,HIGH);
    delay(wait1);
    digitalWriteFast(28,LOW);
    delay(wait2);
    //Serial.println("Gate Int (def)");
    digitalWriteFast(27,HIGH);
    delay(wait1);
    digitalWriteFast(27,LOW);
    delay(wait3);

    //Serial.println("V1-NonInv");
    digitalWriteFast(30,HIGH);
    delay(wait1);
    digitalWriteFast(30,LOW);
    delay(wait2);
    //Serial.println("V1-Inv (def)");
    digitalWriteFast(29,HIGH);
    delay(wait1);
    digitalWriteFast(29,LOW);
    delay(wait3);

    //Serial.println("V2-NonInv");
    digitalWriteFast(32,HIGH);
    delay(wait1);
    digitalWriteFast(32,LOW);
    delay(wait2);
    //Serial.println("V2-Inv (def)");
    digitalWriteFast(31,HIGH);
    delay(wait1);
    digitalWriteFast(31,LOW);
    delay(wait3);

    //Serial.println("I1-Hi");
    digitalWriteFast(34,HIGH);
    delay(wait1);
    digitalWriteFast(34,LOW);
    delay(wait2);
    //Serial.println("I1-Lo (def)");
    digitalWriteFast(33,HIGH);
    delay(wait1);
    digitalWriteFast(33,LOW);
    delay(wait3);

    //Serial.println("I2-Hi");
    digitalWriteFast(36,HIGH);
    delay(wait1);
    digitalWriteFast(36,LOW);
    delay(wait2);
    //Serial.println("I2-Lo (def)");
    digitalWriteFast(35,HIGH);
    delay(wait1);
    digitalWriteFast(35,LOW);
    delay(wait3);

    //Serial.println("I1-CSA");
    digitalWriteFast(38,HIGH);
    delay(wait1);
    digitalWriteFast(38,LOW);
    delay(wait2);
    //Serial.println("I1-TIA (def)");
    digitalWriteFast(37,HIGH);
    delay(wait1);
    digitalWriteFast(37,LOW);
    delay(wait3);

    //Serial.println("I2-CSA");
    digitalWriteFast(40,HIGH);
    delay(wait1);
    digitalWriteFast(40,LOW);
    delay(wait2);
    //Serial.println("I2-TIA (def)");
    digitalWriteFast(39,HIGH);
    delay(wait1);
    digitalWriteFast(39,LOW);
    delay(wait3);

    counter++;
    delay(3000); // wait 3 seconds between sets

    if (counter >= count){
      hasRun = true;
    }  
  }
}