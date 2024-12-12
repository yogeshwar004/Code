#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Pixel 8a";
const char* password = "87654321";

const char* mqtt_server = "mqtt.platinumrobotics.com";
const int mqttPort = 1883;
const char* mqttuser = "mqtt_user";
const char* mqttpassword = "8655167646";

const char* pubtopic = "ctrlFreaks/Sensors/Proximity"; // MQTT topic for motion status

int sensor = 27;            // the pin that the sensor is attached to
int state = LOW;            // by default, no motion detected
int val = 0;                // variable to store the sensor status

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

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("motion_sensor_client", mqttuser, mqttpassword)) {
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
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqttPort);

  pinMode(sensor, INPUT);   // initialize sensor as an input
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  val = digitalRead(sensor);  // read sensor value
  if (val == HIGH) {          // check if the sensor is HIGH
    delay(100);               // delay 100 milliseconds 

    if (state == LOW) {
      Serial.println("Motion detected!");
      client.publish(pubtopic, "Motion detected!");
      state = HIGH;           // update variable state to HIGH
    }
  } else {
    delay(200);               // delay 200 milliseconds 

    if (state == HIGH) {
      Serial.println("Motion stopped!");
      client.publish(pubtopic, "Motion stopped!");
      state = LOW;            // update variable state to LOW
    }
  }
}
