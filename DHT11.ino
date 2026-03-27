#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPin 4

DHT dht (DHTPin, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  // put your main code here, to run repeatedly:
  int temp = dht.readTemperature();
  int humi = dht.readHumidity();

  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print(" oC, Humidity = ");
  Serial.print(humi);
  Serial.println(" %");
  
}