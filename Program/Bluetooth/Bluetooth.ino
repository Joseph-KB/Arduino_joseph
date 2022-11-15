
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(9,10);  //TXD of blueModule to PIN_9(RX), RXD of blueModule to PIN_10(TX)

#define Switch_1 13

String data= "";
String buff="";
char ret='\r';
char newline='\n';


void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for command...........");
  Bluetooth.write("Send on or off to Switch_1");
  pinMode(Switch_1,OUTPUT);
}

void loop() {
  delay(600);
  while(Bluetooth.available()>0)
  {
    char character=Bluetooth.read();
    if((character !=newline) && (character !=ret))
    {
      buff.concat(character);
    }
   data=buff;
   data.toLowerCase();
  }
 Serial.println(data);
 if(data=="on"){
  digitalWrite(Switch_1,1);
  buff="";
 }
 else if(data=="off"){
 digitalWrite(Switch_1,0);
 buff="";
 }
 else{
  buff="";
 }
 
}
