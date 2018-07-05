#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <FreqCount.h>
#include <math.h>

LiquidCrystal_I2C lcd(0x27,16,2);
float Blank;
float Measurement;
float Bl_OD;   //Blank OD
float OD_Fin;
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
