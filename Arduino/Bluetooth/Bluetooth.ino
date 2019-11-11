#include <SoftwareSerial.h>

int ledPin=7;
int RxPin=3;
int TxPin=2;
SoftwareSerial HC06(RxPin,TxPin);

String Message;
char c;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  HC06.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  while(Serial.available()==0);
  char b=Serial.read();
  if (b=='1'){
    digitalWrite(ledPin,HIGH);
  }
  else if (b=='0'){
    digitalWrite(ledPin,LOW);
  }

  delay(100);
  */
  if (Serial.available()){
    c=Serial.read();
    HC06.write(c);
    Serial.print(">");
    Serial.write(c);
    Serial.print("\n");
  }
  if (HC06.available()){
    Serial.write(HC06.read());
    Serial.print("\n");
  }
}

