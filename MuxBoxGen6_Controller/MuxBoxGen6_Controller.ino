//
// Brought to Teensy-wells v1.1.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// Main algorithm taking commands from the python software and implementing the switching of relays in the MuxBox.
// Software runs continuously on the Teensy 4.1 during operation of the MuxBox.
//
// GPIO Mapping for Gen6 Box (V2+)
// W-EN1 = 1; W-EN2 = 2; W-A0 = 3; W-A1 = 4; W-A2 = 5; W-A3 = 6; B-EN1 = 7; B-EN2 = 8; B-A0 = 9; B-A1 = 10; B-A2 = 11; B-A3 = 12; 
// Bias Bits = 13; Bias Words (def) = 14; Word On = 15; Word Off (def) = 16; Bit On = 17; Bit Off (def) = 18; Gate TIA = 19; Hold TIA (def) = 20;
// Source Ext = 21; Source Int (def) = 22; Drain Ext = 23; Drain Int (def) = 24; Hold Ext = 25; Hold Int (def) = 26; Gate Ext = 27; Gate Int (def) = 28;
// V1-Pos = 29; V1-Neg (def) = 30; V2-Pos = 31; V2-Neg (def) = 32; I1-Hi = 33; I1-Lo (def) = 34; I2-Hi = 35; I2-Lo (def) = 36;
// I1-CSA = 37; I1-TIA (def) = 38; I2-CSA = 39; I2-TIA (def) = 40.

  int wait1 = 2; // Time relay coil is active (ms)
  int wait2r = 5; // Time between on and off (ms)
  int wait2f = 10; // Time between on and off (ms)
  int wait3f = 30; // Time before the next relay (ms)
  int wait4f = 500; // Time between test sets (ms)
  int wait2s = 100; // Time between on and off (ms)
  int wait3s = 500; // Time before the next relay (ms)
  int wait4s = 2000; // Time between test sets (ms)
  struct activeNode { // Data for the active node
    int wAct; // Active word line -- if 0 then none, if 1-27, then corresponding word line. Used for error control.
    int bAct; // Active bit line -- if 0 then none, if 1-27, then corresponding bit line. Used for error control.
  };
    // Initialize activeNode structure
  activeNode node = {0,0};


  uint8_t muxTable[27][6] = { // Columns are EN1, EN2, A0, A1, A2, A3
    {1,0,0,0,0,0}, // Line 1
    {1,0,1,0,0,0}, // Line 2
    {1,0,0,1,0,0}, // Line 3
    {1,0,1,1,0,0}, // Line 4
    {1,0,0,0,1,0}, // Line 5
    {1,0,1,0,1,0}, // Line 6
    {1,0,0,1,1,0}, // Line 7
    {1,0,1,1,1,0}, // Line 8
    {1,0,0,0,0,1}, // Line 9
    {1,0,1,0,0,1}, // Line 10
    {1,0,0,1,0,1}, // Line 11
    {1,0,1,1,0,1}, // Line 12
    {1,0,0,0,1,1}, // Line 13
    {1,0,1,0,1,1}, // Line 14
    {0,1,0,0,0,0}, // Line 15
    {0,1,1,0,0,0}, // Line 16
    {0,1,0,1,0,0}, // Line 17
    {0,1,1,1,0,0}, // Line 18
    {0,1,0,0,1,0}, // Line 19
    {0,1,1,0,1,0}, // Line 20
    {0,1,0,1,1,0}, // Line 21
    {0,1,1,1,1,0}, // Line 22
    {0,1,0,0,0,1}, // Line 23
    {0,1,1,0,0,1}, // Line 24
    {0,1,0,1,0,1}, // Line 25
    {0,1,1,1,0,1}, // Line 26
    {0,1,0,0,1,1}, // Line 27
  };

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
  pinMode(15,OUTPUT); // Word On
  pinMode(16,OUTPUT); // Word Off (def)
  pinMode(17,OUTPUT); // Bit On
  pinMode(18,OUTPUT); // Bit Off (def)
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
  digitalWriteFast(1,0);
  digitalWriteFast(2,0);
  digitalWriteFast(3,0);
  digitalWriteFast(4,0);
  digitalWriteFast(5,0);
  digitalWriteFast(6,0);
  digitalWriteFast(7,0);
  digitalWriteFast(8,0);
  digitalWriteFast(9,0);
  digitalWriteFast(10,0);
  digitalWriteFast(11,0);
  digitalWriteFast(12,0);
  digitalWriteFast(15,0);
  digitalWriteFast(16,0);
  digitalWriteFast(17,0);
  digitalWriteFast(18,0);

  // Correct for 'Pin 25 activates during bootload' issue
  //Serial.println("Hold Int (def)");
  digitalWriteFast(26,HIGH);
  delay(wait1);
  digitalWriteFast(26,LOW);
  delay(1000);

  // Ensure the control relays are set to defaults
  // Set Hold-TIA (def)
  digitalWriteFast(20,1);
  delay(wait1);
  digitalWriteFast(20,0);
  // Set Source Int (def)
  digitalWriteFast(22,1);
  delay(wait1);
  digitalWriteFast(22,0);
  // Set Drain Int (def)
  digitalWriteFast(24,1);
  delay(wait1);
  digitalWriteFast(24,0);
  // Set Hold Int (def)
  digitalWriteFast(26,1);
  delay(wait1);
  digitalWriteFast(26,0);
  // Set Gate Int (def)
  digitalWriteFast(28,1);
  delay(wait1);
  digitalWriteFast(28,0);
  // Set V1-Neg (def)
  digitalWriteFast(30,1);
  delay(wait1);
  digitalWriteFast(30,0);
  // Set V2-Neg (def)
  digitalWriteFast(32,1);
  delay(wait1);
  digitalWriteFast(32,0);
  // Set I1-Lo (def)
  digitalWriteFast(34,1);
  delay(wait1);
  digitalWriteFast(34,0);
  // Set I2-Lo (def)
  digitalWriteFast(36,1);
  delay(wait1);
  digitalWriteFast(36,0);
  // Set I1-TIA (def)
  digitalWriteFast(38,1);
  delay(wait1);
  digitalWriteFast(38,0);
  // Set I2-TIA (def)
  digitalWriteFast(40,1);
  delay(wait1);
  digitalWriteFast(40,0);

  // Ensure the word relays are all set to hold
  for (int i = 0; i < 27; i++) {
    digitalWriteFast(1,muxTable[i][0]);
    digitalWriteFast(2,muxTable[i][1]);
    digitalWriteFast(3,muxTable[i][2]);
    digitalWriteFast(4,muxTable[i][3]);
    digitalWriteFast(5,muxTable[i][4]);
    digitalWriteFast(6,muxTable[i][5]);
    digitalWriteFast(16,1);
    delay(wait1);
    digitalWriteFast(16,0);
  }

  // Ensure the bit relays are all set to hold
  for (int j = 0; j < 27; j++) {
    digitalWriteFast(7,muxTable[j][0]);
    digitalWriteFast(8,muxTable[j][1]);
    digitalWriteFast(9,muxTable[j][2]);
    digitalWriteFast(10,muxTable[j][3]);
    digitalWriteFast(11,muxTable[j][4]);
    digitalWriteFast(12,muxTable[j][5]);
    digitalWriteFast(18,1);
    delay(wait1);
    digitalWriteFast(18,0);
  }

  // Prep the serial connection
  Serial.begin(9600);
}

