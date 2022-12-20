

//pin ids
//format is UP,DOWN,CONFIRM,REFRESH
int buttonPins[4]={4,3,6,2};
volatile int _moveBy=0;

//button events

void buttonPressed(){
  doUpdate=false;int baseMoveBy=_moveBy;_moveBy=0;
  bool willUpdate=false;
  for(int i=0;i<4;i++){
    bool pressed=digitalRead(buttonPins[i])==LOW;
    willUpdate=willUpdate||pressed;
    if(pressed){
      _moveBy+=int(i<2)*(i*2-1);
      fullRefresh=fullRefresh||i==3;
        
    } 
    
  }
  if(_moveBy==0){_moveBy=baseMoveBy;}
  doUpdate=willUpdate;
}







//initializes the buttons to the device and adds the interrupt signals
void initButtons(){
  //cant use sizeof on the rp2040
  for(int i=0;i<4;i++){
    int buttonPin=buttonPins[i];
    pinMode(buttonPin, INPUT_PULLUP);
    //allows me to only need a ground connection
    digitalWrite(buttonPin,HIGH);
    attachInterrupt(digitalPinToInterrupt(buttonPin),buttonPressed,CHANGE);
  }
}
