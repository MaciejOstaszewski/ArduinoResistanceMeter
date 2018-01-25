#include <Wire.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,6,5,4,3,2);
int multiplier;
int value1;
int value2;

byte grey[3] = {16, 16, 16};
byte gold[3] = {218, 165, 32};
byte black[3] = {0, 0, 0};
byte brown[3] = {90, 10, 0};
byte red[3] = {255, 0, 0};
byte orange[3] = {244, 11, 0};
byte yellow[3] = {255, 255, 0};
byte green[3] = {0, 255, 0};
byte blue[3] = {0, 0, 255};
byte purple[3] = {151, 51, 255};
byte white[3] = {255, 255, 255};
byte silver[3] = {128, 128, 128};

char kilo = 'k';
char mega = 'M';
char giga = 'G';

void Display();
void setColor(byte, byte, byte, byte, byte ,byte);
void setDiodes();
void startTranssmitDiode2(byte[]);
int getMultiplier(int, int);
int getValue(int, int);
bool switchState = 0;
bool oldSwitchState = 0;



void setup() {
	Serial.begin(9600);
    Wire.begin();
   
    pinMode(7, INPUT);
    digitalWrite(7, HIGH);
       
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Podaj wartosc"); 
  	lcd.setCursor(0, 1);
    lcd.print("oporu");
   
  	pinMode(1, INPUT);
   
  	pinMode(11, OUTPUT);
  	pinMode(10, OUTPUT);   
  	pinMode(9, OUTPUT);
  

  
  	digitalWrite(11, 1);
 	digitalWrite(10, 1);
  	digitalWrite(9, 1);
	delay(500);
    digitalWrite(11, 0);
 	digitalWrite(10, 0);
  	digitalWrite(9, 0);
  
 }

void loop() {

	delay(300);
    lcd.setCursor(10, 1);
    lcd.print("       ");
 
  
	switchState = bitRead(PIND, 7);
  
  if(oldSwitchState != switchState){
  	oldSwitchState = switchState;
    delay(10);
    switchState = bitRead(PIND, 7);
    if(switchState == 0) setDiodes();
  }
 	
  
  
    multiplier = analogRead(A2);
    value1 = analogRead(A0);
    value2 = analogRead(A1);
 
 

  

    Display();
 
  
}

void Display(){
    value1 = getValue(value1, 102);
    value2 = getValue(value2, 102);
	multiplier = getMultiplier(multiplier, 85);
    if(value1 > 9) value1 = 9;
    if(value2 > 9) value2 = 9;
    lcd.setCursor(10, 1);
  	if(value1 == 0 && value2 == 0) lcd.print("0."+String(value1)+String(value2)+char(222));
    else if(value1 == 0){
      switch(multiplier){
    	case 0: lcd.print("0."+String(value1)+String(value2)+char(222)); break;
      	case 1: lcd.print(String(value1)+"."+String(value2)+char(222)); break;      		
     	case 2: lcd.print(String(value2)+char(222)); break;
      	case 3: lcd.print(String(value2)+"0"+char(222)); break;      
      	case 4: lcd.print(String(value2)+"00"+char(222)); break;
      	case 5: lcd.print(String(value2)+kilo+char(222)); break;      
      	case 6: lcd.print(String(value2)+"0"+kilo+char(222)); break;      
      	case 7: lcd.print(String(value2)+"00"+kilo+char(222)); break;      
      	case 8: lcd.print(String(value2)+mega+char(222)); break;      
      	case 9: lcd.print(String(value2)+"0"+mega+char(222)); break;      
        case 10: lcd.print(String(value2)+"00"+mega+char(222)); break;
        case 11: lcd.print(String(value2)+"0"+giga+char(222)); break;
        
      
    	}    
    }else{
      switch(multiplier){
    	case 0: lcd.print("0."+String(value1)+String(value2)+char(222)); break;
      	case 1: lcd.print(String(value1)+"."+String(value2)+char(222)); break;      		
     	case 2: lcd.print(String(value1)+String(value2)+char(222)); break;
      	case 3: lcd.print(String(value1)+String(value2)+"0"+char(222)); break;      
      	case 4: lcd.print(String(value1)+"."+String(value2)+kilo+char(222)); break;
      	case 5: lcd.print(String(value1)+String(value2)+kilo+char(222)); break;      
      	case 6: lcd.print(String(value1)+String(value2)+"0"+kilo+char(222)); break;      
      	case 7: lcd.print(String(value1)+"."+String(value2)+mega+char(222)); break;      
      	case 8: lcd.print(String(value1)+String(value2)+mega+char(222)); break;      
      	case 9:	lcd.print(String(value1)+String(value2)+"0"+mega+char(222)); break;      
        case 10: lcd.print(String(value1)+"."+String(value2)+giga+char(222)); break;      
        case 11: lcd.print(String(value1)+String(value2)+giga+char(222)); break;
        
    	}    
      
    }        		      
}



