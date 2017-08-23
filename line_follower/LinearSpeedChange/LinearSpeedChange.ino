#define Lp 7 //left pin of positive motor
#define Ln 4 // left negative
#define El 5 // Enable pin of left motor
#define Rp 8 //right motor positive pin
#define Rn 12 //pin no of right negative motor
#define Er 6 //Enable pin of right motor. if it is 0 right motor is always off
#define led 13
#define obsSensor 2

int i=0;
int j=50;
int k = j - i;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(obsSensor,INPUT);
  pinMode(Lp,OUTPUT);
  pinMode(Ln,OUTPUT);
  pinMode(El,OUTPUT);
  pinMode(Er,OUTPUT);
  pinMode(Rp,OUTPUT);
  pinMode(Rn,OUTPUT);
  pinMode(led,OUTPUT);
}

void loop() 
{
  
  MotorControl(1,1);
  
  if(i>=50&&i<70)
  {
    digitalWrite(El,HIGH);
    digitalWrite(Er,HIGH);
    i++;
  }
  
  else if (i < 50)
  {
    digitalWrite(El,HIGH);
    digitalWrite(Er,HIGH);
    delay(i);
  
    digitalWrite(El,LOW);
    digitalWrite(Er,LOW);
    delay(k);
    i++;
    k = j - i;
  }
  else
  {
     digitalWrite(El,HIGH);
     digitalWrite(Er,HIGH);
     delay(i);
  
     digitalWrite(El,LOW);
     digitalWrite(Er,LOW);
     delay(k);

     i--;
     k = j - i;
  }
  
 
  //Serial.println(i);
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


