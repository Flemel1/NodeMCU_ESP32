#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int pin = 4;
char auth[] = "JCYcnUopgmmH1yXp1a5WrZl2_WaAbJEA";       // You should get Auth Token in the Blynk App.
char ssid[] = "Flemel";                    // Your Wi-Fi Credentials
char pass[] = "nyxtgu186534";
void setup() {  
  pinMode(pin, OUTPUT); 
  pinMode(pin, HIGH);
  Serial.begin(9600);
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println("WiFi connected");  
  Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,6), 8080);
}
void loop(){
   Blynk.run();
}
