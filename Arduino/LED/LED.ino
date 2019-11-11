int yellowLED = 9;
int Time = 5000; 
void setup() {
  // put your setup code here, to run once:
  pinMode(yellowLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(Time);
  digitalWrite(yellowLED,HIGH);
}
