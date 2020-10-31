#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

#define DHTPIN 32
#define DHTTYPE DHT11
#define ldrPin 36
#define BLYNK_GREEN     "#23C48E"
#define BLYNK_RED       "#D3435C"

const int ledLdrRed = 4;
const int ledLdrGreen = 16;
const int ledTemperatureRed = 17;
const int ledTemperatureGreen = 33;
char auth[] = "nPrMYaBncFzciWva0VhotwHzJkkNHpxO"; //token auth   
char ssid[] = "Flemel"; //ssid wifi
char pass[] = "nyxtgu186534"; // pass wifi
int luxLimit = 0;
int temperatureLimit = 0;
int buttonValue = 0;

WidgetLED ledLux(V6);
WidgetLED ledTemperature(V7);

BlynkTimer timer;
DHT dht(DHTPIN,DHTTYPE);

BLYNK_WRITE(V4) {
  luxLimit = param.asInt();
  Serial.print("Lux: ");
  Serial.println(luxLimit);
}

BLYNK_WRITE(V5) {
  temperatureLimit = param.asInt();
  Serial.print("Temperature: ");
  Serial.println(temperatureLimit);
}

BLYNK_WRITE(V8) {
  buttonValue = param.asInt();
}


void setup() {
  Serial.begin(9600);
  pinMode(ledLdrRed, OUTPUT);
  pinMode(ledLdrGreen, OUTPUT);
  pinMode(ledTemperatureRed,OUTPUT);
  pinMode(ledTemperatureGreen,OUTPUT);
  Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,3), 8080);
  timer.setInterval(1000L, getTemperatureInCelcius);
  timer.setInterval(1000L, getLight);
  dht.begin();
  ledLux.on();
  ledTemperature.on();
}

void loop() {
  Blynk.run();
  if(buttonValue == 1)
  {
    timer.run();
    Serial.println("System ON");
  }
  else {
    Serial.println("System OFF");
    digitalWrite(ledLdrRed, LOW);
    digitalWrite(ledLdrGreen, LOW);
    digitalWrite(ledTemperatureRed,LOW);
    digitalWrite(ledTemperatureGreen,LOW);
  }
}

void getTemperatureInCelcius() {
  float celcius = dht.readTemperature();
  if(celcius <= temperatureLimit) {
    Blynk.virtualWrite(V1,celcius);
    Blynk.virtualWrite(V3,celcius);
    Serial.println(celcius);
    digitalWrite(ledTemperatureRed,LOW);
    digitalWrite(ledTemperatureGreen,HIGH);
    ledTemperature.setColor(BLYNK_GREEN);
    Serial.println("TEMPERATURE LED  GREEN");
  }
  else {
    Blynk.virtualWrite(V1,celcius);
    Blynk.virtualWrite(V3,celcius);
    Serial.println(celcius);
    digitalWrite(ledTemperatureRed,HIGH);
    digitalWrite(ledTemperatureGreen,LOW);
    ledTemperature.setColor(BLYNK_RED);
    Serial.println("TEMPERATURE LED  RED");
  }
}

void getLight() {
  int input = analogRead(ldrPin);
  int ldrStatus = (0.009768 * input) + 10;
  if(ldrStatus <= luxLimit) {
    Serial.println(ldrStatus);
    Blynk.virtualWrite(V0,ldrStatus);
    Blynk.virtualWrite(V2,ldrStatus);
    digitalWrite(ledLdrRed,LOW);
    digitalWrite(ledLdrGreen,HIGH);
    ledLux.setColor(BLYNK_GREEN);
    Serial.print("LUX LED GREEN");
  }
  else {
    Serial.println(ldrStatus);
    Blynk.virtualWrite(V0,ldrStatus);
    Blynk.virtualWrite(V2,ldrStatus);
    digitalWrite(ledLdrRed,HIGH);
    digitalWrite(ledLdrGreen,LOW);
    ledLux.setColor(BLYNK_RED);
    Serial.print("LUX LED RED");
  }
}
