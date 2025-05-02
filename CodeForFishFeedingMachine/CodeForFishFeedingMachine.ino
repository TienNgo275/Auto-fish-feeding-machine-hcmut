#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#define BLYNK_TEMPLATE_ID "" // insert your template ID here
#define BLYNK_TEMPLATE_NAME ""// insert your template name here
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = ""; // Token can be found in your email
char ssid[] = ""; // WiFi name
char pass[] = ""; // WiFi password

Servo servo;
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servo.attach(2);
  stopServo();
}

void spinServo1() {
  int speed = 100; // Adjust speed as needed (0-255)

  // Rotate in one direction (clockwise)
  servo.writeMicroseconds(1500 - speed);
  delay(2125); // Rotation time greater than 5 seconds

  // Stop the servo
  stopServo();
}

void spinServo2() {
  int speed = 100; // Adjust speed as needed (0-255)

  // Rotate in one direction (clockwise)
  servo.writeMicroseconds(1500 - speed);
  delay(2100); // Rotation time greater than 5 seconds

  // Stop the servo
  stopServo();
}

void stopServo() {
  // Stop the servo by sending a stop signal
  servo.writeMicroseconds(1500);
}

BLYNK_WRITE(V3) {
  int buttonState = param.asInt();
  if (buttonState == 1) {
    spinServo1();
    Blynk.virtualWrite(V3, 0); // Reset the button state
  }
}

BLYNK_WRITE(V4) {
  int buttonState = param.asInt();
  if (buttonState == 1) {
    spinServo2();
    Blynk.virtualWrite(V4, 0); // Reset the button state
  }
}

BLYNK_WRITE(V5)
{
  servo.write(param.asInt());
}
void loop() {
  Blynk.run();
}