#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define Threshold 400
#define MQ2pin 0
float sensorValue; //variable to store sensor value
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 columns, 2 rows
void setup() {
lcd.init();
lcd.clear();
lcd.backlight();
lcd.begin(16, 2);
Serial.begin(9600); // sets the serial port to 9600
Serial.println("MQ2 warming up!");
lcd.print("LPG detecting");
delay(20000); // allow the MQ2 to warm up
lcd.clear();
}
void loop() {
sensorValue = analogRead(MQ2pin); // read analog input pin 0
Serial.print("Sensor Value: ");
Serial.print(sensorValue);
Serial.println("");
if(sensorValue > Threshold)
{
lcd.setCursor(2, 0);
lcd.print("LPG gas leaked");
}
else
{
lcd.setCursor(2, 0);
lcd.print("Safe No leak");
}
delay(500); // wait 2s for next reading
}