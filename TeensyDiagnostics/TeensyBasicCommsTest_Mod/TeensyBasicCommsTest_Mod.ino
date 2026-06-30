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
  Serial.begin(9600); // Begin transmission n.b. baud rate is ignored by Teensy 4.1
  //Serial.setTimeout(50);
}

void loop() {
  if (Serial.available() > 0) {
    //while (Serial.available() > 0) {
    //  val = val + (char)Serial.read(); // Read data byte by byte and store it
    //}
    String val = Serial.readStringUntil('\n');
    val.trim();
    reverse(val);
    Serial.println(val); // Send the received data back to Raspberry Pi
  }
}

void reverse(String &str) {
  int len = str.length();
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
}