int currentItemCount=15;

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



//handles reloading the select icon on the menu along with
//handling refreshing to load new pages
void updateMenu() {
  
  display.display(true);
}

