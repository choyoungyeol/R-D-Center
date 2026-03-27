#define Fan 12

void setup() {
pinMode(Fan, OUTPUT);
}

void loop() {
  digitalWrite(Fan, HIGH);
  delay(5000);
  digitalWrite(Fan, LOW);
  delay(10000);

}
