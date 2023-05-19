/*
   Smart Pest Detection and Repellent System Prototype
   Detail prototype simulation can be seen here: https://wokwi.com/projects/365135161739188225
   Any feedback or ideas are really appreaciated :)
*/

// Define the PIR sensor pin
const int pirPin = 2;
// Define the LED pin
const int ledPin = 13;
// Define the US pin
const int trigPin = 11;    // Trigger
const int trigPin2 = 7;    // Trigger2
const int echoPin = 12;    // Echo
const int MAX_DISTANCE = 395;
const int MIN_DISTANCE = 3; 
long duration, cm, inches;
uint8_t count;
bool IS_RAT;

void setup() {
  //Serial Port begin
  Serial.begin (9600);
  setupPinMode();
}

void loop() {
  // Turn on the sensor
  turnOnSensor();

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = waitForEcho();

  // Calculate the distance to the object
  float distance = calculateDistance(duration);

  // Check if the PIR sensor and Ultrasonic sensor have detected movement
  if (isRatDetected(distance)) {
    turnOnLED();
    controlTriggerUS2(true);
    IS_RAT = true;
  } else {
    if (IS_RAT) {
      count++;
      turnOffLED();
      controlTriggerUS2(false);
      Serial.print("RAT DETECTED: , ");Serial.println(count);
      IS_RAT = false;
    }
  }
  delay(250);
}

// Define a function to turn on the sensor
void turnOnSensor() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}

void controlTriggerUS2(bool IS_TRIGGER_2_ON) {
  if (!IS_TRIGGER_2_ON) {
    digitalWrite(trigPin2, LOW);
    return;
  }
  digitalWrite(trigPin2, HIGH);
}

void setupPinMode() {
  //Define US inputs and outputs
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Set the PIR sensor pin as an input
  pinMode(pirPin, INPUT);
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

///////////////////////////// HC-SR04 /////////////////////////////////////

// Define a function to wait for the echo pulse to return
int waitForEcho() {
  int echoTime;
  echoTime = pulseIn(echoPin, HIGH);
  return echoTime;
}

// Define a function to calculate the distance to the object
float calculateDistance(int echoTime) {
  float distance = echoTime * 0.034 / 2; // Divide by 29.1 or multiply by 0.0343
  return distance; //(cm)
}

/////////////////////////PIR AND LED
// Define a function to turn on the LED
void turnOnLED() {
  digitalWrite(ledPin, HIGH);
}

// Define a function to turn off the LED
void turnOffLED() {
  digitalWrite(ledPin, LOW);
}

// Define a function to read the PIR sensor value
int readPIRSensor() {
  return digitalRead(pirPin);
}

// Define a function to check if the PIR sensor has detected movement
bool isRatDetected(float distance) {
  int pirValue = digitalRead(pirPin);
  return pirValue == HIGH && (distance >= MAX_DISTANCE || distance <= MIN_DISTANCE);
}
