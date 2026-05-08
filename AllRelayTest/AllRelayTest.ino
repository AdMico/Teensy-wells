//
// Brought to Teensy-wells v1.0.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// Basic algorithm for testing all 14 control relays.
// It will cycle through bringing each relay one by one first to NO, then back to NC (default)
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


int led13Pin = 13; // Bias Words (def)
int led14Pin = 14; // Bias Bits
int led15Pin = 15; // Word Off (def)
int led16Pin = 16; // Word On
int led17Pin = 17; // Bit Off (def)
int led18Pin = 18; // Bit On
int led19Pin = 19; // +5V GND (def)
int led20Pin = 20; // +5V Active
int led21Pin = 21; // Source Int (def)
int led22Pin = 22; // Source Ext
int led23Pin = 23; // Drain Int (def)
int led24Pin = 24; // Drain Ext
int led25Pin = 25; // Hold Int (def)
int led26Pin = 26; // Hold Ext
int led27Pin = 27; // Gate Int (def)
int led28Pin = 28; // Gate Ext
int led29Pin = 29; // V1-Inv (def)
int led30Pin = 30; // V1-NonInv
int led31Pin = 31; // V2-Inv (def)
int led32Pin = 32; // V2-NonInv
int led33Pin = 33; // I1-Lo (def)
int led34Pin = 34; // I1-Hi
int led35Pin = 35; // I2-Lo (def)
int led36Pin = 36; // I2-Hi
int led37Pin = 37; // I1-TIA (def)
int led38Pin = 38; // I1-CSA
int led39Pin = 39; // I2-TIA (def)
int led40Pin = 40; // I2-CSA
int wait1 = 10;
int wait2 = 500;
bool hasRun = false;

void setup() {
  Serial.begin(9600);
  // initialize the digital pins as outputs
  pinMode(led13Pin,OUTPUT);
  pinMode(led14Pin,OUTPUT);
  pinMode(led15Pin,OUTPUT); 
  pinMode(led16Pin,OUTPUT);
  pinMode(led17Pin,OUTPUT);
  pinMode(led18Pin,OUTPUT);
  pinMode(led19Pin,OUTPUT);
  pinMode(led20Pin,OUTPUT);
  pinMode(led21Pin,OUTPUT);
  pinMode(led22Pin,OUTPUT); 
  pinMode(led23Pin,OUTPUT);
  pinMode(led24Pin,OUTPUT);
  pinMode(led25Pin,OUTPUT);
  pinMode(led26Pin,OUTPUT);
  pinMode(led27Pin,OUTPUT);
  pinMode(led28Pin,OUTPUT);
  pinMode(led29Pin,OUTPUT);
  pinMode(led30Pin,OUTPUT);
  pinMode(led31Pin,OUTPUT);
  pinMode(led32Pin,OUTPUT);
  pinMode(led33Pin,OUTPUT);
  pinMode(led34Pin,OUTPUT);
  pinMode(led35Pin,OUTPUT);
  pinMode(led36Pin,OUTPUT);
  pinMode(led37Pin,OUTPUT);
  pinMode(led38Pin,OUTPUT);
  pinMode(led39Pin,OUTPUT);
  pinMode(led40Pin,OUTPUT);
}

