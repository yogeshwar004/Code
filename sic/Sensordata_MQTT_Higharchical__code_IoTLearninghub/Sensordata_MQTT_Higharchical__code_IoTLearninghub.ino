#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// WiFi credentials
const char* ssid = "Pixel 8a";
const char* password = "87654321";

// MQTT broker details
const char* mqtt_server = "mqtt.platinumrobotics.com";
const int mqtt_port = 1883;
const char* mqtt_topic_temp = "ctrlFreaks/Sensors/Temperature";
const char* mqtt_topic_hum = "ctrlFreaks/Sensors/Humidity";
const char* mqtt_username = "mqtt_user"; // Replace with your MQTT username
const char* mqtt_password = "8655167646"; // Replace with your MQTT password

// DHT11 setup
#define DHTPIN 32 // GPIO pin connected to DHT11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// WiFi and MQTT clients
WiFiClient espClient;
PubSubClient client(espClient);

// Function to connect to WiFi
void setupWiFi() {
  delay(10);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("WiFi connected!");
}

// Function to connect to MQTT broker
void setupMQTT() {
  client.setServer(mqtt_server, mqtt_port);
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32Sensor", mqtt_username, mqtt_password)) {
      Serial.println("Connected to MQTT!");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" trying again in 2 seconds");
      delay(2000);
    }
  }
}

// Function to read DHT11 data and publish to separate topics
void readAndPublishDHT11() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Publish temperature
  String tempPayload = String(temperature);
  client.publish(mqtt_topic_temp, tempPayload.c_str());
  Serial.println("Published Temperature: " + tempPayload);

  // Publish humidity
  String humPayload = String(humidity);
  client.publish(mqtt_topic_hum, humPayload.c_str());
  Serial.println("Published Humidity: " + humPayload);
}

void setup() {
  Serial.begin(115200);
  setupWiFi();
  setupMQTT();
  dht.begin();
}

void loop() {
  if (!client.connected()) {
    setupMQTT();
  }
  client.loop();

  // Read and publish sensor data
  readAndPublishDHT11();
  delay(5000); // Publish every 5 seconds
}
