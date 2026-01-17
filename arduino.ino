#include <Servo.h>


const int trigPin = 10; 
const int echoPin = 11;
const int buzzerPin = 2; 
Servo myServo;

void setup() { 
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzerPin, OUTPUT);
  myServo.attach(9); 
}


void loop() {
for(int angle = 0; angle <= 180; angle++) { 
  myServo.write(angle);
  delay(20); // Adjust speed of sweep as needed int distance = getDistance(); Serial.print(angle);
  Serial.print(","); 
  Serial.println(distance); 
  if (distance < 50) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  delay(50); // Adjust delay as needed
}
  for(int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(20); // Adjust speed of sweep as needed 
    int distance = getDistance();
    Serial.print(angle);
    Serial.print(","); 
    Serial.println(distance); 
    if (distance < 50) {
      digitalWrite(buzzerPin, HIGH);
    } else {
      digitalWrite(buzzerPin, LOW);
    }
    delay(50); // Adjust delay as needed
  }
}


int getDistance() { 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) / 58; // Convert pulse duration to distance in cm
 
}
