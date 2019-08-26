#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>

char auth[] = "rOyKE9YGU76YkQHOl97wGBDumro--uCL";

#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

char ssid[] = "AA-2.4";
char pass[] = "Aaron202014";

char lecturaserialesp;
String lecturaserialesp_s;

void setup(){
  delay(10);
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(200);
  }
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V0){ //pin16
  int pinValue = param.asInt();
  if (pinValue==1){
    digitalWrite(16,HIGH);
  } else {
    digitalWrite(16,LOW);
  }
}

BLYNK_WRITE(V1){ //pin5
  int pinValue = param.asInt();
  if (pinValue==1){
    digitalWrite(5,HIGH);
  } else {
    digitalWrite(5,LOW);
  }
}

BLYNK_WRITE(V2){ //pin4
  int pinValue = param.asInt();
  if (pinValue==1){
    digitalWrite(4,HIGH);
  } else {
    digitalWrite(4,LOW);
  }
}

BLYNK_WRITE(V3){ //pin2
  int pinValue = param.asInt();
  if (pinValue==1){
    digitalWrite(2,HIGH);
  } else {
    digitalWrite(2,LOW);
  }
}

BLYNK_WRITE(V4){ //pin14
  int pinValue = param.asInt();
  if (pinValue==1){
    digitalWrite(14,HIGH);
  } else {
    digitalWrite(14,LOW);
  }
}

BLYNK_WRITE(V5){ //pin12
  int pinValue = param.asInt();
  if (pinValue==1){
    digitalWrite(12,HIGH);
  } else {
    digitalWrite(12,LOW);
  }
}

BLYNK_WRITE(V6){ //pin13
  int pinValue = param.asInt();
  if (pinValue==1){
    digitalWrite(13,HIGH);
  } else {
    digitalWrite(13,LOW);
  }
}

BLYNK_WRITE(V7){ //pin15
  int pinValue = param.asInt();
  if (pinValue==1){
    digitalWrite(15,HIGH);
  } else {
    digitalWrite(15,LOW);
  }
}

BLYNK_WRITE(V8){ //pin10
  int pinValue = param.asInt();
  if (pinValue==1){
    digitalWrite(10,HIGH);
  } else {
    digitalWrite(10,LOW);
  }
}

//********este bloque hace que la placa nodemcu esp8266 recuerde los valores de los pines al retomar conexion con internet****
/*
BLYNK_CONNECTED() {
    Blynk.syncAll();
}
*/
//************************

void loop(){
  Blynk.run();
  if(Serial.available()>0){
    lecturaserialesp_s="";
    while(Serial.available()>0){
      delay(70);
      lecturaserialesp = Serial.read();
      lecturaserialesp_s += lecturaserialesp;
    }
    lecturaserialesp_s.trim();
    if(lecturaserialesp_s=="V00"){
      digitalWrite(16,LOW);
    }else{
      if(lecturaserialesp_s=="V01"){
        digitalWrite(16,HIGH);
      }else{
        if(lecturaserialesp_s=="V10"){
          digitalWrite(5,LOW);
        }else{
          if(lecturaserialesp_s=="V11"){
            digitalWrite(5,HIGH);            
          }else{
            if(lecturaserialesp_s=="V20"){
              digitalWrite(4,LOW);          
            }else{
              if(lecturaserialesp_s=="V21"){
                digitalWrite(4,HIGH);                          
              }else{
                if(lecturaserialesp_s=="V30"){
                  digitalWrite(2,LOW);          
                }else{
                  if(lecturaserialesp_s=="V31"){
                    digitalWrite(2,HIGH);                              
                  }else{
                    if(lecturaserialesp_s=="V40"){
                      digitalWrite(14,LOW);          
                    }else{
                      if(lecturaserialesp_s=="V41"){
                        digitalWrite(14,HIGH);          
                      }else{
                        if(lecturaserialesp_s=="V50"){
                          digitalWrite(12,LOW);                                    
                        }else{
                          if(lecturaserialesp_s=="V51"){
                            digitalWrite(12,HIGH);                                                              
                          }else{
                            if(lecturaserialesp_s=="V60"){
                              digitalWrite(13,LOW);                                                                  
                            }else{
                              if(lecturaserialesp_s=="V61"){
                                digitalWrite(13,HIGH);                                                                                                  
                              }else{
                                if(lecturaserialesp_s=="V70"){
                                  digitalWrite(15,LOW);                                                                                                    
                                }else{
                                  if(lecturaserialesp_s=="V71"){
                                    digitalWrite(15,HIGH);                                                                                                                                        
                                  }else{
                                    if(lecturaserialesp_s=="V80"){
                                      digitalWrite(10,LOW);                                                                                                                                          
                                    }else{
                                      if(lecturaserialesp_s=="V81"){
                                        digitalWrite(10,HIGH);                                                                                                                                                                                  
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
