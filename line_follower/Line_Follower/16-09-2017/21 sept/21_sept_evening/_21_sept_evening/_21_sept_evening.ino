#define sen1 11
#define sen2 2
#define sen3 3
#define sen4 A0
#define sen5 A1
#define Lp 7 //left pin of positive motor
#define Ln 4 // left negative
#define El 5 // Enable pin of left motor
#define Rp 8 //right motor positive pin
#define Rn 12 //pin no of right negative motor
#define Er 6 //Enable pin of right motor. if it is 0 right motor is always off
//#define led 13

int i=0;
int j;
int n=10;

int s1,s2,s3,s4,s5;

int count=0;
int count1=30;
int count2=count1-count;

int sf=0;   //stop flag
int flag=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sen1,INPUT);
  pinMode(sen2,INPUT);
  pinMode(sen3,INPUT);
  pinMode(sen4,INPUT);
  pinMode(sen5,INPUT);
  pinMode(Lp,OUTPUT);
  pinMode(Ln,OUTPUT);
  pinMode(El,OUTPUT);
  pinMode(Er,OUTPUT);
  pinMode(Rp,OUTPUT);
  pinMode(Rn,OUTPUT);
  
  
  
  
//digitalWrite(El,HIGH);
  //digitalWrite(Er,HIGH);
  
  //MotorControl(1,1);
//  Serial.print("hi");
}

//obstacle detected returns 0
//refresh rate 5ms
//on time increased, radius of turn increased


void right(int);
void left(int);

void loop(){
  
  if(!sf)
    MotorControl(1,1);
  
  s1 = digitalRead(sen1);
  s2 = digitalRead(sen2);
  s3 = digitalRead(sen3);
  s4 = digitalRead(sen4);
  s5 = digitalRead(sen5);
  
  
  if(!s1 && s2 && s3 && s4 && !s5)
  {
    sf=0;
  
    digitalWrite(Er,HIGH);
    digitalWrite(El,HIGH);
    delay(10);
    digitalWrite(Er,LOW);
    digitalWrite(El,LOW);
    delay(60);

    Serial.println("Straight");
  }
  
  else if(!s1 && !s2 && s3 && s4 && !s5)
  {
    sf=0;
//    MotorControl(1,1);
    Serial.println("                Right");
    right(3);
  }
  
  else if(!s1 && s2 && s3 && !s4 && !s5)
  {
    sf=0;
//    MotorControl(1,1);
    Serial.println("                          Left");
    left(3);
  }
  
  else if(s1 && s2 && !s3 && !s4 && !s5)
  {
    sf=0;
//    MotorControl(1,1);
    Serial.println("           Moderate Left");
    left(2);
  }
  
  else if(s1 && !s2 && !s3 && !s4 && !s5)
  {
    sf=0;
//    MotorControl(1,1);
    Serial.println("                                   Extreme Left");
    left(1);
  }
  
  else if(!s1 && !s2 && !s3 && s4 && s5)
  {
    sf=0;
    
//    MotorControl(1,1);
    Serial.println("             Moderate Right");
    right(2);
  }
  
  else if(!s1 && !s2 && !s3 && !s4 && s5 )
  {
    sf=0;
//    MotorControl(1,1);
    Serial.println("                                  Extereme Right");
    right(1);
  }
   else if(!s1 && s2 && !s3 && !s4 && !s5 )
  {
    sf=0;
//    MotorControl(1,1);
    Serial.println("                                  Extra left");
    left(2);
  }
   else if(!s1 && !s2 && !s3 && s4 && !s5 )
  {
    sf=0;
//    MotorControl(1,1);
    Serial.println("                                  Extra right");
    right(2);
  }
  else if(!s1 && s2 && s3 && s4 && s5 )
  {
    sf=0;
    digitalWrite(Er,HIGH);
    digitalWrite(El,HIGH);
    MotorControl(1,0);
    delay(325);
    Serial.println("                                  90 right");
  }
   else if(s1 && s2 && s3 && s4 && !s5 )
  {
    sf=0;
    digitalWrite(Er,HIGH);
    digitalWrite(El,HIGH);
    MotorControl(0,1);
    delay(325);
    Serial.println("                                  90 left");
  }
  else
  {
     sf=1;
     MotorControl(0,0);
  }  
//    MotorControl(0,0);
    //delay(150);
}

void left(int id)
{
      digitalWrite(Er,HIGH);
      delay(50);
      if(id==1)
      {
        digitalWrite(El,HIGH);
        delay(100); 
        digitalWrite(Er,LOW);
        digitalWrite(El,LOW);
        delay(100);
      }
      
      if(id==2)
      {
        digitalWrite(El,HIGH);
        delay(150); 
        digitalWrite(Er,LOW);
        digitalWrite(El,LOW);
        delay(100);
      }
      
      if(id==3)
      {
        digitalWrite(El,HIGH);
        delay(250); 
        digitalWrite(Er,LOW);
        digitalWrite(El,LOW);
        delay(100);
      }
      
      
}

void right(int id)
{
      digitalWrite(El,HIGH);
      delay(50);
      if(id==1)
      {
        digitalWrite(Er,HIGH);
        delay(100); 
        digitalWrite(El,LOW);
        digitalWrite(Er,LOW);
        delay(100);
      }
      
      if(id==2)
      {
        digitalWrite(Er,HIGH);
        delay(150); 
        digitalWrite(El,LOW);
        digitalWrite(Er,LOW);
        delay(100);
      }
      if(id==3)
      {
        digitalWrite(Er,HIGH);
        delay(250); 
        digitalWrite(El,LOW);
        digitalWrite(Er,LOW);
        delay(100);
      }
}


void MotorControl(int driveL,int driveR)
{
  switch(driveL)
  {
    case 0: 
      digitalWrite(Ln,LOW);
      digitalWrite(Lp,LOW);
      break;
    case 1:
      digitalWrite(Ln,HIGH);
      digitalWrite(Lp,LOW);
      break;
    case 2:
      digitalWrite(Ln,LOW);
      digitalWrite(Lp,HIGH);
      break;
    default: 
      break;
  }
  
  switch(driveR)
  {
    case 0:
      digitalWrite(Rn,LOW);
      digitalWrite(Rp,LOW);
      break;
    case 1:
      digitalWrite(Rn,HIGH);
      digitalWrite(Rp,LOW);
      break;
    case 2:
      digitalWrite(Rn,LOW);
      digitalWrite(Rp,HIGH);
      break;
    default: 
      break;
  }
  
}


