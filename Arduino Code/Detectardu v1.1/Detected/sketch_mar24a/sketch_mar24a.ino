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
  myservo2.write(20);
  myservo1.write(58);
  
}


void loop()
{
  if(Serial.available())
  {
      Serial.readBytes(say,7);
      int a;
      for(a=0;a<=7;a++)
      say[a]=say[a]-'0';
        int top1=(say[0]*1000)+(say[1]*100)+(say[2]*10)+say[3];
        int top2=(say[4]*1000)+(say[5]*100)+(say[6]*10)+say[7];
        if(top1>750 && top1<1550)
           myservo1.writeMicroseconds(top1);
//           delay(500);
        if(top2>450 && top2<1050)
           myservo2.writeMicroseconds(top2);
      Serial.flush();
  }
    //058020
    //1145
    //0752
    
}
  


