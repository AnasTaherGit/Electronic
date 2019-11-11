int trigPin=13;
int echoPin=11;
float pingTime;
float speedOfSound;
float targetDistance=16.3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pingTime=pulseIn(echoPin,HIGH);

  speedOfSound=20000*targetDistance/pingTime;
  Serial.print("the speed of sound is ");
  Serial.print(speedOfSound);
  Serial.println(" m/s");
  delay(1000);
}
