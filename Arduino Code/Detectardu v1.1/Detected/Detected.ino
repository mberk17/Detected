#include <Servo.h> 
int ledPin = 13; // the number of the LED pin
char say[10];
Servo myservo1,myservo2;

void setup() 
{
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, LOW);
  myservo1.attach(9);
  myservo2.attach(11);
  myservo1.write(50);
  myservo2.write(20);
}


void loop()
{
  if(Serial.available())
  {
      Serial.readBytes(say,6);
      int a;
      for(a=0;a<=5;a++)
      say[a]=say[a]-'0';
        int top1=(say[0]*100)+(say[1]*10)+say[2];
        int top2=(say[3]*100)+(say[4]*10)+say[5];
           if(top1>=1 && top1<=170)
              myservo1.write(top1);
           if(top2>=1 && top2<=170)
              myservo2.write(top2);
      Serial.flush();
  }
    //051020
    //111132
}
  


