//
// Brought to Teensy-wells v1.0.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// For use with TeensyBasicCommsTest.py in PyNE-wells v2.0.0. only.
// Code will allow you to send a string to a Teensy, which will echo the string back to you.
// End loop using 'exit'. Code is purely for serial byte traffic check.
//

void setup() {
  Serial.begin(9600); // Begin transmission
}

void loop() {
  String val;
  while (Serial.available() > 0) {
    val = val + (char)Serial.read(); // Read data byte by byte and store it
  }
  Serial.print(val); // Send the received data back to Raspberry Pi
}
