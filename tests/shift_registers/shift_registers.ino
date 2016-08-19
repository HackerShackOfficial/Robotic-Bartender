/*Sample sketch used to test shift registers. Since our relays rely
on grounding the vcc input, a 0 represents on and a 1 represents off
*/

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
 
byte relays = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}
 
void loop() 
{
  relays = 255;
  updateShiftRegister();
  delay(500);

  //we can even set individual pins.
  for (int i=0; i<8; i++) {
    bitClear(relays, i);
    updateShiftRegister();
    delay(500);
  }
}

//Uses the arduino 'shiftOut' function to set shift register output pins
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, MSBFIRST, relays);
   digitalWrite(latchPin, HIGH);
}
