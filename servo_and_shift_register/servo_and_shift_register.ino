#include <Servo.h>
Servo myServo;

const int upButtonPin = 9;
const int downButtonPin = 10;
int upButtonState = 0;
int downButtonState = 0;
int lastUpButtonState = 0;
int lastDownButtonState = 0;
int buttonCounter = 0;

const int dataPin = 4;
const int latchPin = 5;
const int clockPin = 6;

byte byteArray[] = {B11111100,B01100000,B11011010,B11110010,B01100110,B10110110,B10111110,B11100000,B11111110,B11110110};


void setup() {
  pinMode(upButtonPin, INPUT);
  pinMode(downButtonPin, INPUT);

  pinMode(dataPin, OUTPUT);
  pinMode(latchPin,  OUTPUT);
  pinMode(clockPin, OUTPUT);

  myServo.attach(11);
  myServo.write(0);
  
  updateDisplay(0);
}

void loop() {
  upButtonState = digitalRead(upButtonPin);
  downButtonState = digitalRead(downButtonPin);

  if(upButtonState != lastUpButtonState){//When up button pressed
    if(upButtonState == HIGH){
      if(buttonCounter < 9){
        buttonCounter++;
      }
      updateDisplay(buttonCounter);  
    }  
    delay(50);
  }
  lastUpButtonState = upButtonState;
/////////////////////////////////////////////////////////////////////////
  if(downButtonState != lastDownButtonState){
    if(downButtonState == HIGH){
      if(buttonCounter > 0){
        buttonCounter--;
      }  
      updateDisplay(buttonCounter);
    }  
    delay(50);
  }
  lastDownButtonState = downButtonState;
/////////////////////////////////////////////////////////////////////////
  int setServo = map(buttonCounter, 0, 9, 95, 180); //Using 95, not 90, cause my servo is dumb
  myServo.write(setServo);
  delay(15);


  
}

void updateDisplay(int displayInt){//Writes to the display
  digitalWrite(latchPin, LOW); //Get ready for data
  shiftOut(dataPin, clockPin, LSBFIRST, byteArray[displayInt]); //Send data
  digitalWrite(latchPin, HIGH); //Update display
}
