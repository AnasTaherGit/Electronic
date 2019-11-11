int DataPin=2;
int LatchPin=3;
int ClockPin=4;
int ScrollNumber=0;
int Pattern[]={0x00,0x1E,0x10,0x10,0x1E,0x10,0x10,0x1E};
int Heart[]={0x0,0x66,0xDB,0x81,0x42,0x24,0x18,0x0};

void Refresh(){
  digitalWrite(LatchPin,LOW);
  shiftOut(DataPin,ClockPin,MSBFIRST,0);
  shiftOut(DataPin,ClockPin,MSBFIRST,255);
  digitalWrite(LatchPin,HIGH);
}

void Draw(int* Pattern){
  for (int i=0;i<8;i++){
    digitalWrite(LatchPin,LOW);
    shiftOut(DataPin,ClockPin,LSBFIRST,(Pattern[i]>>ScrollNumber)|(Pattern[i]<<(8-ScrollNumber)));
    shiftOut(DataPin,ClockPin,MSBFIRST,~(1<<i));
    digitalWrite(LatchPin,HIGH); 
    delayMicroseconds(100);
    //delay(100);
  }
}

void Scroll(){
  ScrollNumber++;
  if (ScrollNumber==8){
    ScrollNumber=0;
  }
}

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(DataPin,OUTPUT);
  pinMode(LatchPin,OUTPUT);
  pinMode(ClockPin,OUTPUT);
  Refresh();
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  for( int i=0;i<200;i++){
    Draw(Heart);
    //Draw(Pattern);
  }
  //Scroll();
}
