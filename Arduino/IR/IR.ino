#include <IRremote.h>

int RECV_PIN = 7;
int LED_PIN = 9;
bool flag=true;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  pinMode(RECV_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);
  irrecv.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)){
    Serial.println(results.value,HEX);
    if (results.value==0x2008A857){
      if (flag){
      digitalWrite(LED_PIN,HIGH);
      flag=false;
      }
      else {
        digitalWrite(LED_PIN,LOW);
        flag=true;
      }
    }
    //0x200808F7
    irrecv.resume();
  }
}
