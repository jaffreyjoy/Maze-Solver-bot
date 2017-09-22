#define motorPinL 5 
#define motorPinR 6
#define Rn 4
#define Rp 3
#define Ln 8
#define Lp 7
void setup(){
 pinMode(motorPinL, OUTPUT);
 pinMode(motorPinR, OUTPUT);
 pinMode(Rn, OUTPUT);
 pinMode(Rp, OUTPUT);
 pinMode(Ln, OUTPUT);
 pinMode(Lp, OUTPUT);
}

int i=0;

void loop() {
  
  
 analogWrite(motorPinL,100);
 analogWrite(motorPinR,100);
 MotorControl(1,1); 
 Serial.println("For 1"); 
 delay(30);
  i++;
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

