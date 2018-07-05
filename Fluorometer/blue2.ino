void blue2(){
  //Serial.println("blue2");
  //digitalWrite(BL, HIGH);    //Turn On red led
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("cfp mode:");
  lcd.setCursor(0,1);
  lcd.print("Insert sample");
  lcd.write(7);
  delay(1000);
  Getblue();
  //digitalWrite(BL, LOW);    //Turn Off red led
  Color=3;
  Modo=2;
 }
