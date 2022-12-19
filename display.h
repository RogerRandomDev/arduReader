//handles all display-related functions for me


//will need to be changed off of GxEPD2
//since it is slow and made for the normal arduinos
//i'll have enough ram on the rp_2040 that i won't care though
#include <GxEPD2.h>
#include <GxEPD2_BW.h>
#include <Fonts/FreeMono9pt7b.h>

//d# that the CS pin connects to
#define EPD_CS 10
// adapt the constructor parameters to your wiring
#define GxEPD2_DISPLAY_CLASS GxEPD2_BW
#define GxEPD2_DRIVER_CLASS GxEPD2_420     // GDEW042T2   400x300, UC8176 (IL0398)
#define MAX_DISPLAY_BUFFER_SIZE 131072ul // e.g. half of available ram
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))
GxEPD2_DISPLAY_CLASS<GxEPD2_DRIVER_CLASS, MAX_HEIGHT(GxEPD2_DRIVER_CLASS)> display(GxEPD2_DRIVER_CLASS(/*CS=4*/ EPD_CS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7));




//font
#include "bitmaps/Bitmaps400x300.h" // 4.2"  b/w



//the menu file
#include "menu.h"






//boot screen for when first powering on
void bootScreen() {
  fullWipe();
  display.setFullWindow();
  display.setTextSize(2);
  char bootSplash[]="arduReader";
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(bootSplash, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t x = (display.width() - tbw) / 2;
  uint16_t y = (display.height() - tbh) / 2;
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(bootSplash);
  }
  while (display.nextPage());
  //boot screen time :D
  delay(3000);
}



//loads the bootscreen then the menu
void prepDisplay() {
  //reset display for 10ms
  display.init(115200);
  display.setRotation(1);
  display.setTextWrap(true);
  display.setTextSize(1);
  
  //move to first page
  display.firstPage();
  //font and text color
  display.setFont(&FreeMono9pt7b);
  display.setTextColor(GxEPD_BLACK);
  //shows bootscreen
  bootScreen();
  display.setTextSize(1);
  //now loads the menu screen
  loadMenu();
}


