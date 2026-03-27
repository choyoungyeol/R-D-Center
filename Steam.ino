#define Steam 13

void setup() {
  pinMode(Steam, OUTPUT);
}

void loop() {
  digitalWrite(Steam, HIGH);
  delay(5000);
  digitalWrite(Steam, LOW);
  delay(10000);
}
