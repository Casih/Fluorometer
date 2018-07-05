void rojo(){
  //Serial.println("red");
  digitalWrite(BL, LOW);
  digitalWrite(RL, HIGH);
  digitalWrite(GL, LOW); 
  digitalWrite(ODL, LOW);    //Turn On red led
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("rfp mode:");
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
  Getred();   
  //digitalWrite(RL, LOW);    //Turn Off red led
  Color=1;
  Modo=2;
}
