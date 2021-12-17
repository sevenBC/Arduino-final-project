void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
attachInterrupt(0,swt,FALLING);
attachInterrupt(1,swt,FALLING);
}

volatile byte state=0;

void loop() 
{
  // put your main code here, to run repeatedly:
  if (state==1){digitalWrite(9,HIGH);digitalWrite(10,LOW);digitalWrite(11,LOW);}
  else if(state==2) {digitalWrite(9,LOW);digitalWrite(10,HIGH);digitalWrite(11,LOW);}
  else if(state==3) {digitalWrite(9,LOW);digitalWrite(10,LOW);digitalWrite(11,HIGH);}
}

void swt()
{
 if(state!=3)state++;
 else state=1;
}
