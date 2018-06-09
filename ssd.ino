  // make an array to save Sev Seg pin configuration of numbers

int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,0,0,1,1 }};   // 9

const int upButtonPin = 9;
const int downButtonPin = 10;
int upButtonState = 0;
int downButtonState = 0;
int lastUpButtonState = 0;
int lastDownButtonState = 0;
int buttonPushCounter = 0;
//function header
void Num_Write(int);

void setup() 
{ 
  // set pin modes
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(upButtonPin, INPUT);
  pinMode(downButtonPin, INPUT);
  Num_Write(0);
}

void loop() 
{
  upButtonState = digitalRead(upButtonPin);
  downButtonState = digitalRead(downButtonPin);

  if(upButtonState != lastUpButtonState){
    if(upButtonState == HIGH){
      if(buttonPushCounter < 9){
        buttonPushCounter++;
      } 
      Num_Write(buttonPushCounter);
    }  
    delay(50);
  }
  lastUpButtonState = upButtonState;

  if(downButtonState != lastDownButtonState){
    if(downButtonState == HIGH){
      if(buttonPushCounter > 0){
        buttonPushCounter--;
      }
      Num_Write(buttonPushCounter);
    }
    delay(50);
  }
  lastDownButtonState = downButtonState;
}

void Num_Write(int number) 
{
  int pin= 2;
  for (int j=0; j < 7; j++) {
   digitalWrite(pin, num_array[number][j]);
   pin++;
  }
}
