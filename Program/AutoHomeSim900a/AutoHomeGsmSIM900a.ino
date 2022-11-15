#include <SoftwareSerial.h>

SoftwareSerial gsmSim(5,6);   //Tx(gsmSim900A)-->pin5(Rx of Arduino) &&& Rx(gsmSim900A)-->pin6(Tx of Arduino)


#define pir 11  // input PIR motion sensor
#define gas 10  // input gas sensor MQ- 5
#define ldr 9   // input ldr sensor

String smsString;
String GSMdata;

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
  smsString="";
  GSMdata="";
  ReceiveMessage();
  delay(1000);
  if (smsString!=""){
    Serial.print("smsString-----");
    Serial.println(smsString);
  }
  smsString;
  Serial.println(smsString);
  mySerial.write(smsString.c_str());

  if(smsString=="r1 on all"){
    Serial.println("room is in on mode");
  }

  if(flag==0){
    SendMessage();
    flag=1;
  }


//  int motion=digitalRead(pir);
//  if(motion>0){
//    Serial.println("Motion detected in Room 2");
////    SendMessage();
//    delay(10000);
//  }
  

}

void ReceiveMessage(){
  gsmSim.println("AT+CMGF=1"); 
//  delay(1000);
//  gsmSim.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live 
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


void SendMessage(){
  gsmSim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  gsmSim.println("AT+CMGS=\"+916238283364\"\r"); // Replace x with mobile number
  delay(1000);
  gsmSim.println("Motion detected in room 2");// The SMS text you want to send
  delay(1000);
  gsmSim.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  Serial.println("Message Sending....");
}
