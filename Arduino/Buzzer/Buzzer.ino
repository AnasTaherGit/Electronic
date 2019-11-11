int Buzzer=7;

void setup() {
  // put your setup code here, to run once:
  pinMode(Buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int note=700;note<2000;note++){
    tone(Buzzer,note,125);
    delay(5);
  }
  for (int note=2000;note>=700;note--){
    tone(Buzzer,note,125);
    delay(5);
  }
}