void loop() {
  // Wait for a command to arrive then pass to appropriate subroutine
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.length() > 0) {
      if (input == "exit") {
        Error0();
      }
      else if (input.length() == 3) {
        char firstChar = input.charAt(0);
        if (firstChar == 'A') { // Request for active node information
          Error0a(node);
        }
        else if (firstChar == 'D') { // Set control relay back to default
          CmdD(input);
        }
        else if (firstChar == 'N') { // Set control relay to non-default
          CmdN(input);
        }
        else if (firstChar == 'M') { // Node to measure
          node = NodeM(input,node);
        }
        else if (firstChar == 'H') { // Node to hold
          node = NodeH(input,node);
        }
        else if (firstChar == 'W') { // Shift measured node along wordline
          node = ShiftW(input,node);
        }
        else if (firstChar == 'B') { // Shift measured node along bitline
          node = ShiftB(input,node);
        }
        else if (firstChar == 'R') { // Run a reset routine
          char secondChar = input.charAt(1);
          if (secondChar == 'D') { // Reset all nodes to hold
            node = ResetDevices(wait2r,node);
          }
          else if (secondChar == 'C') { // Reset all control relays to default
            ResetControl();
          }
          else if (secondChar == 'A') { // Do both resets sequentially
            node = ResetAll(wait2r,node);
          }          
        }
        else if (firstChar == 'T') { // Run Device Relay Test
          char secondChar = input.charAt(1);
          if (secondChar == 'F') { // Run in fast mode
            node = DRT(wait2f,wait3f,wait4f,node);
          }
          else if (secondChar == 'S') { // Run in slow mode
            node = DRT(wait2s,wait3s,wait4s,node);
          }
          else { // Invalid command so send error
            Error2();
          }  
        }
        else { // Invalid prefix so send error
          Error1();
        }
      }
      else { // Invalid command so send error
        Error2();   
      } 
    }
  }
}

