int gpio=26;
int gpio1=25;
int gpio2=32;
int gpio3=27;
void setup() {
  pinMode(gpio,OUTPUT);
  pinMode(gpio1,OUTPUT);
  pinMode(gpio2,OUTPUT);
pinMode(gpio3,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(gpio, HIGH);
delay(500);
digitalWrite(gpio, LOW);
delay(500);
digitalWrite(gpio1, HIGH);
delay(500);
digitalWrite(gpio1, LOW);
delay(500);
digitalWrite(gpio2, HIGH);
delay(500);
digitalWrite(gpio2, LOW);
delay(500);
digitalWrite(gpio3, HIGH);
delay(500);
digitalWrite(gpio3, LOW);
delay(500);
}

