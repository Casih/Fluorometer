/*
  Fluorometer

 The circuit:
 https://github.com/Casih/Fluorometer/tree/master/Circuit

 created 2015
 by Carlos A. Sanchez & Ciro Gelvez 
 
 Modified 2017
 by Johnny Turizo & Carlos A. Sanchez

 
 */
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <FreqCount.h>
#include <math.h>

LiquidCrystal_I2C lcd(0x27,16,2);
signed long Blank;
signed long Measurement;
signed long Bl_OD;   //Blank OD
signed long OD_Fin;
int Modo = 0;
int Color = 0;
//Pin button definitions
const int red = 2;     // the number of the pushbutton pin red mode
const int green = 3;    // the number of the pushbutton pin green mode
const int blue = 4;     // the number of the pushbutton pin blue mode
const int OD = 6;       // the number of the pushbutton pin optical density mode
const int Enter = 7;    // the number of the pushbutton pin Enter
int ModoR = HIGH;
int ModoV = HIGH;
int ModoA = HIGH;
int ModoOD = HIGH;
int ModoEn = HIGH;
//LED pin definition
const int RL = 8;     // the number of the lED pin red mode
const int GL= 9;    // the number of the LED pin green mode
const int BL= 10;     // the number of the LED pin bluemode
const int ODL = 11;       // the number of the LED pin optical density mode
//***********************************************************************
int i;

void setup() {
  Serial.begin(9600);        // initialize serial communication:
  FreqCount.begin(1000);     //  //initialize frequency counter:
  // initialize the LED pins Sensor:
  pinMode(5, INPUT);         // Frequency reader
  pinMode(A0, OUTPUT);       // S0
  pinMode(A1, OUTPUT);       // S1
  pinMode(A2, OUTPUT);       // S2
  pinMode(A3, OUTPUT);       // S3
  //********LED's colors********
  pinMode(RL,OUTPUT);          //red
  pinMode(GL,OUTPUT);          //green
  pinMode(BL,OUTPUT);         //blue
  pinMode(ODL,OUTPUT);         //od
  digitalWrite(RL, LOW);    //
  digitalWrite(GL, LOW);    //
  digitalWrite(BL, LOW);    //
  digitalWrite(ODL, LOW);    //
  // Sensor off:
  digitalWrite(A0, HIGH);    //
  digitalWrite(A1, HIGH);    //
  //Button initialization
  pinMode(red, INPUT);
  pinMode(blue, INPUT);
  pinMode(green, INPUT);
  pinMode(OD, INPUT);
  pinMode(Enter, INPUT);
  int i = 0;
  // LCD screen setup
  lcd.init();                // 
  lcd.backlight();           //
  lcd.clear();               // 
  lcd.setCursor(0,0);        //
  lcd.print("Select mode:");  //
  lcd.setCursor(0,1);        //
  lcd.print("r, g ,c, OD");   //

  Serial.println("Blank,Measurement,Mode"); 
}

void loop() {
  ModoR = digitalRead(red);
  ModoV = digitalRead(green);
  ModoA = digitalRead(blue);
  ModoOD = digitalRead(OD);
  ModoEn = digitalRead(Enter);
  if (ModoR == LOW) {
    i=1;
    }
  if (ModoV == LOW) {
    i=2;
    }
  if (ModoA == LOW) {
    i=3;
    }
  if (ModoOD == LOW) {
    i=4;
    }
  if (ModoEn == LOW){
    i=5;
  }
// Cases
 switch (i) {
      case 1:
        Modo=1;
        rojo();
        i=0;
        break;
      case 2:
        Modo=1;
        verde();
        i=0;
        break;
      case 3:
        Modo=1;
        bluel();
        i=0;
        break;
      case 4:
        Modo=1;
        ODD();
        i=0;
        break;
      case 5:
        if(Modo==2){
          color();
          i=0;
        }
        break;
      default:
        break;
    }
  delay(100);
}

void color(){
  //Serial.println("color");
  switch (Color) {
    case 1:  
      rojo2();
      break;
    case 2:  
      verde2();
      break;
    case 3:  
      blue2();
      break;
    case 4:  
      OD2();
      break;
    default:
    break;
   }
}

void rojo(){
  //Serial.println("red");
  digitalWrite(RL, HIGH);    //Turn On red led
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
  digitalWrite(RL, LOW);    //Turn Off red led
  Color=1;
  Modo=2;
}

void rojo2(){
  // Serial.println("red2");
  digitalWrite(RL, HIGH);    //Turn On red led
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("rfp mode:");
  lcd.setCursor(0,1);
  lcd.print("Insert sample");
  lcd.write(7);
  delay(1000);
  Getred();
  digitalWrite(RL, LOW);    //Turn Off red led
  Color=1;
  Modo=2;
 }
 
void verde(){
  //Serial.println("green");
  digitalWrite(GL, HIGH);    //Turn On red led
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
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
  digitalWrite(GL, LOW);    //Turn Off red led
  Color=2;
  Modo=2;
}

