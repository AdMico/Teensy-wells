//
// Brought to Teensy-wells v1.0.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// Basic algorithm for testing all 14 control relays.
// It will cycle through bringing each relay one by one first to NO, then back to NC (default)
// Has no interaction with PyNE-wells code, it's purely for hardware test, and should be used with the Teensy in the MuxBox PCB.
//

int led13Pin = 13; // Bias Bits
int led14Pin = 14; // Bias Words (def)
int led15Pin = 15; // Word On
int led16Pin = 16; // Word Off (def)
int led17Pin = 17; // Bit On
int led18Pin = 18; // Bit Off (def)
int led19Pin = 19; // +5V Active
int led20Pin = 20; // +5V GND (def)
int led21Pin = 21; // Source Ext
int led22Pin = 22; // Source Int (def)
int led23Pin = 23; // Drain Ext
int led24Pin = 24; // Drain Int (def)
int led25Pin = 25; // Hold Ext
int led26Pin = 26; // Hold Int (def)
int led27Pin = 27; // Gate Ext
int led28Pin = 28; // Gate Int (def)
int led29Pin = 29; // V1-NonInv
int led30Pin = 30; // V1-Inv (def)
int led31Pin = 31; // V2-NonInv
int led32Pin = 32; // V2-Inv (def)
int led33Pin = 33; // I1-Hi
int led34Pin = 34; // I1-Lo (def)
int led35Pin = 35; // I2-Hi
int led36Pin = 36; // I2-Lo (def)
int led37Pin = 37; // I1-CSA
int led38Pin = 38; // I1-TIA (def)
int led39Pin = 39; // I2-CSA
int led40Pin = 40; // I2-TIA (def)
int wait1 = 10;
int wait2 = 500;
bool hasRun = false;

void setup() {
  Serial.begin(9600);
  // initialize the digital pins as outputs
  pinMode(led13Pin,OUTPUT); // Bias Bits
  pinMode(led14Pin,OUTPUT); // Bias Words (def)
  pinMode(led15Pin,OUTPUT); // Word On 
  pinMode(led16Pin,OUTPUT); // Word Off (def)
  pinMode(led17Pin,OUTPUT); // Bit On
  pinMode(led18Pin,OUTPUT); // Bit Off (def)
  pinMode(led19Pin,OUTPUT); // +5V Active
  pinMode(led20Pin,OUTPUT); // +5V GND (def)
  pinMode(led21Pin,OUTPUT); // Source Ext
  pinMode(led22Pin,OUTPUT); // Source Int (def)
  pinMode(led23Pin,OUTPUT); // Drain Ext
  pinMode(led24Pin,OUTPUT); // Drain Int (def)
  pinMode(led25Pin,OUTPUT); // Hold Ext
  pinMode(led26Pin,OUTPUT); // Hold Int (def)
  pinMode(led27Pin,OUTPUT); // Gate Ext
  pinMode(led28Pin,OUTPUT); // Gate Int (def)
  pinMode(led29Pin,OUTPUT); // V1-NonInv
  pinMode(led30Pin,OUTPUT); // V1-Inv (def)
  pinMode(led31Pin,OUTPUT); // V2-NonInv
  pinMode(led32Pin,OUTPUT); // V2-Inv (def)
  pinMode(led33Pin,OUTPUT); // I1-Hi
  pinMode(led34Pin,OUTPUT); // I1-Lo (def)
  pinMode(led35Pin,OUTPUT); // I2-Hi
  pinMode(led36Pin,OUTPUT); // I2-Lo (def)
  pinMode(led37Pin,OUTPUT); // I1-CSA
  pinMode(led38Pin,OUTPUT); // I1-TIA (def)
  pinMode(led39Pin,OUTPUT); // I2-CSA
  pinMode(led40Pin,OUTPUT); // I2-TIA (def)
}

