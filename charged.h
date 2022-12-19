
//reads current percentage of battery
float readPercentage() {
  int value = 0;float voltage;float perc;
  value = analogRead(A0);
  voltage = value * 5.0/1023;
  perc = map(voltage, 3.4, 4.2, 0, 100);
  Serial.print("Voltage= ");
  Serial.println(voltage);
  Serial.print("Battery level= ");
  Serial.print(perc);
  Serial.println(" %");
  return perc;
}


void updatePercentage() { 
  float val=readPercentage();
  //device is below 0, shut down safely
  if(val<=0.0) {
        shutdown=true;
  }
}