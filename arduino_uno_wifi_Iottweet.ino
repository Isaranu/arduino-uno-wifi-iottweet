#include <Wire.h>
#include <UnoWiFiDevEd.h>

String _id = "000031";
String _key = "qisxbp8ycwuw";

float _d0, _d1, _d2, _d3;  

void setup() {
  Serial.begin(115200);
  Ciao.begin();
}

void loop() {
  
//Example data generating
  _d0 = random(20,80);
  _d1 = random(30,70);
  _d2 = random(40,60);
  _d3 = random(50,55);

  sendToIoTtweet();
  /*Bug : 
    1. Ciao ส่ง Payload ได้ไม่เกิน 70 character/packet.
    2. ทำเป็น Lib. ไม่ได้ (ยังไม่ทราบสาเหตุ)
    3. ส่ง argument เข้าไปใน function ไม่ได้
  */

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
