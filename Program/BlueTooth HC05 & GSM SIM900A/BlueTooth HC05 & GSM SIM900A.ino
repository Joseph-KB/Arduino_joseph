#include <SoftwareSerial.h>

SoftwareSerial BlueTooth(9,10);
SoftwareSerial GsmSim(5,10);

void setup() {
  Serial.begin(9600);
  
  GsmSim.begin(9600);
  BlueTooth.begin(9600);
  Serial.println("Begin command initiated");
  
}

void loop() {
  delay(1500);
  Serial.println("Bluetooth available");
  Serial.println(BlueTooth.available());
  Serial.println(BlueTooth.read());

  Serial.println("GSM sim 900a available");
  Serial.println(GsmSim.available());
  Serial.println(GsmSim.read());
  // put your main code here, to run repeatedly:

}
void RecieveMessage(){
  GsmSim.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
  Serial.println("Message Recieving...");
  String GsmMsg;
  while(GsmSim.available()>0){
    GsmMsg=GsmSim.read();
    Serial.println(GsmMsg);
  }
  Serial.println(GsmMsg);

}
