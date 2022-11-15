//RoboIndia Code for HC-05 with AT Mode
//https://www.roboindia.com/tutorials


// dont connect enable pin.. connect RX of HC-05 to pin6 and TX of HC-05 to pin5


#include <SoftwareSerial.h>

SoftwareSerial BTSerial(5, 6); // RX | TX

void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);       // HC-05 default speed in AT command more
}

void loop()
{
  if (BTSerial.available())    // read from HC-05 and send to Arduino Serial Monitor
  Serial.write(BTSerial.read());

  if (Serial.available())     // Keep reading from Arduino Serial Monitor and send to HC-05
  BTSerial.write(Serial.read());
}
