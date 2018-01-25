#include <Wire.h>

void reciveEvent(int);
void setColor(byte, byte, byte, byte, byte ,byte);

byte pinR11;
byte pinB10;
byte pinG9;
byte pinR6;
byte pinB5;
byte pinG3;
byte red1;
byte green1;
byte blue1;
byte red2;
byte green2;
byte blue2;

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(11, 1);
  digitalWrite(10, 1);
  digitalWrite(9, 1);
  digitalWrite(6, 1);
  digitalWrite(5, 1);
  digitalWrite(3, 1);
  delay(500);
  digitalWrite(11, 0);
  digitalWrite(10, 0);
  digitalWrite(9, 0);
  digitalWrite(6, 0);
  digitalWrite(5, 0);
  digitalWrite(3, 0);
}

void loop() {
  delay(500);
}


void receiveEvent(int howMany) {

  red1 = Wire.read();
  green1 = Wire.read();
  blue1 = Wire.read();
  pinR11 = Wire.read();
  pinB10 = Wire.read();
  pinG9 = Wire.read();
 	setColor(red1, green1, blue1, pinR11, pinG9, pinB10);
  red2 = Wire.read();
  green2 = Wire.read();
  blue2 = Wire.read();
  pinR6 = Wire.read();
  pinB5 = Wire.read();
  pinG3 = Wire.read();  
 	setColor(red2, green2, blue2, pinR6, pinG3, pinB5);

  

}

void setColor(byte red, byte green, byte blue, byte redPin, byte greenPin, byte bluePin){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

