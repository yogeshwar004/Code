#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h> // Include the DHT sensor library 

#define DHTPIN 32      // Pin connected to DHT11 sensor 
#define DHTTYPE DHT11  // Specify DHT sensor type as DHT11

DHT dht(DHTPIN, DHTTYPE); // Create a DHT object with specified pin and type 

// Wi-Fi credentials
const char* ssid = "Pixel 8a";
const char* password = "87654321";

// MQTT broker details
const char* mqtt_server = "mqtt.platinumrobotics.com";
const int mqttPort = 1883;
const char* mqttuser = "mqtt_user";
const char* mqttpassword = "8655167646";

// MQTT topics
const char* tempTopic = "ctrl/Sensor/Temperature";
const char* humidityTopic = "ctrl/Sensor/Humidity";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("dht11_client", mqttuser, mqttpassword)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, mqttPort);

  dht.begin(); // Initialize the DHT sensor
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Read temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any reading failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature and humidity
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Publish data to MQTT topics
  char tempStr[8];
  char humidityStr[8];
  dtostrf(temperature, 6, 2, tempStr);  // Convert temperature to string
  dtostrf(humidity, 6, 2, humidityStr); // Convert humidity to string

  client.publish(tempTopic, tempStr);
  client.publish(humidityTopic, humidityStr);

  delay(2000); // Wait 2 seconds before next reading
}
