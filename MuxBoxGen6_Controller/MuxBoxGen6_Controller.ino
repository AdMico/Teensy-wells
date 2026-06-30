//
// Brought to Teensy-wells v1.0.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// Main algorithm taking commands from the python software and implementing the switching of relays in the MuxBox.
// Software runs continuously on the Teensy 4.1 during operation of the MuxBox.
//
// APM 08MAY26 -- Need to fix GPIO map in future instance when I fix the BC847 issue on the MuxBox PCB.

// GPIO Mapping for V1 of Gen6 box
// W-EN1 = 1; W-EN2 = 2; W-A0 = 3; W-A1 = 4; W-A2 = 5; W-A3 = 6; B-EN1 = 7; B-EN2 = 8; B-A0 = 9; B-A1 = 10; B-A2 = 11; B-A3 = 12;
// Bias Words (def) = 13; Bias Bits = 14; Word Off (def) = 15; Word On = 16; Bit Off (def) = 17; Bit On = 18; +5V GND (def) = 19; +5V Active = 20;
// Source Int (def) = 21; Source Ext = 22; Drain Int (def) = 23; Drain Ext = 24; Hold Int (def) = 25; Hold Ext = 26; Gate Int (def) = 27; Gate Ext = 28;
// V1-Inv (def) = 29; V1-NonInv = 30; V2-Inv (def) = 31; V2-NonInv = 32; I1-Lo (def) = 33; I1-Hi = 34; I2-Lo (def) = 35; I2-Hi = 36;
// I1-TIA (def) = 37, I1-CSA = 38, I2-TIA (def) = 39; I2-CSA = 40.
//
// GPIO Mapping as designed for Gen6 Box (will end up here on V2 boards)
// W-EN1 = 1; W-EN2 = 2; W-A0 = 3; W-A1 = 4; W-A2 = 5; W-A3 = 6; B-EN1 = 7; B-EN2 = 8; B-A0 = 9; B-A1 = 10; B-A2 = 11; B-A3 = 12;
// Bias Bits = 13; Bias Words (def) = 14; Word On = 15; Word Off (def) = 16; Bit On = 17; Bit Off (def) = 18; +5V Active = 19; +5V GND (def) = 20;
// Source Ext = 21; Source Int (def) = 22; Drain Ext = 23; Drain Int (def) = 24; Hold Ext = 25; Hold Int (def) = 26; Gate Ext = 27; Gate Int (def) = 28;
// V1-NonInv = 29; V1-Inv (def) = 30; V2-NonInv = 31; V2-Inv (def) = 32; I1-Hi = 33; I1-Lo (def) = 34; I2-Hi = 35; I2-Lo (def) = 36;
// I1-CSA = 37; I1-TIA (def) = 38; I2-CSA = 39; I2-TIA (def) = 40.

  int wait1 = 2; // Time relay coil is active
  int wait2 = 

void setup() {
  // Initialize the digital pins as outputs
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
  pinMode(15,OUTPUT); // Word Off (def)
  pinMode(16,OUTPUT); // Word On
  pinMode(17,OUTPUT); // Bit Off (def)
  pinMode(18,OUTPUT); // Bit On
  // Control Set
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

  // Make sure the 5V power line is active, otherwise the other relays won't switch.
  digitalWriteFast(20,HIGH);
  delay(wait1);
  digitalWriteFast(20,LOW);

  // Ensure the control relays are set to defaults
  // Set Source Int (def)
  digitalWriteFast(21,HIGH);
  delay(wait1);
  digitalWriteFast(21,LOW);
  // Set Drain Int (def)
  digitalWriteFast(23,HIGH);
  delay(wait1);
  digitalWriteFast(23,LOW);
  // Set Hold Int (def)
  digitalWriteFast(25,HIGH);
  delay(wait1);
  digitalWriteFast(25,LOW);
  // Set Gate Int (def)
  digitalWriteFast(27,HIGH);
  delay(wait1);
  digitalWriteFast(27,LOW);
  // Set V1-Inv (def)
  digitalWriteFast(29,HIGH);
  delay(wait1);
  digitalWriteFast(29,LOW);
  // Set V2-Inv (def)
  digitalWriteFast(31,HIGH);
  delay(wait1);
  digitalWriteFast(31,LOW);
  // Set I1-Lo (def)
  digitalWriteFast(33,HIGH);
  delay(wait1);
  digitalWriteFast(33,LOW);
  // Set I2-Lo (def)
  digitalWriteFast(35,HIGH);
  delay(wait1);
  digitalWriteFast(35,LOW);
  // Set I1-TIA (def)
  digitalWriteFast(37,HIGH);
  delay(wait1);
  digitalWriteFast(37,LOW);
  // Set I2-TIA (def)
  digitalWriteFast(39,HIGH);
  delay(wait1);
  digitalWriteFast(39,LOW);

  // Prep the serial connection
  Serial.begin(9600);
}

void loop() {
  // Wait for a command to arrive then pass to appropriate subroutine
  String input;
  while (Serial.available() > 0) {
    input = input + (char)Serial.read(); // Read data byte by byte and store it
  }

}
