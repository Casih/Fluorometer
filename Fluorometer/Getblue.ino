void Getblue(){
  ModoEn = digitalRead(Enter);
  while (ModoEn == HIGH){     
    ModoEn = digitalRead(Enter);        //waiting for enter
    }
  if(FreqCount.available()){
          lcd.clear();  
          lcd.setCursor(0,0);       
          lcd.print("reading blue..");
          lcd.setCursor(0,1);
          lcd.print("....");
          lcd.blink();
          delay(1000);
          Measurement = 0;
          for(int x = 0;x < 100; x ++){
          Measurement += FreqCount.read();
          }
          Measurement = Measurement/100.0;
          lcd.noBlink();
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Med = ");
          lcd.print(Measurement);
          lcd.setCursor(0,1);
          lcd.print("blue =");
          lcd.print(Measurement - Blank);
          Serial.print(Blank);
          Serial.print(",");
          Serial.print(Measurement - Blank);
          Serial.println(",blue");    
          delay(500);
        }
}
