// This code should read the state of the button and turn the motor on or off

// Set up pin numbers
const int motorPin = 2; // The number of the motor pin

// Variable for the motor state
int motorState = 0; 

void setup() {
  // Initialize the motorPin as an input
  pinMode(motorPin, INPUT);
}

void loop() {
  // Read the state of the motor button
  motorState = digitalRead(motorPin);
  
  // Check if the button is pressed.
  // If it is, the motorState is HIGH
  if (motorState == HIGH) {
    // Turn the motor on
    digitalWrite(motorPin, HIGH);
  }
  else {
    // Turn the motor off
    digitalWrite(motorPin, LOW);
  }
}


