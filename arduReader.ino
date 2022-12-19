//save shutdown helper
bool shutdown=false;
bool fullRefresh=false;
bool doUpdate=true;
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
  Serial.end();
}
//scenes
//0=menu
//1=file
int curScene=0;
void loop() {
  //stops anything fragile from happening when power is low
  if(shutdown){drawLowPower();return;}
  if(doUpdate){    
    doUpdate=false;
    moveSelect(_moveBy);
    _moveBy=0;
    updateMenu();
    fullRefresh=false;
  }
  delay(200);
  
}


