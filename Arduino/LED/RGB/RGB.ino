int Red =3;
int Green=5;
int Blue =6;

void setup() {
  // put your setup code here, to run once:
  pinMode(Red,OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);
  analogWrite(Red,0);
  analogWrite(Green,90);
  analogWrite(Blue,30);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
