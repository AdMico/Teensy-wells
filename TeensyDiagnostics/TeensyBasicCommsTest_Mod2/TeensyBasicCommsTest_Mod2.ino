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
    String val = Serial.readStringUntil('\n');
    val.trim();
    if (val.length() > 0) {
      char firstChar = val.charAt(0);
      if (firstChar == 'A') { // Condition A: Activate control relay
        String relay = val.substring(1,3);
        Serial.println("Activate: " + relay);
      } 
      else if (firstChar == 'B') { // Condition B: Deactivate control relay
        String relay = val.substring(1,3);
        Serial.println("Deactivate: " + relay);
      } 
      else if (firstChar == 'M') { // Condition C: Node to measure
        String word = val.charAt(1);
        String bit = val.charAt(2);
        Serial.println("Measure: " + word + " " + bit);
      }
      else if (firstChar == 'H') { // Condition D: Node to hold
        String word = val.charAt(1);
        String bit = val.charAt(2);
        Serial.println("Hold: " + word + " " + bit);
      }
      else { // Condition E: Invalid prefix, return an error message
        Serial.println("Error: String must start with A, B, M or H.");
      }
    }
  }
}

String reverse(String str) {
  int len = str.length();
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
  return str;
}