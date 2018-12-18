#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10, 9);
const int ledpin=13; 
const int flamepin=A2;
const int buzpin=11;
const int threshold=200;
int flamesensvalue=0;
int data=0;
void setup() {
Bluetooth.begin(9600);
Serial.begin(9600);
pinMode(ledpin,OUTPUT);
pinMode(flamepin,INPUT);
pinMode(buzpin,OUTPUT);
Serial.println("Waiting for command...");
Bluetooth.println("!!  ........FOREST....FIRE.....ALERT...AND....MONITORING.......SYSTEM........  !!");
}
void loop() { 
flamesensvalue=analogRead(flamepin); 
if (flamesensvalue<=threshold) { 
digitalWrite(ledpin,HIGH); 
tone(buzpin,1000);
Serial.println("!!fire....fire!!");
Bluetooth.println("!!fire....fire!!");
delay(1000);
}
else{
digitalWrite(ledpin,LOW);
noTone(buzpin);
Serial.println("no fire stay clam !!");
Bluetooth.println("no fire stay clam !!");
}
}
