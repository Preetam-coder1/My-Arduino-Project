#include <Servo.h> //ultra_sensor_barrigate project: Smartgate

// Pin definitions
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;
const int buzzerPin = 7;
const int led1 = 3;   // LED1: Alert
const int led2 = 4;    // LED2: Gate status

Servo gateServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  gateServo.attach(servoPin);
  gateServo.write(0); // Gate closed
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 15) {
    // Phase 1: Alert
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(led1, HIGH);
    delay(1000); // Alert duration

    // Phase 2: Gate opens
    digitalWrite(buzzerPin, LOW);
    digitalWrite(led1, LOW);
    gateServo.write(90); //  gate open
    digitalWrite(led2, HIGH);
    delay(3000); // Gate open duration

    // Reset
    gateServo.write(0); // Close gate
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

  delay(500); // reset
}