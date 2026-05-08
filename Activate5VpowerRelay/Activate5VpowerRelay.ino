//
// Brought to Teensy-wells v1.0.0 on Wed May 05 2026 by APM
//
// @developers: Adam Micolich
//
// Basic algorithm for switching on +5V power to Muxbox PCB.
// It will flip the K-P relay to NO then stop.
// Has no interaction with PyNE-wells code, it's purely for hardware test, and should be used with the Teensy in the MuxBox.
//
// APM 08MAY26 -- Need to fix GPIO map in future instance when I fix the BC847 issue on the MuxBox PCB.

int led1Pin = 20; // +5V Active

int wait1 = 500;
int wait2 = 500;
bool hasRun = false;

void setup() {
  // initialize the digital pins as outputs
  pinMode(led1Pin,OUTPUT);
}

void loop() {
  if (!hasRun)  {
    digitalWrite(led1Pin,HIGH);
    delay(wait1);
    digitalWrite(led1Pin,LOW);
    delay(wait2);

    hasRun = true;
  }
}