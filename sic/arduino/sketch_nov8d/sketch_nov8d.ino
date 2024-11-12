const int Bled=1;
const int Gled=2;
int v=10000;
void setup() {
  pinMode(Gled,OUTPUT);
  pinMode(Bled,OUTPUT);

  Serial.begin(9600);
  delay(v);
  Serial.println("Type 'X','G','Y' to turn on corresponding LED.");
  Serial.println("Type '0' to turn off all LEDs");
}

void loop() {
  if (Serial.available()>0)
  {
    char command=Serial.read();
    if(command=='G' || command == toUpperCase('g'))
    {
      digitalWrite(Gled,HIGH);
      delay(v);
      Serial.println("Green LED turned ON.");
    } else if (command == 'B'|| command == toUpperCase('b')) {
      digitalWrite(Bled, HIGH);
      delay(v);
      Serial.println("Blue LED turned ON.");
    }else if(command == 'X'|| command == toUpperCase('x')) {
      digitalWrite(Bled, HIGH);
      delay(v);
      digitalWrite(Gled,HIGH);
      delay(v);
      Serial.println("Both LED turned ON.");
      
    } 
    else if (command == '0') {

      digitalWrite(Gled, LOW);
      digitalWrite(Bled, LOW);
      Serial.println("All LEDs turned OFF.");
    }
  }
}
