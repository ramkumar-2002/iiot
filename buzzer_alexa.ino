#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <fauxmoESP.h>
#define WIFI_SSID "your_wifi_ssid" #define WIFI_PASS "your_wifi_password" #define BUZZER_PIN 2
fauxmoESP fauxmo;
void wifiSetup() {
WiFi.begin(WIFI_SSID, WIFI_PASS);
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
}
}
void setup() {
Serial.begin(115200);
pinMode(BUZZER_PIN, OUTPUT);
wifiSetup();
fauxmo.addDevice("buzzer");
fauxmo.onMessage( {
if (strcmp(device_name, "buzzer") == 0) {
digitalWrite(BUZZER_PIN, state ? HIGH : LOW);
}
});
}
void loop() {
fauxmo.handle();
}