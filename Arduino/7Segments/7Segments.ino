int DataPin=2;
int LatchPin=3;
int ClockPin=4;
int DigitToDisplay[]={63,6,91,79,102,109,125,7,127,111};

void setup() {
  // put your setup code here, to run once:
  pinMode(DataPin,OUTPUT);
  pinMode(LatchPin,OUTPUT);
  pinMode(ClockPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0;i<10;i++){
    digitalWrite(LatchPin,LOW);
    shiftOut(DataPin,ClockPin,MSBFIRST,DigitToDisplay[i]);
    digitalWrite(LatchPin,HIGH);
    delay(700);
  }
}
