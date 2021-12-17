#include <Wire.h>


void setup() {
Serial.begin(9600);
pinMode(9,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
}

void loop() {
while(1)
{
int val=analogRead(A1);
if(val>700){digitalWrite(9,LOW);digitalWrite(11,LOW);digitalWrite(10,LOW);}
else if(val>500){digitalWrite(9,LOW);digitalWrite(11,HIGH);digitalWrite(10,LOW);}
else if(val>250){digitalWrite(9,LOW);digitalWrite(11,LOW);digitalWrite(10,HIGH);}
else {digitalWrite(9,HIGH);digitalWrite(11,LOW);digitalWrite(10,LOW);}
Serial.println(val);
delay(1);
}


}
