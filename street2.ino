int ir1=2;
int ir2=3;
int ir3=4;
int ir4=5;

int led1=6;
int led2=7;
int led3=8;
int led4=9;
int led5=10;
int led6=11;

int proxy1=0;
int proxy2=0;
int proxy3=0;
int proxy4=0;
void setup()

{
//pinMode(motorPlus,OUTPUT);

//pinMode(motorMinus,OUTPUT);

pinMode(ir1,INPUT);

pinMode(ir2,INPUT);

pinMode(ir3,INPUT);

//pinMode(ir4,INPUT);

pinMode(led1,OUTPUT);

pinMode(led2,OUTPUT);

pinMode(led3,OUTPUT);

pinMode(led4,OUTPUT);

pinMode(led5,OUTPUT);

//pinMode(led6,OUTPUT);

}


void loop(){
  

 
 
proxy1=digitalRead(ir1);

proxy2=digitalRead(ir2);

proxy3=digitalRead(ir3);

//proxy4=digitalRead(ir4);

if(proxy1==HIGH)

{
 
//digitalWrite(motorPlus,HIGH);
 
//digitalWrite(motorMinus,LOW);
 

digitalWrite(led1,HIGH);

digitalWrite(led2,HIGH);

digitalWrite(led3,HIGH);

}

else

{

digitalWrite(led1,LOW);

digitalWrite(led2,LOW);

digitalWrite(led3,LOW);

}

if(proxy2==HIGH)

{

digitalWrite(led2,HIGH);

digitalWrite(led3,HIGH);

digitalWrite(led4,HIGH);

}

else

{

digitalWrite(led2,LOW);

digitalWrite(led3,LOW);

digitalWrite(led4,LOW);

}

if(proxy3==HIGH)

{

digitalWrite(led3,HIGH);

digitalWrite(led4,HIGH);

digitalWrite(led5,HIGH);

}

else

{

digitalWrite(led3,LOW);

digitalWrite(led4,LOW);

digitalWrite(led5,LOW);

}

/*if(proxy4==HIGH)

{

digitalWrite(led4,HIGH);

digitalWrite(led5,HIGH);

digitalWrite(led6,HIGH);

}

else

{

digitalWrite(led4,LOW);

digitalWrite(led5,LOW);

digitalWrite(led6,LOW);

}*/
}
