//libraries for LCD Display 
#include <LiquidCrystal.h> 
// Define LCD display pins
LiquidCrystal lcd(12,11,10,9,8,7);
// DeUfine 4 channel relay pins
const int Light = 13; // Relay pin 1 (IN1)
const int Fan = 5;   // Relay pin 2 (IN2)
const int TV = 4;    // Relay pin 3 (IN3)
const int Pump = 3;  // Relay pin 4 (IN4)

String data; //Variable for storing received data
 
 void setup()
  {
   Serial.begin(9600); //Sets the baud for serial data transmission
   // Set Relay pins as OUTPUT 
   pinMode(Light, OUTPUT);
   pinMode(Fan, OUTPUT);
   pinMode(TV, OUTPUT);
   pinMode(Pump, OUTPUT);
   // Print massage on LCD Display
   lcd.begin(16, 2);
   lcd.setCursor(0,0);
   lcd.print("Voice Controlled");
   lcd.setCursor(0,1);
   lcd.print("Home Automation");
   delay(2000);
   // All devics are Off when system is on 
   digitalWrite(Light, HIGH);
   digitalWrite(Fan, HIGH);
   digitalWrite(TV, HIGH);
   digitalWrite(Pump, HIGH);
   // Print Device status (all Off) on LCD Display
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print(" D1  D2  D3  D4 ");
   lcd.setCursor(0,1);
   lcd.print("OFF OFF  OFF OFF");
   
  }
 
 void loop()
  {
    // Read data from Bluetooth Module
    char ch=0;
    data="";
    while(1)
    { 
      while(Serial.available()<=0);
      ch = Serial.read();
      if(ch=='#')
      break;
      data+=ch;
    }
    
 // Print Bluetooth Module data on serial monitor
   Serial.print(data); 
   Serial.print("\n");

// Control the devices using voice command
    if (data == "*turn on light") // turn on Device1
    {
      digitalWrite(Light, HIGH);
      lcd.setCursor(0,1);
      lcd.print("ON ");
      delay(200);
    }
    
  else if (data== "*turn off light") // turn off Device1
    {
      digitalWrite(Light, LOW);
      lcd.setCursor(0,1);
      lcd.print("OFF");
      delay(200);
    }
    
  else if (data== "*turn on fan" ) // turn on Device2
    {
     digitalWrite(Fan, LOW);
     lcd.setCursor(4,1);
     lcd.print("ON ");
     delay(200);
    }
    
  else if (data== "*turn off fan" ) // turn off Device2
    {
     digitalWrite(Fan, HIGH);
     lcd.setCursor(4,1);
     lcd.print("OFF");
     delay(200);
    }
  else if (data== "*turn on TV" ) // turn on Device3
    {
      digitalWrite(TV, LOW);
      lcd.setCursor(9,1);
      lcd.print("ON");
      delay(200);
    }
  else if (data== "*turn off TV" ) // turn off Device3
    {
     digitalWrite(TV, HIGH);
     lcd.setCursor(9,1);
     lcd.print("OFF");
     delay(200);
    }
  else if (data== "*turn on pump" ) // turn on Device4
    {
      digitalWrite(Pump, LOW);
      lcd.setCursor(13,1);
      lcd.print("ON    ");
      delay(200);
    }
  else if (data== "*turn off pump" ) // turn off Device4
    {
      digitalWrite(Pump, HIGH);
      lcd.setCursor(13,1);
      lcd.print("OFF");
      delay(200);
    }    

  else if (data== "*turn on all" ) // turn on all Device
    {
      digitalWrite(Light, LOW);
      digitalWrite(Fan, LOW);
      digitalWrite(TV, LOW);
      digitalWrite(Pump, LOW);
      lcd.setCursor(0,1);
      lcd.print("ON  ON   ON  ON ");
      delay(200);
    }
  else if (data== "*turn off all" ) // turn off all Device
    {
      digitalWrite(Light, HIGH);
      digitalWrite(Fan, HIGH);
      digitalWrite(TV, HIGH);
      digitalWrite(Pump, HIGH);

      lcd.setCursor(0,1);
      lcd.print("OFF OFF  OFF OFF");
      delay(200);
    }    
 } 
