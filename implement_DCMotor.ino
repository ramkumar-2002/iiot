//library BluetoothSerial by Henry Abrahamsen
#include "BluetoothSerial.h" 3. BluetoothSerial serialBT;
char val ;
// Motor A connections
int enA = 32;
int in1 = 35;
int in2 = 34;
void setup() {
serialBT.begin("ESP32-LAB");
Serial.begin(9600); // sets the serial port to 9600
Serial.println("Setup Complete");
// Set all the motor control pins to outputs
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
// Turn off motors - Initial state
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
}
void loop() {

// Set motors to maximum speed
// For PWM maximum possible values are 0 to 255
analogWrite(enA, 255);
if(serialBT.available()){v
al = serialBT.read();
}
if(val == '1'){
//spin Forward
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
}
if(val == '2'){
//spin Backward
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
}
if(val == '0'){
//Motor OFF
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
}
delay(30);
 }