#define Lamp 11

void setup() {
pinMode(Lamp, OUTPUT);
}

void loop() {
  digitalWrite(Lamp, HIGH);
  delay(5000);
  digitalWrite(Lamp, LOW);
  delay(10000);
}
