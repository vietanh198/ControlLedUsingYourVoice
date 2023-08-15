#include <SoftwareSerial.h>
 
#define TX_PIN      7
#define RX_PIN      6
char value; 
SoftwareSerial bluetooth(RX_PIN, TX_PIN);
int baudRate[] = {300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200};
char kytu;
String chuoi; 
int n=0;
int ledxanh=13;
int leddo=11;
int ledvang=12;
void setup() {
  Serial.begin(9600);
  pinMode(ledxanh, OUTPUT);
  pinMode(leddo, OUTPUT);  
  pinMode(ledvang, OUTPUT);
  while (!Serial) {}
  
  Serial.println("Configuring, please wait...");
  
  for (int i = 0 ; i < 9 ; i++) {
     bluetooth.begin(baudRate[i]);
     String cmd = "AT+BAUD4";
     bluetooth.print(cmd);
     bluetooth.flush();
     delay(100);
  }
  
  bluetooth.begin(9600);
  Serial.println("Config done");
  while (!bluetooth) {}
  
  Serial.println("Enter AT commands:");
}
 
void loop() {
  
  if (bluetooth.available()) {
    
    kytu=bluetooth.read();
    chuoi=chuoi+kytu;
    Serial.println(kytu);
    if(chuoi.indexOf("bật đèn xanh")>=0){
        digitalWrite(ledxanh,HIGH);
        Serial.println(chuoi);
        chuoi="";
        n=0;
      }
    if(chuoi.indexOf("tắt đèn xanh")>=0){
        digitalWrite(ledxanh,LOW);
        Serial.println(chuoi);
        chuoi="";
        n=0;
      }
     if(chuoi.indexOf("bật đèn đỏ")>=0){
        digitalWrite(leddo,HIGH);
        Serial.println(chuoi);
        chuoi="";
        n=0;
      }
    if(chuoi.indexOf("tắt đèn đỏ")>=0){
        digitalWrite(leddo,LOW);
        Serial.println(chuoi);
        chuoi="";
        n=0;
      }
    if(chuoi.indexOf("bật đèn vàng")>=0){
        digitalWrite(ledvang,HIGH);
        Serial.println(chuoi);
        chuoi="";
        n=0;
      }
    if(chuoi.indexOf("tắt đèn vàng")>=0){
        digitalWrite(ledvang,LOW);
        Serial.println(chuoi);
        chuoi="";
        n=0;
      }
  }
  
}
