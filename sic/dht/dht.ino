#include <DHT.h>
#include <DHT_U.h>

#include <DHT.h> // Include the DHT sensor library 
#define DHTPIN 17      // Pin connected to DHT11 sensor (GPIO5) 
#define DHTTYPE DHT11   // Specify DHT sensor type as DHT11 
 
DHT dht(DHTPIN, DHTTYPE); // Create a DHT object with specified pin and type 
 
void setup() { 
  Serial.begin(9600); // Initialize serial communication for debugging 
  dht.begin();        // Initialize the DHT sensor 
} 
void loop() { 
  float temperature = dht.readTemperature(); // Read temperature in Celsius 
  float humidity = dht.readHumidity();       // Read humidity 
 
  // Check if any reading failed and exit early 
  if (isnan(temperature) || isnan(humidity)) { 
    Serial.println("Failed to read from DHT sensor!"); // Print an error message 
    return; // Exit the loop and do not proceed with printing values 
  } 
 
  // Print temperature and humidity readings 
  Serial.print("Temperature: "); 
  Serial.print(temperature); // Print temperature value 
  Serial.print(" °C\t"); // Print Celsius symbol and a tab 
 
  Serial.print("Humidity: "); 
  Serial.print(humidity); // Print humidity value 
  Serial.println(" %"); // Print percentage symbol and move to the next line 
 
  delay(2000); // Wait 2 seconds before the next reading 
}