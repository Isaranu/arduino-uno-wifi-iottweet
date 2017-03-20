/*
Simple code for Arduino UNO WiFi board.
This code is raw coding to send data to IoTtweet.com dashboard
2017.Mar.20
Coder : Isaranu

** This code is not support send tweet message to dashboard.
We are under developing it **.
*/

#include <Wire.h>
#include <UnoWiFiDevEd.h>

String _id = "IoTtweet-UserID"; /*Numerical ID by 6 digit*/
String _key = "device-key";     /*Registered key of IoT device in "My IoT garage"*/

float _d0, _d1, _d2, _d3;       /*Data slot0-3 send to Dashboard*/  

void setup() {
  Serial.begin(115200);
  Ciao.begin();
}

void loop() {
  
/*Example data generating*/
  _d0 = random(20,80);
  _d1 = random(30,70);
  _d2 = random(40,60);
  _d3 = random(50,55);

  sendToIoTtweet();

}

void sendToIoTtweet()
{
  String  _str = "/U/u.php?id=";
          _str += String(_id);
          _str += "&k=";
          _str += String(_key);
          _str += "&s0=";
          _str += String(_d0);
          _str += "&s1=";
          _str += String(_d1);
          _str += "&s2=";
          _str += String(_d2);
          _str += "&s3=";
          _str += String(_d3);

          Serial.println(_str);
          Serial.println(_str.length());
          CiaoData _resp = Ciao.write("rest","api.iottweet.com", _str);
          Serial.println("" + String(_resp.get(1)) + "" + String(_resp.get(2)));
          
          delay(15000); //IoTtweet policy 
  }
