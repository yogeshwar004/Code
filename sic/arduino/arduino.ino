int testLed= 2;
int testLed1=1;
void setup() {
  // put your setup code here, to run once:
    
    pinMode(testLed, OUTPUT);
    pinMode(testLed1, OUTPUT);
    Serial.begin(115206);
    
}

void loop() {
  // put your main code here, to run repeatedly:  
  
  digitalWrite(testLed, HIGH);
  delay(2000);
  Serial.println("yogeshwar swamy");
  digitalWrite(testLed, LOW);
  
  Serial.println("swamiye saranam ayyapa");
  
  digitalWrite(testLed1, HIGH);
  delay(500);
  digitalWrite(testLed1, LOW);
  delay(500);
  
}