
bool doUpdate=true;
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
  Serial.begin(115200);
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
  
  updateTriggers();
  //only updates on changes
  if(doUpdate){
    switch(curScene){
      case(0):updateMenu();break;
      //should be updatePage or something
      case(1):updateMenu();break;
    }
    disablePressed();
    doUpdate=false;}
    
  //sleep until interrupt recieved from user input
  delay(50);
}