void setDiodes(){
  switch(multiplier){
 	case 0: setColor(silver[0], silver[1], silver[2], 11, 9, 10); break;
    case 1: setColor(gold[0], gold[1], gold[2], 11, 9, 10); break;
    case 2: setColor(black[0], black[1], black[2], 11, 9, 10); break;
    case 3: setColor(brown[0], brown[1], brown[2], 11, 9, 10); break;
    case 4: setColor(red[0], red[1], red[2], 11, 9, 10); break;
    case 5: setColor(orange[0], orange[1], orange[2], 11, 9, 10); break;
    case 6: setColor(yellow[0], yellow[1], yellow[2], 11, 9, 10); break;
    case 7: setColor(green[0], green[1], green[2], 11, 9, 10); break;
    case 8: setColor(blue[0], blue[1], blue[2], 11, 9, 10); break;
    case 9: setColor(purple[0], purple[1], purple[2], 11, 9, 10); break;
    case 10: setColor(grey[0], grey[1], grey[2], 11, 9, 10); break;
    case 11: setColor(white[0], white[1], white[2], 11, 9, 10); break;
    

    
  }
	Serial.println(value1);
    Serial.println(value2);
  switch(value1){

 	case 0: startTranssmitDiode1(black); break;
    case 1: startTranssmitDiode1(brown); break;
    case 2: startTranssmitDiode1(red); break;
    case 3: startTranssmitDiode1(orange); break;
    case 4: startTranssmitDiode1(yellow); break;
    case 5: startTranssmitDiode1(green); break;
    case 6: startTranssmitDiode1(blue); break;
    case 7: startTranssmitDiode1(purple); break; 
    case 8: startTranssmitDiode1(grey); break;
    case 9: startTranssmitDiode1(white); break; 
    
  }
  
  switch(value2){

 	case 0: startTranssmitDiode2(black); break;
    case 1: startTranssmitDiode2(brown); break;
    case 2: startTranssmitDiode2(red); break;
    case 3: startTranssmitDiode2(orange); break;
    case 4: startTranssmitDiode2(yellow); break;
    case 5: startTranssmitDiode2(green); break;
    case 6: startTranssmitDiode2(blue); break;
    case 7: startTranssmitDiode2(purple); break;   
    case 8: startTranssmitDiode2(grey); break; 
    case 9: startTranssmitDiode2(white); break; 
    
  } 
  

}

  
void startTranssmitDiode1(byte color[]){
    Wire.beginTransmission(8);
    Wire.write(color[0]);
    Wire.write(color[1]);
    Wire.write(color[2]);
    Wire.write(11);
    Wire.write(10);
    Wire.write(9);

    Wire.endTransmission();    // stop transmitting  
}
void startTranssmitDiode2(byte color[]){
    Wire.beginTransmission(8);  
    Wire.write(color[0]);
    Wire.write(color[1]);
    Wire.write(color[2]);
    Wire.write(6);
    Wire.write(5);
    Wire.write(3);

    Wire.endTransmission();    // stop transmitting  
}

void setColor(byte red, byte green, byte blue, byte redPin, byte greenPin, byte bluePin){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

int getMultiplier(int number, int value){
  if(number >= 0 && number <= value) return 0;
  else if(number > value && number <= value*2) return 1;
  else if(number > value*2 && number <= value*3) return 2;
  else if(number > value*3 && number <= value*4) return 3;
  else if(number > value*4 && number <= value*5) return 4;
  else if(number > value*5 && number <= value*6) return 5;
  else if(number > value*6 && number <= value*7) return 6;
  else if(number > value*7 && number <= value*8) return 7;
  else if(number > value*8 && number <= value*9) return 8;
  else if(number > value*9 && number <= value*10) return 9;
  else if(number > value*10 && number <= value*11) return 10;
  else return 11;


}
  int getValue(int number, int value){
    if(number >= 0 && number <= value) return 0;
  	else if(number > value && number <= value*2) return 1;
  	else if(number > value*2 && number <= value*3) return 2;
  	else if(number > value*3 && number <= value*4) return 3;
  	else if(number > value*4 && number <= value*5) return 4;
 	else if(number > value*5 && number <= value*6) return 5;
 	else if(number > value*6 && number <= value*7) return 6;
 	else if(number > value*7 && number <= value*8) return 7;
 	else if(number > value*8 && number <= value*9) return 8;
	else return 9;   
  }