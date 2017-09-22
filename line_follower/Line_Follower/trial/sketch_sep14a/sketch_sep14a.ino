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
#define led 13

int i=0;
int j;
int n=10;

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
  
  digitalWrite(El,HIGH);
  digitalWrite(Er,HIGH);
  
  MotorControl(1,1);
//  Serial.print("hi");
}

//obstacle detected returns 0
//refresh rate 5ms
//on time increased, radius of turn increased


void right(int);
void left(int);

void loop(){
//  if(i<200)
//  {
//    if((i%n)<(n/2))
//    {
//       Serial.println("              Right");
//       right(1);
//    }  
//    else
//    {
//      Serial.println("Left");
//      left(1);
//    }
//  }
//  else
//  {
     if((i%n)<(n/2))
    {
       Serial.println("           \tRight");
       right(1);
    }  
    else
    {
      Serial.println("Left");
      left(1);
    }
//  }
  
  
  Serial.println(i);
  i++;
   
}

void right(int id)
{
      
      digitalWrite(Er,HIGH);
      
      if(id==1)
      {
        digitalWrite(El,HIGH);
        delay(50); 
        
        digitalWrite(El,LOW);
        delay(200);
      }
      
      if(id==2)
      {
        digitalWrite(El,HIGH);
        delay(150); 
        
        digitalWrite(El,LOW);
        delay(100);
      }
      
}

void left(int id)
{
      digitalWrite(El,HIGH);
      
      if(id==1)
      {
        digitalWrite(Er,HIGH);
        delay(50); 
        
        digitalWrite(Er,LOW);
        delay(200);
      }
      
      if(id==2)
      {
        digitalWrite(Er,HIGH);
        delay(150); 

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


