#include <WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#define WIFI_SSID "your_wifi_ssid" #define WIFI_PASS "your_wifi_password" #define ADAFRUIT_IO_USERNAME "your_adafruit_io_username"
#define ADAFRUIT_IO_KEY "your_adafruit_io_key" #define MOTOR_PIN 2
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, "io.adafruit.com", 1883, ADAFRUIT_IO_USERNAME, ADAFRUIT_IO_KEY);Adafruit_MQTT_Subscribe motorControl = Adafruit_MQTT_Subscribe(&mqtt, ADAFRUIT_IO_USERNAME"/feeds/motor-control");
void setup() {
pinMode(MOTOR_PIN, OUTPUT);
WiFi.begin(WIFI_SSID, WIFI_PASS);
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
}
mqtt.subscribe(&motorControl);
}
void loop() {
Adafruit_MQTT_Subscribe *subscription;
while ((subscription = mqtt.readSubscription(5000))) {
if (subscription == &motorControl) {
int state = atoi((char *)motorControl.lastread);
digitalWrite(MOTOR_PIN, state ? HIGH : LOW);
}
}
}