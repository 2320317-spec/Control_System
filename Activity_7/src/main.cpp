#include <Arduino.h>
#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(9); // Connect Signal wire to Pin 9
  myServo.write(0);  // Start at 0 degrees
  Serial.println("System Ready: Enter Angle 0-180");
}

void loop() {
  // Check if data is waiting in the buffer
  if (Serial.available() > 0) {
    
    // Serial.parseInt() looks for the next valid integer
    int angle = Serial.parseInt();
    
    // Validation Check (Error catching on hardware side)
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);
      Serial.print("Moved to: ");
      Serial.println(angle);
    } else {
      // This helps catch numbers like 250 or -5
      Serial.println("Invalid: Please enter 0 to 180.");
    }
  }
}