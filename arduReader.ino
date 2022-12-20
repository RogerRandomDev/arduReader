//save shutdown helper
bool shutdown=false;
volatile bool fullRefresh=false;
volatile bool doUpdate=true;
#include "charged.h"
#include "display.h"

#include "input.h"

//used with SD module
//#include "reader.h"

//SD setup here

//page number for the sd files
uint16_t pageNum=0;
//how many items per page on the menu
const uint16_t pageItems=10;




//run when first booting
void setup() {
  //preps buttons and inputs
  initButtons();
  //preps display and settings for use
  prepDisplay();
  //will set up once i have the module
  //loadSD();
}
//scenes
//0=menu
//1=file
int curScene=0;
void loop() {
  //stops anything fragile from happening when power is low
  if(shutdown){drawLowPower();return;}
  
  if(doUpdate){    
    if(_moveBy!=0){moveSelect(_moveBy);}
    _moveBy=0;fullRefresh=false;doUpdate=false;
    updateMenu();
  }
  doUpdate=false;
  delay(200);
  
}