void CmdD(String input) { // input designates which control relay to switch
  String relay = input.substring(1,3);
  int relNum = relay.toInt();
  if (relNum >= 1 && relNum <= 6) {
    if (relNum >= 1 && relNum <= 3) {
      if (relNum == 1) {
        digitalWriteFast(14,1);
        delay(wait1);
        digitalWriteFast(14,0);
        Error0();
      }
      else if (relNum == 2) {
        digitalWriteFast(20,1);
        delay(wait1);
        digitalWriteFast(20,0);
        Error0();
      }
      else {
        digitalWriteFast(22,1);
        delay(wait1);
        digitalWriteFast(22,0);
        Error0();
      }
    }
    else {
      if (relNum == 4) {
        digitalWriteFast(24,1);
        delay(wait1);
        digitalWriteFast(24,0);
        Error0();
      }
      else if (relNum == 5) {
        digitalWriteFast(26,1);
        delay(wait1);
        digitalWriteFast(26,0);
        Error0();
      }
      else {
        digitalWriteFast(28,1);
        delay(wait1);
        digitalWriteFast(28,0);
        Error0();
      }
    }
  } 
  else if (relNum >= 7 && relNum <= 12) {
    if (relNum >= 7 && relNum <= 9) {
      if (relNum == 7) {
        digitalWriteFast(30,1);
        delay(wait1);
        digitalWriteFast(30,0);
        Error0();
      }
      else if (relNum == 8) {
        digitalWriteFast(32,1);
        delay(wait1);
        digitalWriteFast(32,0);
        Error0();
      }
      else {
        digitalWriteFast(34,1);
        delay(wait1);
        digitalWriteFast(34,0);
        Error0();
      }
    }
    else {
      if (relNum == 10) {
        digitalWriteFast(36,1);
        delay(wait1);
        digitalWriteFast(36,0);
        Error0();
      }
      else if (relNum == 11) {
        digitalWriteFast(38,1);
        delay(wait1);
        digitalWriteFast(38,0);
        Error0();
      }
      else {
        digitalWriteFast(40,1);
        delay(wait1);
        digitalWriteFast(40,0);
        Error0();
      }
    }
  } 
  else {
    Error3();
  }
}

