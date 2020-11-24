#include <Servo.h>
#include <WiFi.h>
#include <MQTT.h>


#define ldrPin 36

const char ssid[] = "Flemel";
const char pass[] = "nyxtgu186534";


WiFiClient net;
Servo myServo;
MQTTClient client;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("ESP32", "7bff9837", "1957d210a5778121")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("/test");
  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("Payload: " + payload);
  int ldrValue = payload.toInt();
  if(ldrValue <= 700) {
    myServo.write(90);
  }
  else {
    myServo.write(30);
  }
}


void setup() {
  Serial.begin(9600);
  myServo.attach(13);
  myServo.write(0);
  WiFi.begin(ssid, pass);

  client.begin("broker.shiftr.io", net);
  client.onMessage(messageReceived);

  connect();
}

void loop() {
  client.loop();
  delay(500);

  if (!client.connected()) {
    connect();
  }

  int ldrStatus = analogRead(ldrPin);
  String data = String(ldrStatus);
  client.publish("/test", data);
}
