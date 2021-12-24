#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);
#define SSID wori
#define password 31415926

void setup(){
    Serial.begin(115200);
    mySerial.begin(115200);
    delay(5000);
    
    sendcmd("AT+RST","Error");
    sendcmd("AT+CWMODE=1","OK");
    sebdcmd("AT+CWJAP\"%s\",\"%s\"",SSID,password);
}


void loop()
{
  
  }


boolean sendcmd(String cmd,String kwd){
    unsigned char current=0;
    unsigned char kwd_len=kwd.length();
    long ddl=millis()+5000;
    mySerial.println(cmd);
    while(millis()<ddl){
        if(mySerial.available()){
            char bt=mySerial.read();
            Serial.write(bt);
            if(bt==kwd[current]){
                if(++current==kwd_len){
                    Serial.println();
                    return true;
                }
            }

        }

    }
    return false;
}
