// Wave Drive Mode: Strictly ONE LED / ONE Coil active at a time
// Pins: IN1 -> 5, IN2 -> 6, IN3 -> 7, IN4 -> 8

const int motorPin1 = 5; // IN1 (LED A)
const int motorPin2 = 6; // IN2 (LED B)
const int motorPin3 = 7; // IN3 (LED C)
const int motorPin4 = 8; // IN4 (LED D)

// 4-Step Wave Drive Matrix (Only 1 coil ON at any moment)
const int stepMatrix[4][4] = {
  {1, 0, 0, 0}, // Only LED A ON
  {0, 1, 0, 0}, // Only LED B ON
  {0, 0, 1, 0}, // Only LED C ON
  {0, 0, 0, 1}  // Only LED D ON
};

// 2048 single steps = 1 full revolution
const int STEPS_PER_REV = 2048;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Wave Drive: 1 LED at a time active.");
}

void setStep(int s) {
  digitalWrite(motorPin1, stepMatrix[s][0]);
  digitalWrite(motorPin2, stepMatrix[s][1]);
  digitalWrite(motorPin3, stepMatrix[s][2]);
  digitalWrite(motorPin4, stepMatrix[s][3]);
}

void powerOffCoils() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}

void rotateWave(int totalSteps, bool clockwise, int stepDelayMs) {
  if (clockwise) {
    for (int i = 0; i < totalSteps; i++) {
      setStep(i % 4);
      delay(stepDelayMs);
    }
  } else {
    for (int i = 0; i < totalSteps; i++) {
      setStep(3 - (i % 4));
      delay(stepDelayMs);
    }
  }
}

void loop() {
  // Rotate Clockwise (5ms delay per step = clear visible single LED and smooth motion)
  Serial.println("Rotating Clockwise (1 LED at a time: A -> B -> C -> D)...");
  rotateWave(STEPS_PER_REV, true, 5);

  powerOffCoils();
  delay(1000);

  // Rotate Counter-Clockwise
  Serial.println("Rotating Counter-Clockwise (D -> C -> B -> A)...");
  rotateWave(STEPS_PER_REV, false, 5);

  powerOffCoils();
  delay(1000);
}
