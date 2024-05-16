#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
#define TRIGGER_PIN 2 // Pin connected to the trigger pin of the ultrasonic sensor
#define ECHO_PIN 3 // Pin connected to the echo pin of the ultrasonic sensor
#define MAX_DISTANCE 200 // Maximum distance in centimeters for the sensor
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 columns, 2 rows
void setup()
{ lcd.begin(16, 2);
lcd.print("Ultrasonic Range");
delay(2000);
lcd.clear();
}
void loop()
{delay(50);
unsigned int distance = sonar.ping_cm();
lcd.setCursor(0, 0);
lcd.print("Distance: ");
lcd.print(distance);
lcd.print(" cm ");
delay(500);
}