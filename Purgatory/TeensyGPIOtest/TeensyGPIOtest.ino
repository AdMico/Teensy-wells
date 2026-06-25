//
// Brought to Teensy-wells v1.0.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// Designed for use with TeensyBasicCommsTest.py or Control - MCC_BasicFunctionChecks.py and offers full GPIO set functionality.
// For use with TeensyBasicCommsTest.py, send the pin number to turn the respective relay from NO to NC or NC to NO.
// For use with Control - MCC_BasicFunctionChecks.py, the program will automatically run a loop that switches a given relay,
// runs a voltage ramp on AO0 and AO1 to +2.0V and back, switches the relay back, then moves to the same or a different relay on each subsequent iteration.
//
// Relay/Pin Mapping Information
// Bias Bits = 13; Bias Words (def) = 14; Word On = 15; Word Off (def) = 16; Bit On = 17; Bit Off (def) = 18; +5V Active = 19; +5V GND (def) = 20;
// Source Ext = 21; Source Int (def) = 22; Drain Ext = 23; Drain Int (def) = 24; Hold Ext = 25; Hold Int (def) = 26; Gate Ext = 27; Gate Int (def) = 28;
// V1-NonInv = 29; V1-Inv (def) = 30; V2-NonInv = 31; V2-Inv (def) = 32; I1-Hi = 33; I1-Lo (def) = 34; I2-Hi = 35; I2-Lo (def) = 36;
// I1-CSA = 37; I1-TIA (def) = 38; I2-CSA = 39; I2-TIA (def) = 40.

int Pin; //Define variable for pin number 1
int wait = 10;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT); // Bias Bits
  pinMode(14,OUTPUT); // Bias Words (def)
  pinMode(15,OUTPUT); // Word On 
  pinMode(16,OUTPUT); // Word Off (def)
  pinMode(17,OUTPUT); // Bit On
  pinMode(18,OUTPUT); // Bit Off (def)
  pinMode(19,OUTPUT); // +5V Active
  pinMode(20,OUTPUT); // +5V GND (def)
  pinMode(21,OUTPUT); // Source Ext
  pinMode(22,OUTPUT); // Source Int (def)
  pinMode(23,OUTPUT); // Drain Ext
  pinMode(24,OUTPUT); // Drain Int (def)
  pinMode(25,OUTPUT); // Hold Ext
  pinMode(26,OUTPUT); // Hold Int (def)
  pinMode(27,OUTPUT); // Gate Ext
  pinMode(28,OUTPUT); // Gate Int (def)
  pinMode(29,OUTPUT); // V1-NonInv
  pinMode(30,OUTPUT); // V1-Inv (def)
  pinMode(31,OUTPUT); // V2-NonInv
  pinMode(32,OUTPUT); // V2-Inv (def)
  pinMode(33,OUTPUT); // I1-Hi
  pinMode(34,OUTPUT); // I1-Lo (def)
  pinMode(35,OUTPUT); // I2-Hi
  pinMode(36,OUTPUT); // I2-Lo (def)
  pinMode(37,OUTPUT); // I1-CSA
  pinMode(38,OUTPUT); // I1-TIA (def)
  pinMode(39,OUTPUT); // I2-CSA
  pinMode(40,OUTPUT); // I2-TIA (def)
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('/n'); // Read until newline
    String PinStr = command.trim(); // Remove any leading/trailing whitespace
    Pin = PinStr.toInt(); 
    if ((Pin >= 13 && (Pin <= 40))){
      digitalWrite(Pin,HIGH);
      delay(wait);
      digitalWrite(Pin,LOW);
      Serial.println("Relay Switched");
    } else {
      Serial.println("Relay Switch Fail: Pin outside bounds");
    }
  }
}