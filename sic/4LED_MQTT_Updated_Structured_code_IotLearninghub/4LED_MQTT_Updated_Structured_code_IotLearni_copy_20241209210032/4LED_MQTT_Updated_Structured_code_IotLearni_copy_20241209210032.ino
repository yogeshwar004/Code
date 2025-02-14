#include <WiFi.h>
#include <PubSubClient.h>

// WiFi credentials
const char* ssid = "Pixel 8a";           // Replace with your WiFi SSID
const char* password = "87654321";          // Replace with your WiFi password

// MQTT broker details
const char* mqttServer = "mqtt.platinumrobotics.com";
const int mqttPort = 1883;
const char* mqtt_User = "mqtt_user";          // Replace with your MQTT username
const char* mqtt_Password = "8655167646";     // Replace with your MQTT password

// MQTT topics
const char* pubtopic = "outCtrlFreaks";          // MQTT Publish topic (optional, if used later)
const char* subtopic = "ctrlFreaks/LED";        // MQTT Subscribe topic

//LED pins
const int redLED = 25;    //LED 1 (Red)
const int yellowLED = 26; // LED 2 (Yellow)
const int greenLED = 27;  // LED 3 (Green)
const int blueLED = 32;   // LED 4 (Blue)


WiFiClient espClient;
PubSubClient client(espClient);

// Wi-Fi connection function
void setup_wifi() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
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

  // Control LEDs based on the received message
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
    if (client.connect("ESP32Client", mqtt_User, mqtt_Password)) {
      Serial.println("Connected to MQTT broker!");
      client.subscribe(subtopic); // Subscribe to topic
      Serial.print("Subscribed to topic: ");
      Serial.println(subtopic);
    } else {
      Serial.print("Failed to connect. MQTT state: ");
      Serial.println(client.state());
      delay(5000); // Retry after 5 seconds
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  // Initialize LED pins as OUTPUT
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  // Turn off all LEDs initially
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);

  Serial.println("Setup complete. Waiting for MQTT messages...");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop(); // Process MQTT messages
}
