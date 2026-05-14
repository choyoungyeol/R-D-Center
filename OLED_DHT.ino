#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPin 4

DHT dht(DHTPin, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  // initialize the OLED object
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Hello world!");
  display.display();
  delay(2000);
}

void loop() {
  delay(2000);
  // put your main code here, to run repeatedly:
  int temp = dht.readTemperature();
  int humi = dht.readHumidity();
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Temp:");
  display.print(temp);
  display.println(" oC");
  display.print("Humi:");
  display.print(humi);
  display.println(" %");
  display.display();
  delay(2000);
}
