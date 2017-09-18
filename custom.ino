int Left_p=7;
int Left_n=4;
int Right_p=8;
int Right_n=12;

void setup()
{
  pinMode(Left_p,OUTPUT);
  pinMode(Left_n,OUTPUT);
  pinMode(Right_p,OUTPUT);
  pinMode(Right_n,OUTPUT);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(11, INPUT);

}
  

void loop()

{
  int ex_right=analogRead(A1);
  int right=analogRead(A0);
  int centre=digitalRead(3);
  int left=digitalRead(2);
  int ex_left=digitalRead(11);

  if(ex_left==HIGH && ex_right>700)
  {
     digitalWrite(Left_p,HIGH);
     digitalWrite(Left_n,LOW);
     digitalWrite(Right_p,HIGH);
     digitalWrite(Right_n,LOW);
     
  }
  if(ex_left==LOW && ex_right>700)
  {
     digitalWrite(Left_p,HIGH);
     digitalWrite(Left_n,LOW);
     digitalWrite(Right_p,LOW);
     digitalWrite(Right_n,LOW);
  }
  
if(ex_left==HIGH && ex_right<700)
{
     digitalWrite(Left_p,LOW);
     digitalWrite(Left_n,LOW);
     digitalWrite(Right_p,HIGH);
     digitalWrite(Right_n,LOW);    
}

}
