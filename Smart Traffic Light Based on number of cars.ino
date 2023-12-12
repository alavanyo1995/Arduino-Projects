const int pirSensorLane1 = 2; // PIR sensor for Lane 1
const int pirSensorLane2 = 3; // PIR sensor for Lane 2

const int redLedLane1 = 4;    // Red LED for Lane 1
const int greenLedLane1 = 5;  // Green LED for Lane 1
const int redLedLane2 = 6;    // Red LED for Lane 2
const int greenLedLane2 = 7;  // Green LED for Lane 2

bool motionDetectedLane1 = false;
bool motionDetectedLane2 = false;

void setup() {
  pinMode(pirSensorLane1, INPUT);
  pinMode(pirSensorLane2, INPUT);
  pinMode(redLedLane1, OUTPUT);
  pinMode(greenLedLane1, OUTPUT);
  pinMode(redLedLane2, OUTPUT);
  pinMode(greenLedLane2, OUTPUT);
}

void loop() {
  motionDetectedLane1 = digitalRead(pirSensorLane1) == HIGH;
  motionDetectedLane2 = digitalRead(pirSensorLane2) == HIGH;

  if (motionDetectedLane1) {
    // Motion detected in Lane 1, turn Lane 1 green and wait until no motion
    turnGreenLane1();
    while (motionDetectedLane1) {
      motionDetectedLane1 = digitalRead(pirSensorLane1) == HIGH;
      delay(1000); // Adjust the delay based on your requirements
    }
    turnRedLane1();
  } else if (motionDetectedLane2) {
    // Motion detected in Lane 2, turn Lane 2 green and wait until no motion
    turnGreenLane2();
    while (motionDetectedLane2) {
      motionDetectedLane2 = digitalRead(pirSensorLane2) == HIGH;
      delay(100); // Adjust the delay based on your requirements
    }
    turnRedLane2();
  } else {
    // No motion detected, set both lanes to default state (both red)
    turnRedLane1();
    turnRedLane2();
  }
}

void turnGreenLane1() {
  digitalWrite(redLedLane1, LOW);
  digitalWrite(greenLedLane1, HIGH);
}

void turnRedLane1() {
  digitalWrite(greenLedLane1, LOW);
  digitalWrite(redLedLane1, HIGH);
}

void turnGreenLane2() {
  digitalWrite(redLedLane2, LOW);
  digitalWrite(greenLedLane2, HIGH);
}

void turnRedLane2() {
  digitalWrite(greenLedLane2, LOW);
  digitalWrite(redLedLane2, HIGH);
}