void loop() {
  if (!hasRun)  {

    // Make sure the 5V power line is active, otherwise the other relays won't switch.
    Serial.println("+5V Active");
    digitalWrite(led20Pin,HIGH);
    delay(wait1);
    digitalWrite(led20Pin,LOW);
    delay(wait2);

    Serial.println("Bias Bits");
    digitalWrite(led14Pin,HIGH);
    delay(wait1);
    digitalWrite(led14Pin,LOW);
    delay(wait2);

    Serial.println("Bias Words (def)");
    digitalWrite(led13Pin,HIGH);
    delay(wait1);
    digitalWrite(led13Pin,LOW);
    delay(wait2);

    Serial.println("Word On");
    digitalWrite(led16Pin,HIGH);
    delay(wait1);
    digitalWrite(led16Pin,LOW);
    delay(wait2);

    Serial.println("Word Off (def)");
    digitalWrite(led15Pin,HIGH);
    delay(wait1);
    digitalWrite(led15Pin,LOW);
    delay(wait2);

    Serial.println("Bit On");
    digitalWrite(led18Pin,HIGH);
    delay(wait1);
    digitalWrite(led18Pin,LOW);
    delay(wait2);

    Serial.println("Bit Off (def)");
    digitalWrite(led17Pin,HIGH);
    delay(wait1);
    digitalWrite(led17Pin,LOW);
    delay(wait2);

    // Run these two reversed to ensure that all following relay tests run
    Serial.println("+5V GND (def)");
    digitalWrite(led19Pin,HIGH);
    delay(wait1);
    digitalWrite(led19Pin,LOW);
    delay(wait2);

    Serial.println("+5V Active");
    digitalWrite(led20Pin,HIGH);
    delay(wait1);
    digitalWrite(led20Pin,LOW);
    delay(wait2);

    Serial.println("Source Ext");
    digitalWrite(led22Pin,HIGH);
    delay(wait1);
    digitalWrite(led22Pin,LOW);
    delay(wait2);

    Serial.println("Source Int (def)");
    digitalWrite(led21Pin,HIGH);
    delay(wait1);
    digitalWrite(led21Pin,LOW);
    delay(wait2);

    Serial.println("Drain Ext");
    digitalWrite(led24Pin,HIGH);
    delay(wait1);
    digitalWrite(led24Pin,LOW);
    delay(wait2);

    Serial.println("Drain Int (def)");
    digitalWrite(led23Pin,HIGH);
    delay(wait1);
    digitalWrite(led23Pin,LOW);
    delay(wait2);

    Serial.println("Hold Ext");
    digitalWrite(led26Pin,HIGH);
    delay(wait1);
    digitalWrite(led26Pin,LOW);
    delay(wait2);

    Serial.println("Hold Int (def)");
    digitalWrite(led25Pin,HIGH);
    delay(wait1);
    digitalWrite(led25Pin,LOW);
    delay(wait2);

    Serial.println("Gate Ext");
    digitalWrite(led28Pin,HIGH);
    delay(wait1);
    digitalWrite(led28Pin,LOW);
    delay(wait2);

    Serial.println("Gate Int (def)");
    digitalWrite(led27Pin,HIGH);
    delay(wait1);
    digitalWrite(led27Pin,LOW);
    delay(wait2);

    Serial.println("V1-NonInv");
    digitalWrite(led30Pin,HIGH);
    delay(wait1);
    digitalWrite(led30Pin,LOW);
    delay(wait2);

    Serial.println("V1-Inv (def)");
    digitalWrite(led29Pin,HIGH);
    delay(wait1);
    digitalWrite(led29Pin,LOW);
    delay(wait2);

    Serial.println("V2-NonInv");
    digitalWrite(led32Pin,HIGH);
    delay(wait1);
    digitalWrite(led32Pin,LOW);
    delay(wait2);

    Serial.println("V2-Inv (def)");
    digitalWrite(led31Pin,HIGH);
    delay(wait1);
    digitalWrite(led31Pin,LOW);
    delay(wait2);

    Serial.println("I1-Hi");
    digitalWrite(led34Pin,HIGH);
    delay(wait1);
    digitalWrite(led34Pin,LOW);
    delay(wait2);

    Serial.println("I1-Lo (def)");
    digitalWrite(led33Pin,HIGH);
    delay(wait1);
    digitalWrite(led33Pin,LOW);
    delay(wait2);

    Serial.println("I2-Hi");
    digitalWrite(led36Pin,HIGH);
    delay(wait1);
    digitalWrite(led36Pin,LOW);
    delay(wait2);

    Serial.println("I2-Lo (def)");
    digitalWrite(led35Pin,HIGH);
    delay(wait1);
    digitalWrite(led35Pin,LOW);
    delay(wait2);

    Serial.println("I1-CSA");
    digitalWrite(led38Pin,HIGH);
    delay(wait1);
    digitalWrite(led38Pin,LOW);
    delay(wait2);

    Serial.println("I1-TIA (def)");
    digitalWrite(led37Pin,HIGH);
    delay(wait1);
    digitalWrite(led37Pin,LOW);
    delay(wait2);

    Serial.println("I2-CSA");
    digitalWrite(led40Pin,HIGH);
    delay(wait1);
    digitalWrite(led40Pin,LOW);
    delay(wait2);

    Serial.println("I2-TIA (def)");
    digitalWrite(led39Pin,HIGH);
    delay(wait1);
    digitalWrite(led39Pin,LOW);
    delay(wait2);

    hasRun = true;  
  }
}