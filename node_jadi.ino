#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define firebaseURl "stalwart-summer-223313.firebaseio.com"
#define authCode "j5CAYp7vVO2TXq5AvpQ7KFqGAhyKjHs7oxQ0mSYL"

const char* ssid = "tttttt";
const char* password = "amarfadillah";
//String chipId = "123";

int a,b,c,d;
bool sekali_set1 =  false, sekali_set2 =  false;
float masuk_keluar,siap_masuk = 0,siap_keluar = 0 ,kunci1 =1,kunci2=1;

void setup() {
  // put your setup code here, to run once:

  pinMode(12, INPUT);
  pinMode(14, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
//  pinMode(16, INPUT); //Masuk
  
  Pengaturan_wifi();
  Pengaturan_data();

//   Serial.begin(115200);
}

void loop() {
  
  // put your main code here, to run repeatedly:
pembacaan_pin();

ambil_data();


}

void Pengaturan_wifi(){
//  Serial.println();
//  Serial.print("Wifi connecting");
//  Serial.print(ssid);

  WiFi.begin(ssid,password);

//  Serial.println();
//  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
//    Serial.print(".");
  }
  delay(2000);
//  Serial.println(WiFi.localIP());
//  Serial.println("wif.iconnect");
}


void Pengaturan_data(){
  Firebase.begin(firebaseURl,authCode);
  delay(1000);
  float checking = Firebase.getFloat("check");
  while(checking != 1){
    Firebase.begin(firebaseURl,authCode);
    float checking = Firebase.getFloat("check");
    delay(1000);
  }
  masuk_keluar = Firebase.getFloat("penumpang1");
}

void ambil_data(){
  
if(a == 1 && b == 1 && kunci1 == 1 ){
  siap_masuk = 1;
  kunci1 =0;
  kunci2 = 0;
//          if (sekali_set1 == true){
//            siap_masuk++;
//      //      masuk_keluar = Firebase.getFloat("kondisi_di_dalam");
//            
//            
//            sekali_set1 = false;
//          }
//  }
//else{
//    
//    sekali_set1 = true;
//    
//  }
}
if(siap_masuk == 1 && c == 1 && d == 1){
  
  masuk_keluar++;
  Firebase.set("penumpang1",masuk_keluar);
  siap_masuk = 0;
}

 if(siap_masuk == 0 && c == 0 && d == 0 && kunci1== 0 && kunci2 == 0){
  kunci1 = 1;
  kunci2 = 1;
 }


if(c == 1 && d == 1  && kunci2 == 1){
//    if (sekali_set2 == true){
////      masuk_keluar = Firebase.getFloat("kondisi_di_dalam");
////      masuk_keluar--;
////      Firebase.set("kondisi_di_dalam",masuk_keluar);
//      siap_keluar++;
//      sekali_set2 = false;
//    }
siap_keluar = 1;
kunci1 = 0;
kunci2 = 0;
  }

//else{
//     sekali_set2 = true;
//  }


if(siap_keluar == 1  && a == 1 && b == 1){
  masuk_keluar--;
  Firebase.set("penumpang1",masuk_keluar);
  siap_keluar = 0;
 }
if(siap_keluar == 0 && a == 0 && b == 0 && kunci1== 0 && kunci2 == 0){
  kunci1 = 1;
  kunci2 = 1;
 }

}

void pembacaan_pin(){
  a = digitalRead(12);
  b = digitalRead(14);
  c = digitalRead(4);
  d = digitalRead(5);
  


  ////////////////
//    Serial.print("p1 : ");
//    Serial.print(a);
//    Serial.print("\t");
//    Serial.print("p2 : ");
//    Serial.print(b);
//    Serial.print("\t");
//    Serial.print("p3 : ");
//    Serial.print(c);
//    Serial.print("\t");
//    Serial.print("p4 : ");
//    Serial.print(d);

}