void CmdN(String input) { // input designates which control relay to switch
  String relay = input.substring(1,3);
  int relNum = relay.toInt();
  if (relNum >= 1 && relNum <= 6) {
    if (relNum >= 1 && relNum <= 3) {
      if (relNum == 1) {
        digitalWriteFast(13,1);
        delay(wait1);
        digitalWriteFast(13,0);
        Error0();
      }
      else if (relNum == 2) {
        digitalWriteFast(19,1);
        delay(wait1);
        digitalWriteFast(19,0);
        Error0();
      }
      else {
        digitalWriteFast(21,1);
        delay(wait1);
        digitalWriteFast(21,0);
        Error0();
      }
    }
    else {
      if (relNum == 4) {
        digitalWriteFast(23,1);
        delay(wait1);
        digitalWriteFast(23,0);
        Error0();
      }
      else if (relNum == 5) {
        digitalWriteFast(25,1);
        delay(wait1);
        digitalWriteFast(25,0);
        Error0();
      }
      else {
        digitalWriteFast(27,1);
        delay(wait1);
        digitalWriteFast(27,0);
        Error0();
      }
    }
  } 
  else if (relNum >= 7 && relNum <= 12) {
    if (relNum >= 7 && relNum <= 9) {
      if (relNum == 7) {
        digitalWriteFast(29,1);
        delay(wait1);
        digitalWriteFast(29,0);
        Error0();
      }
      else if (relNum == 8) {
        digitalWriteFast(31,1);
        delay(wait1);
        digitalWriteFast(31,0);
        Error0();
      }
      else {
        digitalWriteFast(33,1);
        delay(wait1);
        digitalWriteFast(33,0);
        Error0();
      }
    }
    else {
      if (relNum == 10) {
        digitalWriteFast(35,1);
        delay(wait1);
        digitalWriteFast(35,0);
        Error0();
      }
      else if (relNum == 11) {
        digitalWriteFast(37,1);
        delay(wait1);
        digitalWriteFast(37,0);
        Error0();
      }
      else {
        digitalWriteFast(39,1);
        delay(wait1);
        digitalWriteFast(39,0);
        Error0();
      }
    }
  } 
  else {
    Error3();
  }
}

activeNode NodeM(String input, activeNode &node) { // Set specified node to measure -- input has word and bit information
  char word = input.charAt(1);
  char bit = input.charAt(2);
  int wNum = word;
  int bNum = bit;
  // Convert word and bit into the corresponding line numbers
  if (word == '&') {
    wNum = wNum - 12; // Associates & with muxtable row 27 (i.e., 26) 
  } else {
    wNum = wNum - 65; // Associates A through Z with muxtable row 1 through 26 (i.e., 0 to 25)
  }
  if (bit == '&') {
    bNum = bNum - 12; // Associates & with muxtable row 27 (i.e., 26)
  } else {
    bNum = bNum - 65; // Associates A through Z with muxtable row 1 through 26 (i.e., 0 to 25)
  }
  if (node.wAct == 0 && node.bAct == 0) { // Checks that no other node is active before proceeding
    // Switch the word line over to measure
    digitalWriteFast(1,muxTable[wNum][0]);
    digitalWriteFast(2,muxTable[wNum][1]);
    digitalWriteFast(3,muxTable[wNum][2]);
    digitalWriteFast(4,muxTable[wNum][3]);
    digitalWriteFast(5,muxTable[wNum][4]);
    digitalWriteFast(6,muxTable[wNum][5]);
    digitalWriteFast(15,1);
    delay(wait1);
    digitalWriteFast(15,0);
    node.wAct = (wNum + 1);
    // Switch the bit line over to measure
    digitalWriteFast(7,muxTable[bNum][0]);
    digitalWriteFast(8,muxTable[bNum][1]);
    digitalWriteFast(9,muxTable[bNum][2]);
    digitalWriteFast(10,muxTable[bNum][3]);
    digitalWriteFast(11,muxTable[bNum][4]);
    digitalWriteFast(12,muxTable[bNum][5]);
    digitalWriteFast(17,1);
    delay(wait1);
    digitalWriteFast(17,0);
    node.bAct = (bNum + 1);
    Error0a(node);
  }
  else { // Case if another node is already active
    Error4();
  }  
  return node;
}

