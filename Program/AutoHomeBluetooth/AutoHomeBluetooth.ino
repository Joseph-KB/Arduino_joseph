#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

SoftwareSerial blueTooth(9, 10); //TXD of blueModule to PIN_9(RX), RXD of blueModule to PIN_10(TX)


LiquidCrystal_I2C lcd(0x3E,16,2);  // Find the address(0x3c for lcd using i2scanner for a 16 chars and 2 line display

#define Relay1 2  //output  -- R1 light
#define Relay2 3  //output  -- R1 fan
#define Relay3 4  //output  -- R1 AC
#define Relay4 5 //output  -- R1 PowerPlug


#define button1 6 //input
#define button2 7 //input


// for bluetooth data concatenating
String BTdata = "";
String BTbuff = "";
char ret = '\r';
char newline = '\n';


void setup(){
  HomeScreen();
  Serial.begin(9600);
  blueTooth.begin(9600);
  delay(300);
 

  Serial.println("Serial begin -- Serial monitor");

  //output PINS
  pinMode(Relay1,OUTPUT);
  pinMode(Relay2,OUTPUT);
  pinMode(Relay3,OUTPUT);
  pinMode(Relay4,OUTPUT);

  digitalWrite(Relay1,LOW);
  digitalWrite(Relay2,LOW);
  digitalWrite(Relay3,LOW);
  digitalWrite(Relay4,LOW); 
  delay(200);
  digitalWrite(Relay1,HIGH);
  digitalWrite(Relay2,HIGH);
  digitalWrite(Relay3,HIGH);
  digitalWrite(Relay4,HIGH); 

  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  
}


void loop(){
  BTdata="";
  BTbuff="";  
  delay(700);
  int but1=digitalRead(button1);
  int but2=digitalRead(button2);
  while(blueTooth.available()>0){
    char character=blueTooth.read();
    if((character !=newline) && (character !=ret)){
      BTbuff.concat(character);
    }
   BTdata=BTbuff;
   BTdata.toLowerCase();
  }
 
  if(BTdata!=""){
    Serial.println(BTdata);
  }

  //Turn on command  ----low trigger activating relay we have
   if(BTdata=="room one light on" || BTdata=="room 1 light on"){
    digitalWrite(Relay1,LOW);
//    Serial.println("Room1 light ON");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("R1 Light ON");
    delay(1000);  
  }
  
  else if(BTdata=="room one fan on" || BTdata=="room 1 fan on"){
    digitalWrite(Relay2,LOW);
//    Serial.println("Room1 fan ON");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("R_ 1 Fan ON");
    delay(1000);
    
  }
  else if(BTdata=="room one ac on" || BTdata=="room 1 ac on"){
    digitalWrite(Relay3,LOW);
//    Serial.println("Room1 AC ON");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("R_ 1 AC ON");
    delay(1000);
    
  }

   else if(BTdata=="room one plug on" || BTdata=="room 1 plug on"){
    digitalWrite(Relay4,LOW);
//    Serial.println("Room1 plug ON");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("R_ 1 plug ON");
    delay(1000);
    
  }
  
  else if(BTdata=="room one turn on all" || BTdata=="room 1 turn on all"){
    digitalWrite(Relay1,LOW);
    digitalWrite(Relay2,LOW);
    digitalWrite(Relay3,LOW);
    digitalWrite(Relay4,LOW);
//    Serial.println("Room1 Full ON");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("R_ 1 Full ON");
    delay(1000);
  }

  
   // Turn off commands
   else if(BTdata=="room one light off" || BTdata=="room 1 light off"){
    digitalWrite(Relay1,HIGH);
//    Serial.println("Room1 light OFF");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("R_ 1 Light OFF");
    delay(1000);
  }
  
  else if(BTdata=="room one fan off" || BTdata=="room 1 fan off"){
    digitalWrite(Relay2,HIGH);
//    Serial.println("Room1 fan OFF");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("R_ 1 Fan OFF");
    delay(1000);
  }
  
  else if(BTdata=="room one ac off" || BTdata=="room 1 ac off"){
    digitalWrite(Relay3,HIGH);
//    Serial.println("Room1 light OFF");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("R_ 1 Light OFF");
    delay(1000);
  }

  else if(BTdata=="room one plug off" || BTdata=="room 1 plug off"){
    digitalWrite(Relay4,HIGH);
//    Serial.println("Room1 plug OFF");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("R_ 1 plug OFF");
    delay(1000);
  }
  
  else if(BTdata=="room one turn off all" || BTdata=="room 1 turn off all"){
    digitalWrite(Relay1,HIGH);
    digitalWrite(Relay2,HIGH);
    digitalWrite(Relay3,HIGH);
    digitalWrite(Relay4,HIGH);
//    Serial.println("Room1 Full OFF");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("R_ 1 Full OFF");
    delay(1000);
  }
  
  else{
    BTdata="";
  }
  HomeScreen();
  
}

void HomeScreen(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("I am AuToHoMe");
  lcd.setCursor(0,1);
  lcd.print("Welcome HomeUser");
  delay(1000);
}
