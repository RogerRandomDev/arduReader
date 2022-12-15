#include <SPI.h>
#include <SD.h>
//PIN LAYOUT
//if it doesn't work, flip mosi and miso around
//mosi:11
//miso:12
//SCK:13
//CS: 10
Sd2Card card;
File myFile;

void loadSD() {
// Open serial communications and wait for port to open:
Serial.begin(9600);
while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}
Serial.print("Initializing SD card...");
if(!card.init(SPI_HALF_SPEED,4)){
  Serial.print("Fail2");
}
if (!SD.begin(10)) { //make sure sd card was found
    Serial.print("Fail");
    while (true);
}else{
  Serial.print("a");
}

}




//lists out the files for the current page of the menu
uint16_t listFiles(uint16_t page) {
  
  //returns the number of files on the page
  return 1;
}