activeNode NodeH(String input, activeNode &node) { // Set specified node back to hold -- input has word and bit information
  char word = input.charAt(1);
  char bit = input.charAt(2);
  int wNum = word;
  int bNum = bit;
  if (word == '&') {
    wNum = wNum - 12; // Associates & with muxtable row 27 (i.e., 26)
  } else {
    wNum = wNum - 65; // Associates A through Z with muxtable row 1 through 26 (i.e., 0 to 25)
  }
  if (bit == '&') {
    bNum = bNum - 12; // Associates & with muxtable row 27 (i.e., 26)
  } else {
    bNum = bNum - 65; // Associates A through Z with muxtable row 1 through 26 (i.e., 0 to 25)
  }
  if (node.wAct == (wNum + 1) && node.bAct == (bNum + 1)) { // Checks that the active node is being switched to hold
    // Switch the word line over to hold
    digitalWriteFast(1,muxTable[wNum][0]);
    digitalWriteFast(2,muxTable[wNum][1]);
    digitalWriteFast(3,muxTable[wNum][2]);
    digitalWriteFast(4,muxTable[wNum][3]);
    digitalWriteFast(5,muxTable[wNum][4]);
    digitalWriteFast(6,muxTable[wNum][5]);
    digitalWriteFast(16,1);
    delay(wait1);
    digitalWriteFast(16,0);
    node.wAct = 0;
    // Switch the bit line over to hold
    digitalWriteFast(7,muxTable[bNum][0]);
    digitalWriteFast(8,muxTable[bNum][1]);
    digitalWriteFast(9,muxTable[bNum][2]);
    digitalWriteFast(10,muxTable[bNum][3]);
    digitalWriteFast(11,muxTable[bNum][4]);
    digitalWriteFast(12,muxTable[bNum][5]);
    digitalWriteFast(18,1);
    delay(wait1);
    digitalWriteFast(18,0);
    node.bAct = 0;
    Error0a(node);
  }
  else { // Case if the active node hasn't been selected to switch to hold
    Error5();
  }
  return node;
}

activeNode ShiftW(String input,activeNode &node) { // Shift measured node along a wordline -- input has hold and measure information
  char hold = input.charAt(1);
  char meas = input.charAt(2);
  int hNum = hold;
  int mNum = meas;
  if (hold == '&') {
    hNum = hNum - 12; // Associates & with muxtable row 27 (i.e., 26)
  } else {
    hNum = hNum - 65; // Associates A through Z with muxtable row 1 through 26 (i.e., 0 to 25)
  }
  if (meas == '&') {
    mNum = mNum - 12; // Associates & with muxtable row 27 (i.e., 26)
  } else {
    mNum = mNum - 65; // Associates A through Z with muxtable row 1 through 26 (i.e., 0 to 25)
  } 
  if (node.wAct == (hNum + 1)) { // Checks that the active word line is being switched to hold
    // Switch the first word input over to hold
    digitalWriteFast(1,muxTable[hNum][0]);
    digitalWriteFast(2,muxTable[hNum][1]);
    digitalWriteFast(3,muxTable[hNum][2]);
    digitalWriteFast(4,muxTable[hNum][3]);
    digitalWriteFast(5,muxTable[hNum][4]);
    digitalWriteFast(6,muxTable[hNum][5]);
    digitalWriteFast(16,1);
    delay(wait1);
    digitalWriteFast(16,0);
    // Switch the second word input over to meas
    digitalWriteFast(1,muxTable[mNum][0]);
    digitalWriteFast(2,muxTable[mNum][1]);
    digitalWriteFast(3,muxTable[mNum][2]);
    digitalWriteFast(4,muxTable[mNum][3]);
    digitalWriteFast(5,muxTable[mNum][4]);
    digitalWriteFast(6,muxTable[mNum][5]);
    digitalWriteFast(15,1);
    delay(wait1);
    digitalWriteFast(15,0);
    node.wAct = mNum + 1;
    Error0a(node);
  }
  else {
    Error6();
  }
  return node;
}

