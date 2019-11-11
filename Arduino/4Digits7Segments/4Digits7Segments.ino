int DataPin=2;
int LatchPin=3;
int ClockPin=4;
int DigitToDisplay[]={63,6,91,79,102,109,125,7,127,111};
int DigitsPin[4]={8,9,10,11};

void DisplayDigit(int i){
  digitalWrite(LatchPin,LOW);
  shiftOut(DataPin,ClockPin,MSBFIRST,DigitToDisplay[i]);
  digitalWrite(LatchPin,HIGH);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DataPin,OUTPUT);
  pinMode(LatchPin,OUTPUT);
  pinMode(ClockPin,OUTPUT);
  for (int i=0;i<4;i++){
    pinMode(DigitsPin[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int n,i=9999;i>=0;i--){
    Serial.print("Number :");
    Serial.println(i);
    for (int k=0;k<20;k++){
      n=i;
      for(int j=0;j<4;j++){
        digitalWrite(DigitsPin[j],LOW);
        DisplayDigit(n%10);
        n/=10;
        delay(3);
        digitalWrite(DigitsPin[j],HIGH);
        delay(2);
      }
    }
  }
}
