
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(9, 10); //TXD of blueModule to PIN_9(RX), RXD of blueModule to PIN_10(TX)

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3C,16,2);  // Find the address for lcd using i2scanner for a 16 chars and 2 line display


#define Switch_1 13   //for master light
#define Switch_2 12
#define Switch_3 11
#define Switch_4 8
#define Switch_5 7
#define Switch_6 6
#define Switch_7 5
#define Switch_8 4
#define Switch_9 3
#define Switch_10 2


// for bluetooth data
String data = "";
String buff = "";
char ret = '\r';
char newline = '\n';


void setup() {
  //LCD initialisation
  lcd.init();
  lcd.backlight();  
  lcd.setCursor(3,0);  
  lcd.print("SemiAutoHome");
  lcd.setCursor(5,1);    
  lcd.print("Project");

  //Bluetooth HC-05 initalisation
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for command...........");
  Bluetooth.write("Send on or off to Switch_1");
  pinMode(Switch_1, OUTPUT);

}


void loop() {
  delay(600);

  // Concatenating the characters recieved through bluetooth
  while (Bluetooth.available() > 0)
  {
    char character = Bluetooth.read();
    Serial.println(character);
    if ((character != newline) && (character != ret))
    {
      buff.concat(character);
    }
    data = buff;
  }


  Serial.println(data);
  if (data == "lights on") {
    digitalWrite(Switch_1, 1);  //for master light1 ON
    buff = "";
  }
  else if (data == "lights off") {
    digitalWrite(Switch_1, 0);  //for master light1 OFF
    buff = "";
  }


}
