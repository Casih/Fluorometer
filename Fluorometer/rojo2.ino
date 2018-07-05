void rojo2(){
  // Serial.println("red2");
  //digitalWrite(RL, HIGH);    //Turn On red led
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("rfp mode:");
  lcd.setCursor(0,1);
  lcd.print("Insert sample");
  lcd.write(7);
  delay(1000);
  Getred();
  //digitalWrite(RL, LOW);    //Turn Off red led
  Color=1;
  Modo=2;
 }
