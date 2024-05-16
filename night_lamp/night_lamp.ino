const int IR_SENSOR_PIN = 2; // IR sensor pin
const int BUZZER_PIN = 3; // Buzzer pin
const int LED_PIN = 4; // LED pin
void setup() {
pinMode(IR_SENSOR_PIN, INPUT);
pinMode(BUZZER_PIN, OUTPUT);
pinMode(LED_PIN, OUTPUT);
Serial.begin(9600);
}
void loop() {
if (digitalRead(IR_SENSOR_PIN) == HIGH) { // If IR sensor detects movement
activateAlarmAndLamp();
delay(5000); // Delay to avoid repeated detection
}
delay(100); // Polling interval
}
void activateAlarmAndLamp() {
Serial.println("Morning Alarm Activated!");
digitalWrite(BUZZER_PIN, HIGH); // Turn on buzzer
digitalWrite(LED_PIN, HIGH); // Turn on LED
delay(30000); // Alarm duration
digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
digitalWrite(LED_PIN, LOW); // Turn off LED
}