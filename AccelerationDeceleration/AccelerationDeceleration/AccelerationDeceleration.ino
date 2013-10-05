// This code should read the state of the button and accelerate/decelerate motor

// Set up pin numbers
const int motorPin = 2; // The number of the motor pin

// Variable for the motor state
int motorState = 0; 

void setup() {
  // Initialize the motorPin as an input
  pinMode(motorPin, INPUT);
}

void motorAcceleration() {

  for(int i = 0; i < 256; i++) { // From full speed PWM to none
    analogWrite(motorPin, i); // Sets new speed
    delay(50);
  }
}

void motorDeceleration() {
  
  for(int j = 255; j >=0; j--) { // From full speed PWM to none
    analogWrite(motorPin, j); // Sets new speed
    delay(50);
  }
}

void loop() {
  // Read the state of the motor button
  motorState = digitalRead(motorPin);
  
  // Check if the button is pressed.
  // If it is, the motorState is HIGH
  if (motorState == HIGH) {
    // Accelerate motor
    motorAcceleration();
    // Keeps the motor on
    digitalWrite(motorPin, HIGH);
  }
  else {
    // Decelerates the motor
    motorDeceleration();
    // Keeps the motor off
    digitalWrite(motorPin, LOW);
  }
}
