void verde(){
  //Serial.println("green");
  digitalWrite(BL, LOW);
  digitalWrite(RL, LOW);
  digitalWrite(GL, HIGH); 
  digitalWrite(ODL, LOW);   //Turn On red led
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("gfp mode:");
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
  Getgreen();   
  //digitalWrite(GL, LOW);    //Turn Off red led
  Color=2;
  Modo=2;
}

