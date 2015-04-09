#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <FreqCount.h>

LiquidCrystal_I2C lcd(0x27,16,2);
unsigned long count;
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin
int i;
int inByte;
// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  // initialize serial communication:
  Serial.begin(9600);        //
  
  //initialize frequency counter:
  FreqCount.begin(1000);     // 
  
  // initialize the LED pins:
  pinMode(5, INPUT);         // LECTOR DE FRECUENCIA
  pinMode(A0, OUTPUT);       // S0
  pinMode(A1, OUTPUT);       // S1
  pinMode(A2, OUTPUT);       // S2
  pinMode(A3, OUTPUT);       // S3
  
  // Sensor en apagado:
  digitalWrite(A0, HIGH);    //
  digitalWrite(A1, HIGH);    //
  
  // initialize lcd screen
  
  lcd.init();                //
  lcd.backlight();           //
  lcd.clear();               // 
  lcd.setCursor(0,0);        //
  lcd.print("Seleccione:");  //
  lcd.setCursor(0,1);        //
  lcd.print("R, G, C, O");   //
  
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  int i = 0;
}
void mostrar()
{
  if(FreqCount.available()){
          count = FreqCount.read();
          lcd.setCursor(0,1);
          lcd.print(count);
          Serial.println(count);
        }
}
void rojo()
{
  lcd.clear();
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  lcd.setCursor(0,0);
  lcd.print("Rojo:");
  mostrar();
  //delay(4000);
}
void verde()
{
  lcd.clear();
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Verde:");
  mostrar();
  //delay(4000);      
}
void azul()
{
  lcd.clear();
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Cyan:");
  mostrar();
  //delay(4000);
}
void OD()
{
  lcd.clear();
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  lcd.setCursor(0,0);
  lcd.print("Densidad Optica");
  mostrar();
  //delay(4000);
}
void def()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Seleccione:");
  lcd.setCursor(0,1);
  lcd.print("R, G, C, O");
}
void loop() 
{
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) 
  {
    if (reading != buttonState) 
    {
      buttonState = reading;
      i++;
      Serial.println(i);
    }
    //if(i==1) inByte = 'G';
    //if(i==2) inByte = 'R';
    //if(i==3) inByte = 'C';
    //if(i==4) inByte = 'O';
    if(i==6)
    {
    i=0;
    }    
    switch (i) 
    {
      case 2:
      {
        rojo();
        delay(1000);
        break;
      }  
      case 3:
      {
        verde();
        delay(1000);
        break;
      }
      case 4: 
      {
        azul();
        delay(1000);
        break;
      }
      case 5:
      {
        OD();
        delay(1000);
        break;
      }
      default:
      {
        def();
      }
    }delay(1000);
  }
  lastButtonState = reading;
}

