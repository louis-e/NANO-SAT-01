#include <SPI.h>
#include <WiFiNINA.h>
#include <WiFiUdp.h>

#include "DHT.h"

#include <ArduinoLowPower.h>


//WIFI UDP SERVER
int status = WL_IDLE_STATUS;
#define SECRET_SSID "WIFI NAME"		  //Replace "WIFI NAME" with the name of your Wifi Network
#define SECRET_PASS "WIFI PASSWORD" //Replace "WIFI PASSWORD" with the password of your Wifi Network
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int keyIndex = 0;            // network key index number (needed only for WEP)
unsigned int localPort = 2390;
char packetBuffer[255];
WiFiUDP Udp;

//DHT11 HUMIDITY TEMPERATURE SENSOR
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


float humidity;
float temperature;
bool dhtavaible = false;

//LED
int ledPin1=12;
int ledPin2=13;

//PIEZO BUZZER
int buzzerPin=11;

long timeAlive = 0;


void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  tone(buzzerPin, 1000);
  delay(100);
  noTone(buzzerPin);
  
  dht.begin();
  
  if (WiFi.status() == WL_NO_MODULE) {
    tone(buzzerPin, 1000);
    delay(150);
    noTone(buzzerPin);
  
    delay(150);
    
    tone(buzzerPin, 1000);
    delay(150);
    noTone(buzzerPin);
  
    delay(150);
    
    tone(buzzerPin, 1000);
    delay(150);
    noTone(buzzerPin);
  
    delay(150);
    
    tone(buzzerPin, 1000);
    delay(150);
    noTone(buzzerPin);
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < "1.0.0") {
  }

  while (status != WL_CONNECTED) {
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }

  Udp.begin(localPort);

  
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  
  delay(50);
  
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  
  delay(50);
  
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
  
  delay(50);
  
  tone(buzzerPin, 1000);
  delay(50);
  noTone(buzzerPin);
}

void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    IPAddress remoteIp = Udp.remoteIP();
    int len = Udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    if (String(packetBuffer) == "ConnectionRequest_S01")
    {
      Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
      Udp.write("_________________________________________________\n");
      Udp.write("|        _       __       __ _ ____      __     |\n");
      Udp.write("|   /| )/_| /| )/  ) __  (  /_| /   __  /  )-/  |\n");
      Udp.write("|  / |/(  |/ |/(__/     __)(  |(       (__/ /   |\n");
      Udp.write("_________________________________________________\n");
      Udp.write("                                            \n");
      Udp.write("Connection granted                          (S01)");
      Udp.endPacket();
      
      actionbeep();
    } else if (String(packetBuffer) == "cmd_senddata_humtemp")
    {
      humidity = dht.readHumidity();
      temperature = dht.readTemperature();
      delay(300);
      dhtavaible = false;
      if (isnan(humidity) || isnan(temperature)) {
        dhtavaible = false;
        return;
      } else {
        dhtavaible = true;
      }
      
      Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
      if (dhtavaible)
      {
         Udp.write("Data from DHT sensor:\n");
         Udp.print(dht.readHumidity());
         Udp.write(" % Humidity\n");
         Udp.print(dht.readTemperature());
         Udp.write(" C Temperature");
      } else {
         Udp.write("DHT sensor failed");
      }
      Udp.endPacket();
      
      actionbeep();
    } else if (String(packetBuffer) == "cmd_senddata_timealive"){ 
     Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
     Udp.print(timeAlive);
     Udp.endPacket();
      
     actionbeep();
    } else if (String(packetBuffer) == "cmd_requestaction_led1on") {
     Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
     digitalWrite(ledPin1,HIGH);
     Udp.print("Written digital pin D12 (ON)");
     Udp.endPacket();
      
     actionbeep();
     } else if (String(packetBuffer) == "cmd_requestaction_led1off") {
     Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
     digitalWrite(ledPin1,LOW);
     Udp.print("Written digital pin D12 (OFF)");
     Udp.endPacket();
      
     actionbeep();
     } else if (String(packetBuffer) == "cmd_requestaction_led2on") {
     Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
     digitalWrite(ledPin2,HIGH);
     Udp.print("Written digital pin D13 (ON)");
     Udp.endPacket();
      
     actionbeep();
     } else if (String(packetBuffer) == "cmd_requestaction_led2off") {
     Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
     digitalWrite(ledPin2,LOW);
     Udp.print("Written digital pin D13 (OFF)");
     Udp.endPacket();
      
     actionbeep();
     } else if (String(packetBuffer) == "cmd_requestaction_buzzeron") {
     Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
     tone(buzzerPin, 1000);
     Udp.print("Written digital pin D11 (ON)");
     Udp.endPacket();
     } else if (String(packetBuffer) == "cmd_requestaction_buzzeroff") {
     Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
     noTone(buzzerPin);
     Udp.print("Written digital pin D11 (OFF)");
     Udp.endPacket();
     } else {
     Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
     Udp.write("Unknown command: ");
     Udp.write(packetBuffer);
     Udp.endPacket();
      
     actionbeep();
    } 
  }
  
  //Counting the seconds how long the satellite is on
  static long currentMillis;
  static byte statCounter = 0;
  if (millis() - currentMillis >= 1000)
  {
     timeAlive++;
     currentMillis = millis();
  }
}

void actionbeep(){
  tone(buzzerPin, 1000);
  delay(100);
  noTone(buzzerPin);
}