void verde2(){
  //Serial.println("green2");
  digitalWrite(GL, HIGH);    //Turn On red led
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("gfp mode:");
  lcd.setCursor(0,1);
  lcd.print("Insert sample");
  lcd.write(7);
  delay(1000);
  Getgreen();
  digitalWrite(GL, LOW);    //Turn Off red led
  Color=2;
  Modo=2;
 }
 
void bluel(){
  //Serial.println("blue");
  digitalWrite(BL, HIGH);    //Turn On red led
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
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
  digitalWrite(BL, LOW);    //Turn Off red led
  Color=3;
  Modo=2;
}

void blue2(){
  //Serial.println("blue2");
  digitalWrite(BL, HIGH);    //Turn On red led
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("cfp mode:");
  lcd.setCursor(0,1);
  lcd.print("Insert sample");
  lcd.write(7);
  delay(1000);
  Getblue();
  digitalWrite(BL, LOW);    //Turn Off red led
  Color=3;
  Modo=2;
 }

void ODD(){
  //Serial.println("OD");
  digitalWrite(ODL, HIGH);    //Turn On red led
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
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
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Substracting blank.");
  lcd.setCursor(0,1);
  lcd.print("....");
  lcd.blink();
  GetBlankOD();
  GetOD();   
  digitalWrite(ODL, LOW);    //Turn Off red led
  Color=4;
  Modo=2;
}

void OD2(){
  //Serial.println("OD2");
  digitalWrite(ODL, HIGH);    //Turn On red led
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Modo OD:");
  lcd.setCursor(0,1);
  lcd.print("Insert sample");
  lcd.write(7);
  delay(1000);
  GetOD();
  digitalWrite(ODL, LOW);    //Turn Off red led
  Color=4;
  Modo=2;
 }

void GetBlankOD(){
   //Serial.println("GetBlank");
 if(FreqCount.available()){
  delay(1000);
  Bl_OD = FreqCount.read();
  lcd.noBlink();
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Insert Blank");
  lcd.write(7);  //Enter
  ModoEn = digitalRead(Enter);
  while (ModoEn == HIGH){     
    ModoEn = digitalRead(Enter);        //waiting for enter
    }
  GetBlank();
//  Serial.print("Blank = ");
//  Serial.println(Blank);
  } 
} 

void GetBlank(){
   //Serial.println("GetBlank");
 if(FreqCount.available()){
  delay(1000);
  Blank = FreqCount.read();
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

void Getred(){
   //Serial.println("Getred");
  ModoEn = digitalRead(Enter);
  while (ModoEn == HIGH){     
    ModoEn = digitalRead(Enter);        //waiting for enter
    }
  if(FreqCount.available()){
          lcd.clear();  
          lcd.setCursor(0,0);       
          lcd.print("reading red..");
          lcd.setCursor(0,1);
          lcd.print("....");
          lcd.blink();
          delay(1000);
          Measurement = FreqCount.read();
          lcd.noBlink();
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Med = ");
          lcd.print(Measurement); 
          lcd.setCursor(0,1);
          lcd.print("Red =");
          lcd.print(Measurement - Blank);
          Serial.print(Blank);
          Serial.print(",");
          Serial.print(Measurement - Blank);
          Serial.println(",red");     
          delay(500);
        }
}

void Getgreen(){
  ModoEn = digitalRead(Enter);
  while (ModoEn == HIGH){     
    ModoEn = digitalRead(Enter);        //waiting for enter
    }
  if(FreqCount.available()){
          lcd.clear();  
          lcd.setCursor(0,0);       
          lcd.print("reading green..");
          lcd.setCursor(0,1);
          lcd.print("....");
          lcd.blink();
          delay(1000);
          Measurement = FreqCount.read();
          lcd.noBlink();
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Med = ");
          lcd.print(Measurement);
          lcd.setCursor(0,1);
          lcd.print("green =");
          lcd.print(Measurement - Blank);
          Serial.print(Blank);
          Serial.print(",");
          Serial.print(Measurement - Blank);
          Serial.println(",green");    
          delay(500);
        }
}

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
          Measurement = FreqCount.read();
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

void GetOD(){
  ModoEn = digitalRead(Enter);
  while (ModoEn == HIGH){     
    ModoEn = digitalRead(Enter);        //waiting for enter
    }
  if(FreqCount.available()){
          lcd.clear();  
          lcd.setCursor(0,0);       
          lcd.print("reading OD..");
          lcd.setCursor(0,1);
          lcd.print("....");
          lcd.blink();
          delay(1000);
          Measurement = FreqCount.read();
          lcd.noBlink();
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Med = ");
          lcd.print(Measurement);
          lcd.setCursor(0,1);
          lcd.print("OD =");
          OD_Fin=- log10(Measurement/Bl_OD)-(-log10(Blank/Bl_OD));
          lcd.print(OD_Fin);
          Serial.print(Blank);
          Serial.print(",");
          Serial.print(OD_Fin);
          Serial.println(",OD");    
          delay(500);
        }
}
