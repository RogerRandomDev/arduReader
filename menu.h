int currentItemCount=15;

//fully resets the screen for you
void fullWipe() {
  display.setFullWindow();
  display.firstPage();
  display.nextPage();
}
//draws options on the menu
void drawMenuOption(int line,char stringIn[]){
  line++;
  display.drawFastHLine(24,20+line*20,276,GxEPD_BLACK);
  display.setCursor(28,16+line*20);
  display.print(stringIn);
}

//draws menu buttons
void drawOptions() {
    char stringIn[]="testing string";
    for(int line=0;line<currentItemCount;line++){
      drawMenuOption(line,stringIn);
    }
    display.display();
}
//user menu to choose from text files on the sd card
void loadMenu() {
  fullWipe();
  display.setFullWindow();
  display.fillScreen(GxEPD_WHITE);
  char txt[] = "Choose File:";  
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(txt, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t x = (display.width() - tbw) / 2;
  //draws the top of the page
  display.setCursor(x,tbh+2);
  display.print(txt);
  display.drawFastVLine(24,16,384,GxEPD_BLACK);
  display.drawFastHLine(0,16,display.width(),GxEPD_BLACK);
  //draws the page contents
  drawOptions();
  
}
int selectLine=0;

//moves the select and redraws it
void moveSelect(int moveBy) {
  display.drawRect(6,24+selectLine*20,12,12,GxEPD_WHITE);
  selectLine=max(min(currentItemCount-1,selectLine+moveBy),0);
  display.drawRect(6,24+selectLine*20,12,12,GxEPD_BLACK);
  
}

void drawSelect(bool erase=false) {
  display.drawRect(6,24+selectLine*20,12,12,GxEPD_BLACK);
  
}
//draws when there is no sd loaded
void drawNoCardIn() {
  display.drawRect(0,0,300,400,GxEPD_WHITE);
  display.setTextSize(2);
  char noCard[]="No Card";
  char noCard2[]="Inserted";
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(noCard, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t x = (display.width() - tbw) / 2;
  uint16_t y = (display.height() - tbh) / 2;
  display.fillScreen(GxEPD_WHITE);
  display.setCursor(x, y);
  display.print(noCard);
  
  display.getTextBounds(noCard2, 0, 0, &tbx, &tby, &tbw, &tbh);
  x = (display.width() - tbw) / 2;
  y = (display.height() - tbh) / 2;
  display.setCursor(x-3,y+20);
  display.print(noCard2);
}
void drawLowPower() {
  display.setFullWindow();
  display.fillRect(0,0,300,400,GxEPD_BLACK);
  char lowPower[] = "BATTERY LOW";
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(lowPower, 0, 0, &tbx, &tby, &tbw, &tbh);
  int16_t x = (display.width() - tbw) / 2;
  int16_t y = (display.height() - tbh) / 2;
  display.setCursor(x,y);
  display.print(lowPower);
  display.display(true);
}

//handles reloading the select icon on the menu along with
//handling refreshing to load new pages
void updateMenu() {
  //updates the page
  display.display(true);
  //refreshes the whole page to remove ghosting if you have triggered it
  if(fullRefresh){display.refresh();}
  fullRefresh=false;
  
}