activeNode ShiftB(String input, activeNode &node) { // Shift measured node along a bitline -- input has hold and measure information
  char hold = input.charAt(1);
  char meas = input.charAt(2);
  int hNum = hold;
  int mNum = meas;
  if (hold == '&') {
    hNum = hNum - 12; // Associates & with muxtable row 27 (i.e., 26)
  } else {
    hNum = hNum - 65; // Associates A through Z with muxtable row 1 through 26 (i.e., 0 to 25)
  }
  if (meas == '&') {
    mNum = mNum - 12; // Associates & with muxtable row 27 (i.e., 26)
  } else {
    mNum = mNum - 65; // Associates A through Z with muxtable row 1 through 26 (i.e., 0 to 25)
  }
  if (node.bAct == (hNum + 1)) { // Checks that the active bit line is being switched to hold 
    // Switch the first bit input over to hold
    digitalWriteFast(7,muxTable[hNum][0]);
    digitalWriteFast(8,muxTable[hNum][1]);
    digitalWriteFast(9,muxTable[hNum][2]);
    digitalWriteFast(10,muxTable[hNum][3]);
    digitalWriteFast(11,muxTable[hNum][4]);
    digitalWriteFast(12,muxTable[hNum][5]);
    digitalWriteFast(18,1);
    delay(wait1);
    digitalWriteFast(18,0);
    // Switch the second bit input over to meas
    digitalWriteFast(7,muxTable[mNum][0]);
    digitalWriteFast(8,muxTable[mNum][1]);
    digitalWriteFast(9,muxTable[mNum][2]);
    digitalWriteFast(10,muxTable[mNum][3]);
    digitalWriteFast(11,muxTable[mNum][4]);
    digitalWriteFast(12,muxTable[mNum][5]);
    digitalWriteFast(17,1);
    delay(wait1);
    digitalWriteFast(17,0);
    node.bAct = mNum + 1;
    Error0a(node);
  }
  else {
    Error6();
  }
  return node;
}

void ResetControl() {
  // Ensure the control relays are set to defaults
  // Set Hold TIA (def)
  digitalWriteFast(20,1);
  delay(wait1);
  digitalWriteFast(20,0);
  // Set Source Int (def)
  digitalWriteFast(22,1);
  delay(wait1);
  digitalWriteFast(22,0);
  // Set Drain Int (def)
  digitalWriteFast(24,1);
  delay(wait1);
  digitalWriteFast(24,0);
  // Set Hold Int (def)
  digitalWriteFast(26,1);
  delay(wait1);
  digitalWriteFast(26,0);
  // Set Gate Int (def)
  digitalWriteFast(28,1);
  delay(wait1);
  digitalWriteFast(28,0);
  // Set V1-Neg (def)
  digitalWriteFast(30,1);
  delay(wait1);
  digitalWriteFast(30,0);
  // Set V2-Neg (def)
  digitalWriteFast(32,1);
  delay(wait1);
  digitalWriteFast(32,0);
  // Set I1-Lo (def)
  digitalWriteFast(34,1);
  delay(wait1);
  digitalWriteFast(34,0);
  // Set I2-Lo (def)
  digitalWriteFast(36,1);
  delay(wait1);
  digitalWriteFast(36,0);
  // Set I1-TIA (def)
  digitalWriteFast(38,1);
  delay(wait1);
  digitalWriteFast(38,0);
  // Set I2-TIA (def)
  digitalWriteFast(40,1);
  delay(wait1);
  digitalWriteFast(40,0);
  Error0();
}

