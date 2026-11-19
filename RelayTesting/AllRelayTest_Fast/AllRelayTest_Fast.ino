//
// Brought to Teensy-wells v1.1.0 on Wed Nov 16 2026 by APM
//
// @developers: Adam Micolich
//
// Basic algorithm for testing all 14 control relays and all 54 device relays.
// It will cycle through bringing each relay one by one first to NO, then back to NC (default)
// Has no interaction with PyNE-wells code, it's purely for hardware test, and should be used with the Teensy in the MuxBox PCB.
//
// Note: You will only hear 12 relay rollovers on the control relay test because one GPIO pair has six relays on it rather than only two.
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
int wait2 = 10; // Time between on and off
int wait3 = 30; // Time before the next relay
int wait4 = 500; // Time between test sets
bool hasRun = false;

void setup() {
  //Serial.begin(9600);
  // initialize the digital pins as outputs
  // Device Set
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
  // Control Set
  pinMode(13,OUTPUT); // Bias Bits
  pinMode(14,OUTPUT); // Bias Words (def)
  pinMode(19,OUTPUT); // Gate TIA
  pinMode(20,OUTPUT); // Hold TIA (def)
  pinMode(21,OUTPUT); // Source Ext
  pinMode(22,OUTPUT); // Source Int (def)
  pinMode(23,OUTPUT); // Drain Ext
  pinMode(24,OUTPUT); // Drain Int (def)
  pinMode(25,OUTPUT); // Hold Ext
  pinMode(26,OUTPUT); // Hold Int (def)
  pinMode(27,OUTPUT); // Gate Ext
  pinMode(28,OUTPUT); // Gate Int (def)
  pinMode(29,OUTPUT); // V1-Pos
  pinMode(30,OUTPUT); // V1-Neg (def)
  pinMode(31,OUTPUT); // V2-Pos 
  pinMode(32,OUTPUT); // V2-Neg (def)
  pinMode(33,OUTPUT); // I1-Hi
  pinMode(34,OUTPUT); // I1-Lo (def)
  pinMode(35,OUTPUT); // I2-Hi
  pinMode(36,OUTPUT); // I2-Lo (def)
  pinMode(37,OUTPUT); // I1-CSA
  pinMode(38,OUTPUT); // I1-TIA (def)
  pinMode(39,OUTPUT); // I2-CSA
  pinMode(40,OUTPUT); // I2-TIA (def)

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
  digitalWriteFast(15,LOW);
  digitalWriteFast(16,LOW);
  digitalWriteFast(17,LOW);
  digitalWriteFast(18,LOW);
}

void loop() {
  if (!hasRun)  {

    // Correct for 'Pin 25 activates during bootload' issue
    //Serial.println("Hold Int (def)");
    digitalWriteFast(26,HIGH);
    delay(wait1);
    digitalWriteFast(26,LOW);
    delay(wait3);
    delay(1000);

    // Begin Control Relay Testing

    //Serial.println("Bias Bits");
    digitalWriteFast(13,HIGH);
    delay(wait1);
    digitalWriteFast(13,LOW);
    delay(wait2);
    //Serial.println("Bias Words (def)");
    digitalWriteFast(14,HIGH);
    delay(wait1);
    digitalWriteFast(14,LOW);
    delay(wait3);

    //Serial.println("Gate TIA");
    digitalWriteFast(19,HIGH);
    delay(wait1);
    digitalWriteFast(19,LOW);
    delay(wait2);
    //Serial.println("Hold TIA (def)");
    digitalWriteFast(20,HIGH);
    delay(wait1);
    digitalWriteFast(20,LOW);
    delay(wait3);

    //Serial.println("Source Ext");
    digitalWriteFast(21,HIGH);
    delay(wait1);
    digitalWriteFast(21,LOW);
    delay(wait2);
    //Serial.println("Source Int (def)");
    digitalWriteFast(22,HIGH);
    delay(wait1);
    digitalWriteFast(22,LOW);
    delay(wait3);

    //Serial.println("Drain Ext");
    digitalWriteFast(23,HIGH);
    delay(wait1);
    digitalWriteFast(23,LOW);
    delay(wait2);
    //Serial.println("Drain Int (def)");
    digitalWriteFast(24,HIGH);
    delay(wait1);
    digitalWriteFast(24,LOW);
    delay(wait3);

    //Serial.println("Hold Ext");
    digitalWriteFast(25,HIGH);
    delay(wait1);
    digitalWriteFast(25,LOW);
    delay(wait2);
    //Serial.println("Hold Int (def)");
    digitalWriteFast(26,HIGH);
    delay(wait1);
    digitalWriteFast(26,LOW);
    delay(wait3);

    //Serial.println("Gate Ext");
    digitalWriteFast(27,HIGH);
    delay(wait1);
    digitalWriteFast(27,LOW);
    delay(wait2);
    //Serial.println("Gate Int (def)");
    digitalWriteFast(28,HIGH);
    delay(wait1);
    digitalWriteFast(28,LOW);
    delay(wait3);

    //Serial.println("V1-Pos");
    digitalWriteFast(29,HIGH);
    delay(wait1);
    digitalWriteFast(29,LOW);
    delay(wait2);
    //Serial.println("V1-Neg (def)");
    digitalWriteFast(30,HIGH);
    delay(wait1);
    digitalWriteFast(30,LOW);
    delay(wait3);

    //Serial.println("V2-Pos");
    digitalWriteFast(31,HIGH);
    delay(wait1);
    digitalWriteFast(31,LOW);
    delay(wait2);
    //Serial.println("V2-Neg (def)");
    digitalWriteFast(32,HIGH);
    delay(wait1);
    digitalWriteFast(32,LOW);
    delay(wait3);

    //Serial.println("I1-Hi");
    digitalWriteFast(33,HIGH);
    delay(wait1);
    digitalWriteFast(33,LOW);
    delay(wait2);
    //Serial.println("I1-Lo (def)");
    digitalWriteFast(34,HIGH);
    delay(wait1);
    digitalWriteFast(34,LOW);
    delay(wait3);

    //Serial.println("I2-Hi");
    digitalWriteFast(35,HIGH);
    delay(wait1);
    digitalWriteFast(35,LOW);
    delay(wait2);
    //Serial.println("I2-Lo (def)");
    digitalWriteFast(36,HIGH);
    delay(wait1);
    digitalWriteFast(36,LOW);
    delay(wait3);

    //Serial.println("I1-CSA");
    digitalWriteFast(37,HIGH);
    delay(wait1);
    digitalWriteFast(37,LOW);
    delay(wait2);
    //Serial.println("I1-TIA (def)");
    digitalWriteFast(38,HIGH);
    delay(wait1);
    digitalWriteFast(38,LOW);
    delay(wait3);

    //Serial.println("I2-CSA");
    digitalWriteFast(39,HIGH);
    delay(wait1);
    digitalWriteFast(39,LOW);
    delay(wait2);
    //Serial.println("I2-TIA (def)");
    digitalWriteFast(40,HIGH);
    delay(wait1);
    digitalWriteFast(40,LOW);
    delay(wait3);

    delay(wait4);

    // Begin Device Set -- Words first
    
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
    digitalWriteFast(15,LOW);
    digitalWriteFast(16,LOW);

    delay(wait4);

    // Begin Device Set -- Bits second

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
    delay(wait4); // wait between repeats of the set

    if (counter >= count){
      hasRun = true;
    }  
  }
}