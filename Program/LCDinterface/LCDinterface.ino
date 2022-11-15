#include <Wire.h>
 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3C,16,2);  // Find the address for lcd using i2scanner for a 16 chars and 2 line display

void setup()
{
  lcd.init();
  
  lcd.backlight();
  
  lcd.setCursor(0,0);
  
  lcd.print("Hello world!");

  lcd.setCursor(0,1);
    
  lcd.print("Do U hv Root Access");

}


void loop()
{
}
