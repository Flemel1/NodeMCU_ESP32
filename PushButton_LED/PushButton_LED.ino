const int pinLED = 17;
const int pinPushButton = 16;

void setup() {
  pinMode(pinLED,OUTPUT);
  pinMode(pinPushButton,INPUT);
}

void loop() {
  int state_push_button = digitalRead(pinPushButton);
  if(state_push_button == HIGH)
  {
    digitalWrite(pinLED,HIGH);  
  }
  else
  {
    digitalWrite(pinLED,LOW);
  }
}
