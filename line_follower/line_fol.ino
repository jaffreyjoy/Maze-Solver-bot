//int sense1=0;

int sense2 = 0;

int sense3 = 0;

int sense4 = 0;

//int sense5=0;

int motor_L1 = 8;

int motor_L2 = 9;

int motor_R1 = 10;

int motor_R2 = 11;

void setup() {

    // put your setup code here, to run once:

    pinMode(5, INPUT);

    pinMode(6, INPUT);

    pinMode(7, INPUT);

    pinMode(9, OUTPUT);

    pinMode(10, OUTPUT);

    pinMode(8, OUTPUT);

    pinMode(11, OUTPUT);

    //digitalWrite(motor_L1,LOW);

    //digitalWrite(motor_R1,LOW);

}

void loop() {

    // put your main code here, to run repeatedly:

    //sense1=digitalRead(3);
    sense2 = digitalRead(5);

    sense3 = digitalRead(6);
    sense4 = digitalRead(7);

    //sense5=digitalRead(7);

    if (sense2 == 0 && sense3 == 1 && sense4 == 0)

    {

        digitalWrite(motor_L1, HIGH);

        digitalWrite(motor_L2, LOW);

        digitalWrite(motor_R1, HIGH);

        digitalWrite(motor_R2, LOW);

    } else if (sense2 == 0 && sense3 == 0 && sense4 == 1)

    {

        digitalWrite(motor_L1, LOW);

        digitalWrite(motor_L2, LOW);

        digitalWrite(motor_R1, HIGH);

        digitalWrite(motor_R2, LOW);

    } else if (sense2 == 1 && sense3 == 0 && sense4 == 0)

    {

        digitalWrite(motor_L1, HIGH);

        digitalWrite(motor_L2, LOW);

        digitalWrite(motor_R1, LOW);

        digitalWrite(motor_R2, LOW);

    }

    /*else if(sense2==1&&sense3==1&&sense4==0)

    {

      digitalWrite(motor_L1,255);

      digitalWrite(motor_L2,255);

      digitalWrite(motor_R1,255);

      digitalWrite(motor_R2,128);

    }*/
    else if (sense2 == 0 && sense3 == 1 && sense4 == 1)

    {

        digitalWrite(motor_L1, 128);

        digitalWrite(motor_L2, 255);

        digitalWrite(motor_R1, 255);

        digitalWrite(motor_R2, 255);

    }

}