#include <WiFi.h>
#include <DHT.h>

const char* ssid = "Pixel 8a";       // Replace with your Wi-Fi SSID
const char* password = "87654321"; // Replace with your Wi-Fi password

#define DHTPIN 5        // Pin connected to DHT11 sensor (GPIO5)
#define DHTTYPE DHT11   // Specify DHT sensor type as DHT11

DHT dht(DHTPIN, DHTTYPE); // Create a DHT object with specified pin and type

WiFiServer server(80); // Create a web server at port 80

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  dht.begin();        // Initialize the DHT sensor
    WiFi.begin(ssid, password); // Connect to Wi-Fi network

  while (WiFi.status() != WL_CONNECTED) { // Wait until connected
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
  
  server.begin(); // Start the web server
  Serial.print("IP Address:");
  Serial.println(WiFi.localIP());
  Serial.println("Server started");
}

void loop() {
  WiFiClient client = server.available(); // Check for incoming client connections
  
  if (client) {
    Serial.println("New client connected");
    
    String htmlContent = "<!DOCTYPE html>"
                         "<html>"
                         "<body>"
                         "<h1>Temperature and Humidity</h1>";
    
    float temperature = dht.readTemperature(); // Read temperature in Celsius
    float humidity = dht.readHumidity();       // Read humidity
    
    // Check if any reading failed
    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Failed to read from DHT sensor!");
      htmlContent += "<p>Failed to read data from sensor.</p>";
    } else {
      // Display temperature and humidity readings in HTML
      htmlContent += "<p>Temperature: " + String(temperature) + " &deg;C</p>"
                     "<p>Humidity: " + String(humidity) + " %</p>";
      // Print temperature and humidity to Serial Monitor
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.print(" °C\t");
      Serial.print("Humidity: ");
      Serial.print(humidity);
      Serial.println(" %");
    }
    
    htmlContent += "</body>"
                   "</html>";
    
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println(htmlContent); // Send the HTML page
    
    delay(10); // Small delay to allow time for client to process
    client.stop(); // Close the connection to the client
    Serial.println("Client disconnected");
  }
}
