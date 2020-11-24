#include "Servo.h"
#include <WiFi.h>
#include "FirebaseESP32.h"

#define FIREBASE_HOST "https://my-android-84b28.firebaseio.com/"
#define FIREBASE_AUTH "xODH8rSm0DWaSxATuHL716X4eI10g9BtakXwQLiq"
#define WIFI_SSID "Flemel"
#define WIFI_PASS "nyxtgu186534"

#define pinLDR 36
#define pinServo 13

String pathLDR = "/iot/ldr";
String pathServo = "/iot/servo";
int ldrValue = 0;

FirebaseData db;
Servo servo;

void connect(){
  WiFi.begin(WIFI_SSID,WIFI_PASS);
  Serial.println("Connecting to wifi");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(200);
  }
  Serial.println();
  Serial.println("Connected to wifi");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
   //Set database read timeout 1 menit (max 15 minutes)
  Firebase.setReadTimeout(db, 1000 * 60);
  Firebase.setwriteSizeLimit(db, "tiny");
}


void setup() {
  Serial.begin(9600);
  servo.attach(pinServo);
  pinMode(pinLDR, INPUT);
  servo.write(0);
  connect();
}

void loop() {
  delay(500);
  
  ldrValue = analogRead(pinLDR);
  if(ldrValue >= 500) {
    servo.write(30);
    Firebase.setDouble(db, pathLDR, ldrValue);
    Firebase.setInt(db, pathServo, 30);
  }
  else {
    servo.write(60);
    Firebase.setDouble(db, pathLDR, ldrValue);
    Firebase.setInt(db, pathServo, 60);
  }
}
