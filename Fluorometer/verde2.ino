void verde2(){
  //Serial.println("green2");
  //digitalWrite(GL, HIGH);    //Turn On red led
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("gfp mode:");
  lcd.setCursor(0,1);
  lcd.print("Insert sample");
  lcd.write(7);
  delay(1000);
  Getgreen();
  //digitalWrite(GL, LOW);    //Turn Off red led
  Color=2;
  Modo=2;
 }
