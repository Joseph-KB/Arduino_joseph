// absence of gas---1     presence of gas -- 0


#define AGasSens A0
#define DGasSens 4

int digi;
float val;

void setup() {
  pinMode(AGasSens,INPUT);
  pinMode(DGasSens,INPUT);
  Serial.begin(9600);

}

void loop() {
  val = analogRead(AGasSens);
  Serial.println("Analog value of MQ 5 is : ");
  Serial.println(val);
  digi=digitalRead(DGasSens);
  Serial.println("Digital value of MQ 5 is :");
  Serial.println(digi);
  delay(2500);
  // put your main code here, to run repeatedly:

}
