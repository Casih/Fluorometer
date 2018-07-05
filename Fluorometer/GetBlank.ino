void GetBlank(){
   //Serial.println("GetBlank");
 if(FreqCount.available()){
  delay(1000);
  Blank = 0;
  for(int x = 0;x < 100; x ++){
  Blank += FreqCount.read();
  }
  Blank = Blank/100.0;
  lcd.noBlink();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Bl = ");
  lcd.print(Blank);
  lcd.setCursor(0,1);
  lcd.print("Insert sample");
  lcd.write(7);  //Enter
  lcd.setCursor(0,1);
//  Serial.print("Blank = ");
//  Serial.println(Blank);
  } 
}
