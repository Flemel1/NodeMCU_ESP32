const int PIN_OUTPUT_MERAH = 16;
const int PIN_OUTPUT_KUNING = 17;
const int PIN_OUTPUT_HIJAU = 4;
const long INTERVAL = 3000;
int ledState_Merah = LOW;
int ledState_Kuning = LOW;
int ledState_Hijau = LOW;
unsigned long previousMillis = 0;

void setup() {
  pinMode(PIN_OUTPUT_MERAH,OUTPUT);
  pinMode(PIN_OUTPUT_KUNING,OUTPUT);
  pinMode(PIN_OUTPUT_HIJAU,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= INTERVAL)
    previousMillis = currentMillis;
  {
    if(ledState_Merah == LOW && ledState_Kuning == LOW && ledState_Hijau == LOW)
    {
      ledState_Merah = HIGH;
      digitalWrite(PIN_OUTPUT_MERAH,ledState_Merah);
      digitalWrite(PIN_OUTPUT_KUNING,ledState_Kuning);
      digitalWrite(PIN_OUTPUT_HIJAU,ledState_Hijau);
    }
    else if(ledState_Merah == HIGH && ledState_Kuning == LOW && ledState_Hijau == LOW)
    {
      ledState_Merah = LOW;
      ledState_Kuning = HIGH;
      digitalWrite(PIN_OUTPUT_MERAH,ledState_Merah);
      digitalWrite(PIN_OUTPUT_KUNING,ledState_Kuning);
      digitalWrite(PIN_OUTPUT_HIJAU,ledState_Hijau);
    }
    else if(ledState_Merah == LOW && ledState_Kuning == HIGH && ledState_Hijau == LOW)
    {
      ledState_Kuning = LOW;
      ledState_Hijau = HIGH;
      digitalWrite(PIN_OUTPUT_MERAH,ledState_Merah);
      digitalWrite(PIN_OUTPUT_KUNING,ledState_Kuning);
      digitalWrite(PIN_OUTPUT_HIJAU,ledState_Hijau);
    }
    else
    {
      ledState_Hijau = LOW;
    }
  }
  delay(5000);
}
