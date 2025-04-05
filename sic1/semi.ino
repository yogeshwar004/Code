#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Wi-Fi credentials
const char* ssid = "Pixel 8a";
const char* password = "87654321";

// MQTT broker details
const char* mqtt_server = "mqtt.platinumrobotics.com";
const int mqttPort = 1883;
const char* mqttuser = "mqtt_user";
const char* mqttpassword = "8655167646";

// MQTT topics
const char* ledTopic = "ctrlFreaks/LED";
const char* motionTopic = "ctrlFreaks/Sensors/Proximity";
const char* tempTopic = "ctrl/Sensor/Temperature";
const char* humidityTopic = "ctrl/Sensor/Humidity";

// LED Pins
const int redLED = 25;
const int yellowLED = 26;
const int greenLED = 27;
const int blueLED = 32;

// Motion Sensor
const int motionSensor = 33;
int motionState = LOW; 

// DHT Sensor
#define DHTPIN 0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Wi-Fi & MQTT setup
WiFiClient espClient;
PubSubClient client(espClient);

// Wi-Fi connection function
void setup_wifi() {
  Serial.println("Resetting and connecting to WiFi...");
  
  WiFi.disconnect(true, true);     // Clear old credentials
  delay(1000);

  WiFi.mode(WIFI_STA);            // Set to Station mode
  WiFi.begin(ssid, password);     // Connect to hotspot

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ WiFi connected!");
    digitalWrite(redLED,HIGH);
    delay(2000);
    digitalWrite(redLED,LOW);
    Serial.print("📶 IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n❌ Failed to connect to WiFi.");
  }
}
// MQTT message callback
void callback(char* topic, byte* payload, unsigned int length) {
  String msgString = "";
  for (int i = 0; i < length; i++) {
    msgString += (char)payload[i];
  }

  Serial.print("Message received on topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  Serial.println(msgString);

  // Control LEDs
  if (msgString == "on1") {
    digitalWrite(redLED, HIGH);
    Serial.println("RED LED ON");
  } else if (msgString == "off1") {
    digitalWrite(redLED, LOW);
    Serial.println("RED LED OFF");
  } else if (msgString == "on2") {
    digitalWrite(yellowLED, HIGH);
    Serial.println("YELLOW LED ON");
  } else if (msgString == "off2") {
    digitalWrite(yellowLED, LOW);
    Serial.println("YELLOW LED OFF");
  } else if (msgString == "on3") {
    digitalWrite(greenLED, HIGH);
    Serial.println("GREEN LED ON");
  } else if (msgString == "off3") {
    digitalWrite(greenLED, LOW);
    Serial.println("GREEN LED OFF");
  } else if (msgString == "on4") {
    digitalWrite(blueLED, HIGH);
    Serial.println("BLUE LED ON");
  } else if (msgString == "off4") {
    digitalWrite(blueLED, LOW);
    Serial.println("BLUE LED OFF");
  } else {
    Serial.println("Unknown command");
  }
}

// Reconnect to MQTT broker
void reconnect() {
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    if (client.connect("ESP32Client", mqttuser, mqttpassword)) {
      Serial.println("Connected to MQTT broker!");
      client.subscribe(ledTopic);
      Serial.print("Subscribed to topic: ");
      Serial.println(ledTopic);
    } else {
      Serial.print("Failed to connect. MQTT state: ");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

// Motion Detection
void checkMotion() {
  int val = digitalRead(motionSensor);
  if (val == HIGH) {  
    delay(100);
    if (motionState == LOW) {
      Serial.println("Motion detected!");
      client.publish(motionTopic, "Motion detected!");
      motionState = HIGH;
    }
  } else {
    delay(200);
    if (motionState == HIGH) {
      Serial.println("Motion stopped!");
      client.publish(motionTopic, "Motion stopped!");
      motionState = LOW;
    }
  }
}

// Read & Publish DHT11 Data
void readDHTSensor() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  char tempStr[8];
  char humidityStr[8];
  dtostrf(temperature, 6, 2, tempStr);
  dtostrf(humidity, 6, 2, humidityStr);

  client.publish(tempTopic, tempStr);
  client.publish(humidityTopic, humidityStr);
}

// Setup function
void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqttPort);
  client.setCallback(callback);

  dht.begin();

  // Initialize LEDs
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);

  // Initialize Motion Sensor
  pinMode(motionSensor, INPUT);

  Serial.println("Setup complete. Waiting for MQTT messages...");
}

// Main loop
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  checkMotion();
  readDHTSensor();

  delay(2000);
}
