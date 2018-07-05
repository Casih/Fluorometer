void OD2(){
  //Serial.println("OD2");
  //digitalWrite(ODL, HIGH);    //Turn On red led
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Modo OD:");
  lcd.setCursor(0,1);
  lcd.print("Enter Blank ");
  lcd.write(7);
  delay(100);
  ModoEn = digitalRead(Enter);
  while (ModoEn == HIGH){     
    ModoEn = digitalRead(Enter);        //waiting for enter
    }
  GetBlank();
  lcd.clear();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Mode OD:");
  lcd.setCursor(0,1);
  lcd.print("Insert sample");
  lcd.write(7);
  delay(1000);
  GetOD();
  Color=4;
  Modo=2;
 }
