#include <SoftwareSerial.h>
const int ledpin = 8;
SoftwareSerial bluemod(11, 10);
char data  = "a";

#define STOPPED 0
#define FOLLOWING_LINE 1
#define NO_LINE 2

#define ena 5
#define m1a 6
#define m1b 7
#define m2a 9
#define m2b 8
#define enb 3


void stop()
{ // stop
  // motor 1
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  // motor 2
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}

void forward()
{ // forward
  // motor 1
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  // motor 2
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}
void right()
{
  // right
  // motor 1
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  // motor 2
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
}
void left()
{
  // left
  // motor 1
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  // motor 2
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}


void setup(){

Serial.begin(9600);
bluemod.begin(9600);
Serial.write("pairing started");
pinMode(ledpin,OUTPUT);

 pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(ena, OUTPUT);

  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(enb, OUTPUT);

  // initial speed
  analogWrite(ena, 50);
  analogWrite(enb, 50);

  // pinMode(3, OUTPUT);
  // pinMode(5, OUTPUT);
  // pinMode(6, OUTPUT);

}


void loop(){

  if (bluemod.available()){
    data = char(bluemod.read());
    Serial.write(data);
    //Serial.print(bluemod.read());

    }
    if(data=='e'){
     
      forward();
      
    }else if(data=='c'){
      right();
    } else if(data=='a'){
      left();
    
    }
    else if(data=='g'){
      stop();
    }

  if (Serial.available()){
   bluemod.write(Serial.read());   
  }


}