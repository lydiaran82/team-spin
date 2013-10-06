// This code should read the state of the button and accelerate/decelerate motor

// Set up pin numbers
const int buttonPin = 2; // The number of the motor pin
const int motorPin = 3; // The number of the motor

// Variable for the motor state
int motorState = 0; 

void setup() {
  // Initialize the motorPin as an input
  pinMode(buttonPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void motorAcceleration() {

  for(int i = 0; i < 256; i++) { // Ramps up to full speed
    analogWrite(motorPin, i); // Sets new speed
    delay(100);
    motorState = digitalRead(buttonPin);
  }
}

void motorDeceleration() {
  
  for(int j = 255; j >=0; j--) { // From full speed PWM to none
    analogWrite(motorPin, j); // Sets new speed
    delay(500);
  }
}

void loop() {
  // Read the state of the motor button
  motorState = digitalRead(buttonPin);
  
  // Check if the button is pressed.
  // If it is, the motorState is HIGH
  if (motorState == HIGH) {
    // Accelerate motor
    motorAcceleration();
    // Keeps the motor on
    while(motorState==HIGH){
      digitalWrite(motorPin, HIGH);
      motorState = digitalRead(buttonPin);
    }
    motorDeceleration();
  }
  else {
    // Decelerates the motor
    // motorDeceleration();
    // Keeps the motor off
    digitalWrite(motorPin, LOW);
  }
}
