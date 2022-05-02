#define BLYNK_TEMPLATE_ID "TMPLwLHWTBPjS"
#define BLYNK_DEVICE_NAME "ESP8266"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <SimpleTimer.h>
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"
BlynkTimer timer;
#define WIFI_LED  D0
#include <DHT.h>
#define DHTPIN D3  
#define DHTPIN2 D2  
#define DHTTYPE DHT11 
#define DHTTYPE2 DHT11

DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE2);
int map1, map2, mmm;
float t, h;
float t2, h2;
bool isconnected = false;
int kitchen ;
int storeroom ;

SoftwareSerial NodeMCU(D5, D6);

void checkBlynkStatus() {
  
  isconnected = Blynk.connected();
  if (isconnected == true) {
    a();
    digitalWrite(WIFI_LED, HIGH);
    Serial.println("Blynk Connected");
       if(kitchen == 1 )
        {
          sendSensor();
          }
          else
          {
            Blynk.virtualWrite(V1, map1=0);
            Blynk.virtualWrite(V3, t=0);
            Blynk.virtualWrite(V4, h=0);
          }
        if(storeroom == 1)
         {
          sendSensor2();

          }
          else
          {
            Blynk.virtualWrite(V2, map2=0);
            Blynk.virtualWrite(V5, t2=0);
            Blynk.virtualWrite(V6, h2=0);
            }
  }
  else{
    digitalWrite(WIFI_LED, HIGH);
    Serial.println("Blynk Not Connected");
  }
}
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
     Blynk.virtualWrite(V3, t);
     Blynk.virtualWrite(V4, h);
}
void sendSensor2()
{
  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature(); 
 
  if (isnan(h2) || isnan(t2)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V5, t2);
  Blynk.virtualWrite(V6, h2);
}

void a() {
  if (NodeMCU.available() > 0) {
    mmm = NodeMCU.parseInt();
    if (NodeMCU.read() == '\n') {
      Serial.println(mmm);
      if (mmm >= 2000 && mmm <= 3023) {
        int map1 = mmm;
        map1 = map1 - 2000;
        Serial.print(" map1 : ");         Serial.println(map1);
        if(kitchen == 1)
        {
          Blynk.virtualWrite(V1, map1);
          }
      }
      if (mmm >= 4000 && mmm <= 5023) {
        int map2 = mmm;
        map2 = map2 - 4000;
        Serial.print(" map2 : ");         Serial.println(map2);
        if(storeroom == 1)
        {
          Blynk.virtualWrite(V2, map2);
          }
      }
    }
  }
}
BLYNK_WRITE(V0)
{
  kitchen = param.asInt();
 }

 BLYNK_WRITE(V7)
{
   storeroom = param.asInt();
 }
 
void setup()
{
  Serial.begin(115200);
  NodeMCU.begin(9600);
  delay(100);
  dht.begin();
  dht2.begin();
  pinMode(WIFI_LED, OUTPUT);
   
  digitalWrite(WIFI_LED, LOW);
  timer.setInterval(400L, checkBlynkStatus);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}
