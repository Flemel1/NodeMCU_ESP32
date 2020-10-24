int pin = 16;


void setup() {
  ledcAttachPin(pin,0);
  ledcSetup(0,5000,8);
  Serial.begin(9600);
}

void loop() {
  for(int i = 0;i<=255;i++) {
    ledcWrite(0,i);
    Serial.println(i);
    delay(10);
  }
  for(int i = 255;i>=0;i--) {
    ledcWrite(0,i);
    Serial.println(i);
    delay(10);
  }
}
