#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "SSID"
#define STAPSK  "MDP"
#endif

int Enable =3;
int Motor_1_pos =5;
int Motor_1_neg =16;
int Motor_2_pos =0;
int Motor_2_neg =2;
bool Enabled =false;

const char* ssid = STASSID;
const char* password = STAPSK;

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // Pin for Enabling motors
  pinMode(Enable, OUTPUT);
  digitalWrite(Enable, 0);
  // Motors Pins
  pinMode(Motor_1_pos, OUTPUT);
  pinMode(Motor_1_neg, OUTPUT);
  digitalWrite(Motor_1_pos, LOW);
  digitalWrite(Motor_1_neg, LOW);
  pinMode(Motor_2_pos, OUTPUT);
  pinMode(Motor_2_neg, OUTPUT);
  digitalWrite(Motor_2_pos, LOW);
  digitalWrite(Motor_2_neg, LOW);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print(F("Connecting to "));
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));

  // Start the server
  server.begin();
  Serial.println(F("Server started"));

  // Print the IP address
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println(F("new client"));

  client.setTimeout(5000); // default is 1000

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(F("request: "));
  Serial.println(req);

  // Match the request
  if (req.indexOf(F("/Enable/OFF")) != -1) {
    Enabled = false;
  } 
  else if (req.indexOf(F("/Enable/ON")) != -1) {
    Enabled = true;
  }
  else if (req.indexOf(F("/Forward"))!=-1){
    if (Enabled) Forward();
  }
  else if (req.indexOf(F("/Left"))!=-1){
    if (Enabled) Left();
  }
  else if (req.indexOf(F("/Right"))!=-1){
    if (Enabled) Right();
  }
  else if (req.indexOf(F("/Back"))!=-1){
    if (Enabled) Back();
  }
  else if (req.indexOf(F("/Stop"))!=-1){
    Stop();
  }
  else {
    Serial.println(F("invalid request"));
  }

  while (client.available()) {
    // byte by byte is not very efficient
    client.read();
  }
  client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n<head>"));
  client.print(F("<title>My ROBOT</title>"));
  client.print(F("<style type='text/css'>"));
  client.print(F(".myButton{margin:20px;margin-bottom: 30px}"));
  client.print(F(".Enabling{position:absolute;left:25%;}"));
  client.print(F(".Action{position:absolute;top:50%;left:25%;}"));
  client.print(F("</style></head><body>"));
  client.print(F("<h3 align='center'>Motors are "));
  client.print((Enabled) ? F("Enabled</h3>") :F("not Enabled</h3>"));
  client.print(F("<br><br>"));
  client.print(F("<div id='Action'><a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/Forward' class='myButton' id='Forward'>Forward</a>")); 
  client.print(F("<a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/Left' class='myButton' id='Left'>Left</a>"));
  client.print(F("<a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/Right' class='myButton' id='Right'>Right</a>"));
  client.print(F("<a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/Back' class='myButton' id='Back'>Back</a><br></div>"));
  client.print(F("<div id='Enabling'><br><br><a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/Enable/ON' class='myButton' >Enable ON</a>"));
  client.print(F("<a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/Enable/OFF' class='myButton' >Enable OFF</a>"));
  client.print(F("<a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/Stop' class='myButton' id='Stop'>Stop</a>"));
  client.print(F("</div></body></html>"));
}

void Forward(){
  Serial.println(F("Forward"));
  digitalWrite(Motor_1_pos,HIGH);
  digitalWrite(Motor_2_pos,HIGH);
  digitalWrite(Motor_1_neg,LOW);
  digitalWrite(Motor_2_neg,LOW);
  /*
  digitalWrite(Motor_1_pos,LOW);
  digitalWrite(Motor_2_pos,LOW);
  digitalWrite(Motor_1_neg,LOW);
  digitalWrite(Motor_2_neg,LOW); */
}

void Left(){
  Serial.println(F("Left"));
  digitalWrite(Motor_1_pos,LOW);
  digitalWrite(Motor_2_pos,HIGH);
  digitalWrite(Motor_1_neg,HIGH);
  digitalWrite(Motor_2_neg,LOW);
}
void Right(){
  Serial.println(F("Right"));
  digitalWrite(Motor_1_pos,HIGH);
  digitalWrite(Motor_2_pos,LOW);
  digitalWrite(Motor_1_neg,LOW);
  digitalWrite(Motor_2_neg,HIGH);
}
void Back(){
  Serial.println(F("Back"));
  digitalWrite(Motor_1_pos,LOW);
  digitalWrite(Motor_2_pos,LOW);
  digitalWrite(Motor_1_neg,HIGH);
  digitalWrite(Motor_2_neg,HIGH);
}

void Stop(){
  digitalWrite(Motor_1_pos,LOW);
  digitalWrite(Motor_2_pos,LOW);
  digitalWrite(Motor_1_neg,LOW);
  digitalWrite(Motor_2_neg,LOW);
}

