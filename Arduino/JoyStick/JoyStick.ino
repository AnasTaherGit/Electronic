
int XPin=A0;
int YPin=A1;
int PushPin=7;
int X,Y,S;

void setup() {
  // put your setup code here, to run once:
  pinMode(PushPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  X=map(analogRead(XPin),0,1000,-50,50);
  Y=map(analogRead(YPin),0,1000,50,-50);
  //X=analogRead(XPin);
  //Y=analogRead(YPin);
  Serial.print("x = ");
  Serial.print(X);
  Serial.print(" y = ");
  Serial.println(Y);
  delay(100);
}