void loop() {
  if (!hasRun)  {
    Serial.println("Bias Bits");
    digitalWrite(led13Pin,HIGH);
    delay(wait1);
    digitalWrite(led13Pin,LOW);
    delay(wait2);

    Serial.println("Bias Words");
    digitalWrite(led14Pin,HIGH);
    delay(wait1);
    digitalWrite(led14Pin,LOW);
    delay(wait2);

    Serial.println("Word On");
    digitalWrite(led15Pin,HIGH);
    delay(wait1);
    digitalWrite(led15Pin,LOW);
    delay(wait2);

    Serial.println("Word Off");
    digitalWrite(led16Pin,HIGH);
    delay(wait1);
    digitalWrite(led16Pin,LOW);
    delay(wait2);

    Serial.println("Bit On");
    digitalWrite(led17Pin,HIGH);
    delay(wait1);
    digitalWrite(led17Pin,LOW);
    delay(wait2);

    Serial.println("Bit Off");
    digitalWrite(led18Pin,HIGH);
    delay(wait1);
    digitalWrite(led18Pin,LOW);
    delay(wait2);

    Serial.println("+5V Active");
    digitalWrite(led19Pin,HIGH);
    delay(wait1);
    digitalWrite(led19Pin,LOW);
    delay(wait2);

    Serial.println("+5V GND");
    digitalWrite(led20Pin,HIGH);
    delay(wait1);
    digitalWrite(led20Pin,LOW);
    delay(wait2);

    Serial.println("Source Ext");
    digitalWrite(led21Pin,HIGH);
    delay(wait1);
    digitalWrite(led21Pin,LOW);
    delay(wait2);

    Serial.println("Source Int");
    digitalWrite(led22Pin,HIGH);
    delay(wait1);
    digitalWrite(led22Pin,LOW);
    delay(wait2);

    Serial.println("Drain Ext");
    digitalWrite(led23Pin,HIGH);
    delay(wait1);
    digitalWrite(led23Pin,LOW);
    delay(wait2);

    Serial.println("Drain Int");
    digitalWrite(led24Pin,HIGH);
    delay(wait1);
    digitalWrite(led24Pin,LOW);
    delay(wait2);

    Serial.println("Hold Ext");
    digitalWrite(led25Pin,HIGH);
    delay(wait1);
    digitalWrite(led25Pin,LOW);
    delay(wait2);

    Serial.println("Hold Int");
    digitalWrite(led26Pin,HIGH);
    delay(wait1);
    digitalWrite(led26Pin,LOW);
    delay(wait2);

    Serial.println("Gate Ext");
    digitalWrite(led27Pin,HIGH);
    delay(wait1);
    digitalWrite(led27Pin,LOW);
    delay(wait2);

    Serial.println("Gate Int");
    digitalWrite(led28Pin,HIGH);
    delay(wait1);
    digitalWrite(led28Pin,LOW);
    delay(wait2);

    Serial.println("V1-NonInv");
    digitalWrite(led29Pin,HIGH);
    delay(wait1);
    digitalWrite(led29Pin,LOW);
    delay(wait2);

    Serial.println("V1-Inv");
    digitalWrite(led30Pin,HIGH);
    delay(wait1);
    digitalWrite(led30Pin,LOW);
    delay(wait2);

    Serial.println("V2-NonInv");
    digitalWrite(led31Pin,HIGH);
    delay(wait1);
    digitalWrite(led31Pin,LOW);
    delay(wait2);

    Serial.println("V2-Inv");
    digitalWrite(led32Pin,HIGH);
    delay(wait1);
    digitalWrite(led32Pin,LOW);
    delay(wait2);

    Serial.println("I1-Hi");
    digitalWrite(led33Pin,HIGH);
    delay(wait1);
    digitalWrite(led33Pin,LOW);
    delay(wait2);

    Serial.println("I1-Lo");
    digitalWrite(led34Pin,HIGH);
    delay(wait1);
    digitalWrite(led34Pin,LOW);
    delay(wait2);

    Serial.println("I2-Hi");
    digitalWrite(led35Pin,HIGH);
    delay(wait1);
    digitalWrite(led35Pin,LOW);
    delay(wait2);

    Serial.println("I2-Lo");
    digitalWrite(led36Pin,HIGH);
    delay(wait1);
    digitalWrite(led36Pin,LOW);
    delay(wait2);

    Serial.println("I1-CSA");
    digitalWrite(led37Pin,HIGH);
    delay(wait1);
    digitalWrite(led37Pin,LOW);
    delay(wait2);

    Serial.println("I1-TIA");
    digitalWrite(led38Pin,HIGH);
    delay(wait1);
    digitalWrite(led38Pin,LOW);
    delay(wait2);

    Serial.println("I2-CSA");
    digitalWrite(led39Pin,HIGH);
    delay(wait1);
    digitalWrite(led39Pin,LOW);
    delay(wait2);

    Serial.println("I2-TIA");
    digitalWrite(led40Pin,HIGH);
    delay(wait1);
    digitalWrite(led40Pin,LOW);
    delay(wait2);

    hasRun = true;  
  }
}