#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
DHT dht(4,11);
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);
int a[128];
void setup() 
{
  Serial.begin(9600);
  pinMode(A1,INPUT);
  dht.begin(); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  display.display();
  delay(1000);
}
void loop() 
{
  float  tem=0;
 while(1)
 {
  for(int j=0;j<=10;j++){
  delay(50);
  if(j==0) tem=dht.readTemperature();
  //if(isnan(tem))tem=125*analogRead(A2)>>8;
  int ill=analogRead(A1);
  a[0]=(int)ill>>7;
  for(int i=128;i>0;i--)
  {
    a[i]=a[i-1];
    }
  disdata(tem,ill,a);
  
  Serial.println(tem);
  }
 } 
  
}
void disdata(float tem, int ill,int a[])
{
   display.clearDisplay();
   display.setTextSize(1);
   display.setTextColor(WHITE);
   display.setCursor(0,8);
   display.print("Temperature:");
   display.print(tem);
   display.println("'C");
   display.print("Illumination:");
   display.print(ill);
   for(int i=0;i<129;i++)
   {
    display.drawPixel(i,32-a[i],SSD1306_WHITE);
    }
   // display.drawRect(0,24,128,8,SSD1306_WHITE);
   //display.fillRect(0,24,(int)ill>>3,8,SSD1306_WHITE);
   display.display();
  }
