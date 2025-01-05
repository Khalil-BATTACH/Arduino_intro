// Pin definitions for sensors and motors
const int leftSensorPin = A0;  // Left IR sensor connected to analog pin A0
const int rightSensorPin = A1; // Right IR sensor connected to analog pin A1
const int leftMotorPin1 = 2;   // Left motor control pin 1
const int leftMotorPin2 = 3;   // Left motor control pin 2
const int rightMotorPin1 = 4;  // Right motor control pin 1
const int rightMotorPin2 = 5;  // Right motor control pin 2

// Threshold for detecting the line (adjust based on sensor readings)
const int sensorThreshold = 500;

void setup() {
  // Set motor pins as OUTPUT
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  // Set sensor pins as INPUT
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int leftSensorValue = analogRead(leftSensorPin);
  int rightSensorValue = analogRead(rightSensorPin);

  // Debugging: Print sensor values to Serial Monitor
  Serial.print("Left Sensor: ");
  Serial.print(leftSensorValue);
  Serial.print(" | Right Sensor: ");
  Serial.println(rightSensorValue);

  // Line-following logic
  if (leftSensorValue < sensorThreshold && rightSensorValue < sensorThreshold) {
    // Both sensors detect the line: move forward
    moveForward();
  } else if (leftSensorValue < sensorThreshold && rightSensorValue >= sensorThreshold) {
    // Left sensor detects the line: turn left
    turnLeft();
  } else if (leftSensorValue >= sensorThreshold && rightSensorValue < sensorThreshold) {
    // Right sensor detects the line: turn right
    turnRight();
  } else {
    // No line detected: stop
    stopRobot();
  }
}

// Function to move the robot forward
void moveForward() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

// Function to turn the robot left
void turnLeft() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

// Function to turn the robot right
void turnRight() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
}

// Function to stop the robot
void stopRobot() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
}