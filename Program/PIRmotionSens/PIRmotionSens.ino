#define pir 6

int digi;

void setup(){
  Serial.begin(9600);
  pinMode(pir,INPUT);
    
}

void loop(){
  digi=digitalRead(pir);
  Serial.println("Motion Sensor value");
  Serial.println(digi);
  delay(2500);
}
