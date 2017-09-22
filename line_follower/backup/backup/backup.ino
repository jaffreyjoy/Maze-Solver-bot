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

int s1,s2,s3,s4,s5;
//int dir[500];

void setup() {
  // put your setup code here, to run once:
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
}

//void check(){
//     if ind==499 {
//      clear_array();
//      ind=0;
//    }
// }

void loop() {
  // put your main code here, to run repeatedly:
  s1 = digitalRead(sen1);
  s2 = digitalRead(sen2);
  s3 = digitalRead(sen3);
  s4 = digitalRead(sen4);
  s5 = digitalRead(sen5);
  
  if(!s1 && s2 && s3 && s4 && !s5){
//    check();
//    dir[ind++] = 0;
    MotorControl(1,1);
     analogWrite(El,100);
     analogWrite(Er,100); 
  }
  
  if(s1 && s2 && s3 && !s4 && !s5){
    MotorControl(1,1);
     left(1); 
  }
  
  if(!s1 && s2 && s3 && !s4 && !s5){
    MotorControl(1,1);
     left(0); 
  }
  
  if(s1 && s2 && !s3 && !s4 && !s5){
    MotorControl(1,1);
     left(2); 
  }
  
  if(s1 && !s2 && !s3 && !s4 && !s5){
    MotorControl(1,1);
     left(3); 
  }
  
   if(!s1 && !s2 && s3 && s4 && s5){
     MotorControl(1,1);
     right(1); 
  }
  
  if(!s1 && !s2 && !s3 && s4 && s5){
    MotorControl(1,1);
     right(2); 
  }
  
  if(!s1 && !s2 && !s3 && !s4 && s5){
    
    MotorControl(1,1);
     right(3); 
  }
  
  if(!s1 && !s2 && s3 && s4 && !s5){
    MotorControl(1,1);
     right(0); 
  }
  
  if(!s1 && s2 && s3 && s4 && s5){
//    check();
//    dir[ind++] = 1;
    analogWrite(El,100);//right
    analogWrite(Er,100);
    
    MotorControl(2,1); 
  }
  
  if(s1 && s2 && s3 && s4 && !s5){
 
//    check();
//    dir[ind++] = 2;
    analogWrite(El,100);//left
    analogWrite(Er,100);
    
    MotorControl(1,2); 
  }
  
  if(!s1 && !s2 && !s3 && !s4 && !s5){
     //turn_360:
     analogWrite(El,75);
     analogWrite(Er,75);
    
    MotorControl(1,2);
  }
    
//  if(!s1 && !s2 && !s3 && !s4 && !s5){
//    if(dir[ind]==1)
//      goto tr;
//    else if(dir[ind]==2)
//      goto tl;
//    else
//      goto 
      
//    analogWrite(El,0);
//    analogWrite(Er,0);
//    MotorControl(0,0);
//  }
}

void left(int id){
   
    if(id==0){
      analogWrite(El,95);
      analogWrite(Er,100);
    }
  
   if(id==1){
     analogWrite(El,80);
     analogWrite(Er,100);
   } 
   
   if(id==2){
     analogWrite(El,60);
     analogWrite(Er,100);
   }
   
   if(id==3){
     analogWrite(El,40);
     analogWrite(Er,100);
   }
}

void right(int id){
  
    if(id==0){
      analogWrite(El,100);
      analogWrite(Er,95);
    }
   
   if(id==1){
     analogWrite(El,100);
     analogWrite(Er,80);
   } 
   
   if(id==2){
     analogWrite(El,100);
     analogWrite(Er,60);
   }
   
   if(id==3){
     analogWrite(El,100);
     analogWrite(Er,40);
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
