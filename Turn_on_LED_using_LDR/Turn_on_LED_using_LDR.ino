const int LED = 4;
const int LDR = 26;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop() {
  int ldrStatus = analogRead(LDR);
  
  if(ldrStatus <= 200) {
    digitalWrite(LED,HIGH);
    Serial.print("LED turn on: ");
    Serial.println(ldrStatus);
  }
  else {
    digitalWrite(LED,LOW);
    Serial.print("LED turn off: ");
    Serial.println(ldrStatus);
  }
}
