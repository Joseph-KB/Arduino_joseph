#include <SoftwareSerial.h>

SoftwareSerial gsmSim(5,6);   //Tx(gsmSim900A)-->pin5(Rx of Arduino) &&& Rx(gsmSim900A)-->pin6(Tx of Arduino)


#define pir 11  // input PIR motion sensor
#define gas 10  // input gas sensor MQ- 5
#define ldr 9   // input ldr sensor


String message;

int pirCount=0;
int gasCount=0;


void setup(){
  gsmSim.begin(9600); // setting baud rate of Gsm SIM 900
  Serial.begin(9600); // setting baud rate of serial monitor
  delay(1000);
  
  Serial.println("Serial begin ---- Serial Monitor");

  pinMode(pir,INPUT);
  pinMode(gas,INPUT);
  pinMode(ldr,INPUT);
}


void loop(){
    int pirStatus=digitalRead(pir);
    int gasStatus=digitalRead(gas);
    int ldrStatus=digitalRead(ldr);
    delay(1000);
    Serial.println(pirStatus);
//    Serial.println(gasStatus);
    if(pirStatus==1){
      if (pirCount<=3){
      pirCount+=1;
      if (pirCount==3){
        message="Motion detected in room 2";
        SendMessage(message);
      }
      }
      delay(3500);
    }

    if(gasStatus==0){
      if (gasCount<=3){
      gasCount+=1;
      if (gasCount==3){
        message="Gas leakage detected in room 3";
        SendMessage(message);
      }
      }
      delay(3500);
    }

}





void SendMessage(String message){
  gsmSim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  gsmSim.println("AT+CMGS=\"+916238283364\"\r"); // Replace x with mobile number
  delay(1000);
  gsmSim.println(message);// The SMS text you want to send
  delay(1000);
  gsmSim.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  Serial.println("Message Sending...."+message);
}




String GSMdata="";
String smsString;
void ReceiveMessage(){
  gsmSim.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live 
  delay(1000);
  char GSMbuff;
  while(gsmSim.available()>0) {
    GSMbuff = gsmSim.read();
    GSMdata.concat(GSMbuff);
  }
  if (GSMdata.indexOf("+CMT:">=0)){
    smsString=GSMdata.substring(50);
  }
  smsString.toLowerCase();  
}
