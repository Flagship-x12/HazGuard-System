// Pin Definitions
int gasSensorPin = A0;  // Analog pin for MQ-5 gas sensor
int buzzerPin = 13;     // Pin for buzzer/LED
int threshold = 400;    // Gas level threshold for alert (adjust as needed)

// Calibration values (used for tuning sensitivity)
int baselineValue = 0;  // Stores baseline value from sensor for comparison

void setup() {
  pinMode(buzzerPin, OUTPUT);  // Set buzzerPin as output
  Serial.begin(9600);          // Initialize serial communication for debugging
  
  // Initialize gas sensor
  delay(1000);  // Allow sensor to stabilize
  baselineValue = analogRead(gasSensorPin);  // Read baseline value (when there's no gas)
  Serial.println("HaxGaurd System - LPG Gas Leakage Detector Initialized");
}

void loop() {
  int sensorValue = analogRead(gasSensorPin);  // Read the value from gas sensor
  int gasConcentration = sensorValue - baselineValue; // Get actual gas level

  // Print the gas concentration to the Serial Monitor for debugging
  Serial.print("Gas Level: ");
  Serial.println(gasConcentration);

  // Compare the gas concentration with the threshold
  if (gasConcentration > threshold) {  // If gas leak is detected
    digitalWrite(buzzerPin, HIGH);  // Activate buzzer/LED
    Serial.println("ALERT: Gas Leak Detected!");  // Debugging message
  } else {
    digitalWrite(buzzerPin, LOW);   // Deactivate buzzer/LED
  }

  delay(1000);  // Delay to prevent too frequent readings
}