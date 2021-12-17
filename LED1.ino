int Button=2;
int LED=12;
boolean onoff=LOW;
void setup()
{
  pinMode(Button,INPUT);
  pinMode(LED,OUTPUT);
}
  void loop(){
    if(digitalRead(Button)==HIGH)
    {
      delay(10);
      if(digitalRead(Button)==LOW)
      {
        digitalWrite(LED,onoff);
        onoff=(!onoff);
        delay(10);
        while(digitalRead(Button)==LOW)
        {
          delay(1);
        }
      }
    }
  }
