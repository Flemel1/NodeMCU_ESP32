#include "DHT.h"

#define DHTPIN 32 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int LED_1 = 16; //LED Merah
const int LED_2 = 17; //LED Kuning
const int LED_3 = 4; //LED Hijau
const int PIN_INPUT = 36;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(PIN_INPUT,INPUT);
  dht.begin();
}

void loop() {
  delay(2000);

  int state_push_button = digitalRead(PIN_INPUT);
  
  if(state_push_button == HIGH)
  {
    float h = dht.readHumidity(); //kelembapan
    float t = dht.readTemperature(); //data berupa celsius
    float f = dht.readTemperature(true); // data berupa fahrenheit
  
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }
  
    float hif = dht.computeHeatIndex(f, h); //panas dalam fahrenheit
    float hic = dht.computeHeatIndex(t, h, false); // panas dalam celcius
  
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("°C "));
    Serial.print(hif);
    Serial.println(F("°F"));
  
    if(t < 35)
    {
      digitalWrite(LED_3,HIGH);
      digitalWrite(LED_2,LOW);
      digitalWrite(LED_1,LOW);
    }
    else if(t >= 35 && t <= 50)
    {
      digitalWrite(LED_3,HIGH);
      digitalWrite(LED_2,HIGH);
      digitalWrite(LED_1,LOW);
    }
    else
    {
      digitalWrite(LED_3,HIGH);
      digitalWrite(LED_2,HIGH);
      digitalWrite(LED_1,HIGH);
    }
  }

}