activeNode ResetDevices(int wait2, activeNode &node) { // Reset all device relays to hold
  // Ensure the word relays are all set to hold
  for (int i = 0; i < 27; i++) {
    digitalWriteFast(1,muxTable[i][0]);
    digitalWriteFast(2,muxTable[i][1]);
    digitalWriteFast(3,muxTable[i][2]);
    digitalWriteFast(4,muxTable[i][3]);
    digitalWriteFast(5,muxTable[i][4]);
    digitalWriteFast(6,muxTable[i][5]);
    digitalWriteFast(16,1);
    delay(wait1);
    digitalWriteFast(16,0);
    delay(wait2);
  }

  //Serial.println("W-Deactivate");
  digitalWriteFast(1,0);
  digitalWriteFast(2,0);
  digitalWriteFast(3,0);
  digitalWriteFast(4,0);
  digitalWriteFast(5,0);
  digitalWriteFast(6,0);
  digitalWriteFast(15,0);
  digitalWriteFast(16,0);
  delay(wait2);

  // Ensure the bit relays are all set to hold
  for (int j = 0; j < 27; j++) {
    digitalWriteFast(7,muxTable[j][0]);
    digitalWriteFast(8,muxTable[j][1]);
    digitalWriteFast(9,muxTable[j][2]);
    digitalWriteFast(10,muxTable[j][3]);
    digitalWriteFast(11,muxTable[j][4]);
    digitalWriteFast(12,muxTable[j][5]);
    digitalWriteFast(18,1);
    delay(wait1);
    digitalWriteFast(18,0);
    delay(wait2);
  }

  //Serial.println("B-Deactivate");
  digitalWriteFast(7,0);
  digitalWriteFast(8,0);
  digitalWriteFast(9,0);
  digitalWriteFast(10,0);
  digitalWriteFast(11,0);
  digitalWriteFast(12,0);
  digitalWriteFast(17,0);
  digitalWriteFast(18,0);

  // Reset active node status
  node.wAct = 0; 
  node.bAct = 0;
  Error0();  
  return node;
}

activeNode ResetAll(int wait2, activeNode &node) {
  // Ensure all relays are set to defaults/hold
  // Set Hold TIA (def)
  digitalWriteFast(20,1);
  delay(wait1);
  digitalWriteFast(20,0);
  // Set Source Int (def)
  digitalWriteFast(22,1);
  delay(wait1);
  digitalWriteFast(22,0);
  // Set Drain Int (def)
  digitalWriteFast(24,1);
  delay(wait1);
  digitalWriteFast(24,0);
  // Set Hold Int (def)
  digitalWriteFast(26,1);
  delay(wait1);
  digitalWriteFast(26,0);
  // Set Gate Int (def)
  digitalWriteFast(28,1);
  delay(wait1);
  digitalWriteFast(28,0);
  // Set V1-Neg (def)
  digitalWriteFast(30,1);
  delay(wait1);
  digitalWriteFast(30,0);
  // Set V2-Neg (def)
  digitalWriteFast(32,1);
  delay(wait1);
  digitalWriteFast(32,0);
  // Set I1-Lo (def)
  digitalWriteFast(34,1);
  delay(wait1);
  digitalWriteFast(34,0);
  // Set I2-Lo (def)
  digitalWriteFast(36,1);
  delay(wait1);
  digitalWriteFast(36,0);
  // Set I1-TIA (def)
  digitalWriteFast(38,1);
  delay(wait1);
  digitalWriteFast(38,0);
  // Set I2-TIA (def)
  digitalWriteFast(40,1);
  delay(wait1);
  digitalWriteFast(40,0);

  // Ensure the word relays are all set to hold
  for (int i = 0; i < 27; i++) {
    digitalWriteFast(1,muxTable[i][0]);
    digitalWriteFast(2,muxTable[i][1]);
    digitalWriteFast(3,muxTable[i][2]);
    digitalWriteFast(4,muxTable[i][3]);
    digitalWriteFast(5,muxTable[i][4]);
    digitalWriteFast(6,muxTable[i][5]);
    digitalWriteFast(16,1);
    delay(wait1);
    digitalWriteFast(16,0);
    delay(wait2);
  }

  //Serial.println("W-Deactivate");
  digitalWriteFast(1,0);
  digitalWriteFast(2,0);
  digitalWriteFast(3,0);
  digitalWriteFast(4,0);
  digitalWriteFast(5,0);
  digitalWriteFast(6,0);
  digitalWriteFast(15,0);
  digitalWriteFast(16,0);
  delay(wait2);

  // Ensure the bit relays are all set to hold
  for (int j = 0; j < 27; j++) {
    digitalWriteFast(7,muxTable[j][0]);
    digitalWriteFast(8,muxTable[j][1]);
    digitalWriteFast(9,muxTable[j][2]);
    digitalWriteFast(10,muxTable[j][3]);
    digitalWriteFast(11,muxTable[j][4]);
    digitalWriteFast(12,muxTable[j][5]);
    digitalWriteFast(18,1);
    delay(wait1);
    digitalWriteFast(18,0);
    delay(wait2);
  }

  //Serial.println("B-Deactivate");
  digitalWriteFast(7,0);
  digitalWriteFast(8,0);
  digitalWriteFast(9,0);
  digitalWriteFast(10,0);
  digitalWriteFast(11,0);
  digitalWriteFast(12,0);
  digitalWriteFast(17,0);
  digitalWriteFast(18,0);

  // Reset active node status
  node.wAct = 0; 
  node.bAct = 0;
  Error0();
  return node;
}

