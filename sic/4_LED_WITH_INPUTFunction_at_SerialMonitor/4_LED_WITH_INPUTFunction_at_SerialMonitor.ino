const int Rled = 26;
const int Yled = 25;
const int Gled = 5;

void setup() {
  pinMode(Rled, OUTPUT);
  pinMode(Gled, OUTPUT);
  pinMode(Yled, OUTPUT);
  Serial.begin(9600);  // Initialize the serial communication at 9600 bps
  delay(5000);         // Add a delay to allow time for the Serial Monitor to initialize
  Serial.println("Type 'R', 'G', 'Y', 'B' to turn on corresponding LED.");
  Serial.println("Type '0' to turn off all LEDs.");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the command from the serial input

    // Check the command and control the LEDs accordingly
    if (command == 'R') {
      digitalWrite(Rled, HIGH);
      Serial.println("Red LED turned ON.");
    } else if (command == 'Y') {
      digitalWrite(Yled, HIGH);
      Serial.println("Green LED turned ON.");
    } else if (command == 'G') {
      digitalWrite(Gled, HIGH);
      Serial.println("Yellow LED turned ON.");
    } else if (command == '0') {
      digitalWrite(Rled, LOW);
      digitalWrite(Gled, LOW);
      digitalWrite(Yled, LOW);
      Serial.println("All LEDs turned OFF.");
    } else if (command == '1') {
      digitalWrite(Rled, HIGH);
      digitalWrite(Gled, HIGH);
      digitalWrite(Yled, HIGH);
      Serial.println("All LEDs turned OFF.");
    } else if (command == 'r') {
      digitalWrite(Rled, LOW);
      Serial.println("Red LEDs turned OFF.");
    } else if (command == 'y') {
      digitalWrite(Yled, LOW);
      Serial.println("Yellow LEDs turned OFF.");
    } else if (command == 'g') {
      digitalWrite(Gled, LOW);
      Serial.println("Green LEDs turned OFF.");
    }
  }
}
