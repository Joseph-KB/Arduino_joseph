#define led 5
#define button 2

int flag=0;

void setup() {
 Serial.begin(9600);
 pinMode(led,OUTPUT);
 pinMode(button,INPUT);
 
 digitalWrite(led,LOW);
}

void loop() {
  int but=digitalRead(button);
  Serial.println(but);
  
  delay(400);

  while(but==1){
    flag=!(flag);
    if(flag==1){
    digitalWrite(led,HIGH);
    }
    else{
      digitalWrite(led,LOW);
    }
    break;
  }
  

}
