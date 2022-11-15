// connectin of 4 channel  12 relay module is as follows/
//Jumper is disconnected VCC x JD-Vcc
// JD-vv is connected to the 12V adapter's postive terminal
// Gnd is connected to 12V adapter's negative terminal
// Vcc is connected to arduino's 5V
//Other pins are connected as pins


//we have a low state operated relay

char value;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);

}

void loop() {

  value=Serial.read();
  if(value=='s'){
    digitalWrite(2,HIGH);
    Serial.println("s presssed for off in pin2");
  }
  else if(value=='r'){
    digitalWrite(2,LOW);
    Serial.println("r presssed for on in pin2");
  }

}
