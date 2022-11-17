#include <SoftwareSerial.h>

SoftwareSerial GsmSim(5,6);   //Tx(GsmSim900A)-->pin5(Rx of Arduino) &&& Rx(GsmSim900A)-->pin6(Tx of Arduino)

char value;
//   char msg;

void setup(){
  GsmSim.begin(9600); // setting baud rate of Gsm SIM 900
  Serial.begin(9600); // setting baud rate of serial monitor
  delay(100);
  Serial.println("Begin command initialised at 9600 baud rate");

}

void loop(){
  if (Serial.available()>0){
  value = Serial.read();    //For reading character from serial monitor ascii of s==115, r==114
  switch(value)
  {
    case 's':
      SendMessage();
      break;
    case 'r':
      RecieveMessage();
      break;
    case 'c':
      Call();
      break;
    case 'p':
      Status();
      break;
  }
  }
  
   if (GsmSim.available()>0)
     Serial.println("read");
     Serial.write(GsmSim.read());

}


void SendMessage(){
  GsmSim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  GsmSim.println("AT+CMGS=\"+916238283364\"\r"); // Replace x with mobile number
  delay(1000);
  GsmSim.println("I am SMS GSM Module");// The SMS text you want to send
  delay(100);
  GsmSim.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  Serial.println("Message Sending....");
}

void RecieveMessage(){
  GsmSim.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
  Serial.println("Message Recieving...");
//  String msg;
//  if (GsmSim.available()>0)
//  {
//    msg=GsmSim.read();
//    Serial.println(msg);
//  }

}

void Call(){
  GsmSim.println("ATD+916238283364;");
  delay(4000);
  GsmSim.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  Serial.println("Calling");
 }
 
void Status(){
  GsmSim.println("AT");
  delay(1000);
}
