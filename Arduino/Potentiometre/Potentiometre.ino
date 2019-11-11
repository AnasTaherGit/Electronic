int potPen=A0;
int readValue;
int base=6;

float Voltage(long x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potPen,INPUT);
  //pinMode(base,OUTPUT);
  //analogWrite(base,5);
}

void loop() {
  // put your main code here, to run repeatedly:
  readValue=analogRead(potPen);
  Serial.print(readValue);
  delay(100);
}
