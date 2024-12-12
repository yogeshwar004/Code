const int trigPin = 26; // TRIG pin (GPIO18) on ESP32
const int echoPin = 25; // ECHO pin (GPIO19) on ESP32

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(trigPin, OUTPUT); // Set TRIG pin as output
  pinMode(echoPin, INPUT); // Set ECHO pin as input
}

void loop() {
  digitalWrite(trigPin, LOW); // Set TRIG pin to low
  delayMicroseconds(2); // Wait for a short time
  
  digitalWrite(trigPin, HIGH); // Send a short pulse to start the measurement
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH); // Measure the time for the pulse to return
  float distance = duration * 0.0343 / 2; // Calculate distance based on time

  Serial.print("Distance: "); // Print distance label
  Serial.print(distance); // Print calculated distance value
  Serial.println(" cm"); // Print unit label

  delay(1000); // Delay between measurements
}
