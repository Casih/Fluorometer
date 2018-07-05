void bluel(){
  //Serial.println("blue");
  digitalWrite(BL, HIGH);
  digitalWrite(RL, LOW);
  digitalWrite(GL, LOW); 
  digitalWrite(ODL, LOW);    //Turn On red led
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("cfp mode:");
  lcd.setCursor(0,1);
  lcd.print("Insert Blank ");
  lcd.write(7);
  delay(100);
  ModoEn = digitalRead(Enter);
  while (ModoEn == HIGH){     
    ModoEn = digitalRead(Enter);        //waiting for enter
    }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("reading Blank.");
  lcd.setCursor(0,1);
  lcd.print("....");
  lcd.blink();
  GetBlank();
  Getblue();   
  //digitalWrite(BL, LOW);    //Turn Off red led
  Color=3;
  Modo=2;
}
