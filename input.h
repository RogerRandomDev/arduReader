

//pin ids
//format is UP,DOWN,CONFIRM
int buttonPins[3]={2,6,3};
int btn_prev[3]={0,0,0};
bool justPressed[3]={false,false,false};

//handlers
void onUp(){justPressed[0]=true;}
void onDown(){justPressed[1]=true;}
void onConfirm(){justPressed[2]=true;}

//button events
void upPressed(){
  moveSelect(-1);
}
void downPressed(){
  moveSelect(1);
}

void confirmPressed(){
  
}







//initializes the buttons to the device and adds the interrupt signals
void initButtons(){
  //cant use sizeof on the rp2040
  for(int i=0;i<3;i++){
    int buttonPin=buttonPins[i];
    pinMode(buttonPin, INPUT_PULLUP);
    //allows me to only need a ground connection
    digitalWrite(buttonPin,HIGH);
  }
  attachInterrupt(digitalPinToInterrupt(buttonPins[0]),onUp,RISING);
  attachInterrupt(digitalPinToInterrupt(buttonPins[1]),onDown,RISING);
  attachInterrupt(digitalPinToInterrupt(buttonPins[2]),onConfirm,RISING);
}
void disablePressed(){
  justPressed[0]=false;
  justPressed[1]=false;
  justPressed[2]=false;
}
void updateTriggers(){
  if(justPressed[0]){upPressed();justPressed[0]=false;doUpdate=true;}
  if(justPressed[1]){downPressed();justPressed[1]=false;doUpdate=true;}
  if(justPressed[2]){confirmPressed();justPressed[2]=false;doUpdate=true;}
}