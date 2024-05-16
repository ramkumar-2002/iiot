#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>dht DHT;
#define DHTPIN 2 // Pin where the DHT11 is connected#define
DHTTYPE DHT11 // DHT sensor type
const int temperatureThreshold = 30; // Set your temperature threshold here
LiquidCrystal_I2C lcd(0x27, 16, 2);
// I2C address 0x27, 16 columns, 2 rows
void setup() {
Serial.begin(9600);
lcd.begin(16, 2); // initialize the lcd lcd.backlight(); // turn on
the backlightlcd.setCursor(0, 0); lcd.print("Temperature:");
delay(2000); // Wait for 2 seconds before starting measurements
}
void loop() {
int chk = DHT.read11(DHTPIN);
float temperature = DHT.temperature;
lcd.setCursor(0, 1);
lcd.print("Temp: ");
lcd.print(temperature);lcd.print(" C ");
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" °C");
if (temperature > temperatureThreshold) {
Serial.println("High temperature detected! Possible fire!");lcd.setCursor(0, 0);
lcd.print("High Temp! Fire!");
} else { lcd.setCursor(0, 0);
lcd.print("Temperature:");
}
delay(2000); // Wait for 2 seconds between measurements
}