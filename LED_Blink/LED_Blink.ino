const int PIN_OUTPUT_MERAH = 16;
const int PIN_OUTPUT_KUNING = 17;
const int PIN_OUTPUT_HIJAU = 4;

void setup() {
  pinMode(PIN_OUTPUT_MERAH,OUTPUT);
  pinMode(PIN_OUTPUT_KUNING,OUTPUT);
  pinMode(PIN_OUTPUT_HIJAU,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(PIN_OUTPUT_MERAH,HIGH);
  digitalWrite(PIN_OUTPUT_KUNING,LOW);
  digitalWrite(PIN_OUTPUT_HIJAU,LOW);
  delay(7000);
  digitalWrite(PIN_OUTPUT_MERAH,LOW);
  digitalWrite(PIN_OUTPUT_KUNING,HIGH);
  digitalWrite(PIN_OUTPUT_HIJAU,LOW);
  delay(3000);
  digitalWrite(PIN_OUTPUT_MERAH,LOW);
  digitalWrite(PIN_OUTPUT_KUNING,LOW);
  digitalWrite(PIN_OUTPUT_HIJAU,HIGH);
  delay(5000);
}
