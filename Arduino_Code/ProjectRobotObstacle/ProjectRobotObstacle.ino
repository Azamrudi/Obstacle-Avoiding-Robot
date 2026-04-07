#include <Servo.h>
#include <AFMotor.h>

// Mendifinisikan Pin
#define Echo A0
#define Trig A1
#define motor 10

#define Speed 170
#define spoint 103
#define safeDistance 12


char value;
int distance;
int Left;
int Right;
int L = 0;
int R = 0;

// Object Definitions
Servo servo;
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

//  Function
void setup() {
  // Initialize Serial Communication
  Serial.begin(9600);    // Debugging serial communication

  // Initialize Pins
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  servo.attach(motor);
  servo.write(spoint); // Center servo at startup

  // Set Motor Speed
  M1.setSpeed(Speed);
  M2.setSpeed(Speed);
  M3.setSpeed(Speed);
  M4.setSpeed(Speed);

  // Debug Message
  Serial.println("Robot Initialized");
}

// Main Loop
void loop() {
  Obstacle();
}

// Obstacle Avoidance Function
void Obstacle() {
  // Get the distance to the obstacle
  distance = ultrasonic();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= safeDistance) {
    // Stop and back off if an obstacle is too close
    Stop();
    backward();
    delay(300);
    Stop();

    // Check left and right distances
    L = leftsee();
    R = rightsee();

    // Reset servo to center
    servo.write(spoint);
    delay(500);

    // Debug left and right distances
    Serial.print("Left Distance: ");
    Serial.println(L);
    Serial.print("Right Distance: ");
    Serial.println(R);

    // Decide direction based on measurements
    if (L > R) {
      left(); // Move left if there's more space on the left
      delay(400);
    } else {
      right(); // Move right if there's more space on the right
      delay(400);
    }

    Stop();
  } else {
    // Move forward if path is clear
    forward();
  }
}

// Ultrasonic Sensor Function
int ultrasonic() {
  // Send trigger pulse
  digitalWrite(Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  // Measure echo time
  long t = pulseIn(Echo, HIGH, 30000); // Timeout after 30ms
  int cm = t / 29 / 2; // Convert time to distance (in cm)

  // Validate distance
  if (cm <= 0 || cm > 200) cm = 200; // Cap values to a maximum range
  return cm;
}

// Motor Control Functions
void forward() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

void backward() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}

void right() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

void left() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}

void Stop() {
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
}

// Servo Movement Functions for Scanning
int rightsee() {
  servo.write(20); // Move servo to the right
  delay(800);
  Right = ultrasonic(); // Measure distance
  return Right;
}

int leftsee() {
  servo.write(180); // Move servo to the left
  delay(800);
  Left = ultrasonic(); // Measure distance
  return Left;
}