activeNode DRT(int wait2,int wait3,int wait4, activeNode &node) { // Device Relay Test
  // Begin Device Set -- Words first

  // Ensure the word relays are all set to hold
  for (int i = 0; i < 27; i++) {
    digitalWriteFast(1,muxTable[i][0]);
    digitalWriteFast(2,muxTable[i][1]);
    digitalWriteFast(3,muxTable[i][2]);
    digitalWriteFast(4,muxTable[i][3]);
    digitalWriteFast(5,muxTable[i][4]);
    digitalWriteFast(6,muxTable[i][5]);
    digitalWriteFast(15,1);
    delay(wait1);
    digitalWriteFast(15,0);
    delay(wait2);
    digitalWriteFast(16,1);
    delay(wait1);
    digitalWriteFast(16,0);
    delay(wait3);
  }

  //Serial.println("W-Deactivate");
  digitalWriteFast(1,0);
  digitalWriteFast(2,0);
  digitalWriteFast(3,0);
  digitalWriteFast(4,0);
  digitalWriteFast(5,0);
  digitalWriteFast(6,0);
  digitalWriteFast(15,0);
  digitalWriteFast(16,0);
  delay(wait4);

  // Begin Device Set -- Bits second

  // Ensure the bit relays are all set to hold
  for (int j = 0; j < 27; j++) {
    digitalWriteFast(7,muxTable[j][0]);
    digitalWriteFast(8,muxTable[j][1]);
    digitalWriteFast(9,muxTable[j][2]);
    digitalWriteFast(10,muxTable[j][3]);
    digitalWriteFast(11,muxTable[j][4]);
    digitalWriteFast(12,muxTable[j][5]);
    digitalWriteFast(17,1);
    delay(wait1);
    digitalWriteFast(17,0);
    delay(wait2);
    digitalWriteFast(18,1);
    delay(wait1);
    digitalWriteFast(18,0);
    delay(wait3);
  }

  //Serial.println("B-Deactivate");
  digitalWriteFast(7,0);
  digitalWriteFast(8,0);
  digitalWriteFast(9,0);
  digitalWriteFast(10,0);
  digitalWriteFast(11,0);
  digitalWriteFast(12,0);
  digitalWriteFast(17,0);
  digitalWriteFast(18,0);

  // Reset active node status
  node.wAct = 0; 
  node.bAct = 0;
  Error0();
  return node;
}

void Error0() { // Process ok
  Serial.println("Error 0: OK");
}

void Error0a(activeNode node) { // Process ok but with information about the currently active node
  Serial.print("Active Node is: ");
  Serial.print(node.wAct);
  Serial.print(",");
  Serial.print(node.bAct);
  Serial.print(" --- ");
  Serial.println("Error 0a: OK");
}

void Error1() { // Invalid prefix handler
  Serial.println("Error 1: Invalid prefix");
}

void Error2() { // Invalid command handler
  Serial.println("Error 2: Invalid command");
}

void Error3() { // Relay out of range handler
  Serial.println("Error 3: Relay out of range");
}

void Error4() { // Attempt to activate more than one node
  Serial.println("Error 4: Another node is already active");
}

void Error5() { // Attempt to switch inactive node to hold
  Serial.println("Error 5: The requested node is not active");
}

void Error6() { // Attempt to switch inactive line to hold
  Serial.println("Error 6: The requested word/bit line to hold is not active");
}