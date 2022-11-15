// LDR light is present when light is present----- light-> 0,,, dark-> 1



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(5,INPUT);
}

void loop() {

  int lsrSen= digitalRead(5);
  Serial.println(lsrSen);
  float ldrAn=analogRead(A0);
  Serial.println(ldrAn);
  delay(1500);
  // put your main code here, to run repeatedly:

}
