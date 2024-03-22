#include<Servo.h>
#define IN1 10
#define IN2 11
#define IN3 12
#define IN4 13
#define Enb 5
#define Ena 6
int echo=7;
int trig=8;
int ping = 3;
int pino =4;
int dis ;
int duree;
 Servo myservo;


void setup()
{ 
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(pino, OUTPUT);
  pinMode(ping, OUTPUT);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(Enb ,OUTPUT);
    pinMode(Ena, OUTPUT);
      myservo.attach(9);
}
void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(2); // Wait for 1000 millisecond(s)
  digitalWrite(trig, LOW);
  
  
   duree=pulseIn(echo,HIGH);
   dis=duree* 0.034/2;
   myservo.write(0);

   if (dis>20){
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      analogWrite(Ena,200);

      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      analogWrite(Enb,200);
   }
   else{
    myservo.write(90);
    if (dis>20){
      digitalWrite(IN1,HIGH);// bach yweli lelor
      digitalWrite(IN2,LOW);
      analogWrite(Ena,200);

      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      analogWrite(Enb,200);
          delay(500);

      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      analogWrite(Ena,200);

      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,HIGH);
      analogWrite(Enb,160);
   }  else{
      myservo.write(180);
             if (dis>20){
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      analogWrite(Ena,200);

      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      analogWrite(Enb,200);

        delay(500);
        
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      analogWrite(Ena,160);

      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,HIGH);
      analogWrite(Enb,200);
     }
      }
       }
        }
 

