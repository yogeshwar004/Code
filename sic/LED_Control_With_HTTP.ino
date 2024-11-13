#include <WiFi.h>

const char* ssid = "Pixel 8a";       // Your Wi-Fi SSID
const char* password = "87654321"; // Your Wi-Fi password

//const char* ssid = "realme_GTNEO_3150W";
//const char* password = "deeptanshu27";

const int Rled = 26;
const int Gled = 25;
const int Yled = 27;
const int Bled = 32;

WiFiServer server(80); // Create a web server at port 80

void setup() {
  pinMode(Rled, OUTPUT);
  pinMode(Gled, OUTPUT);
  pinMode(Yled, OUTPUT);
  pinMode(Bled, OUTPUT);

  Serial.begin(9600);
  delay(2000); // Allow time for Serial Monitor to initialize

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.begin(); // Start the web server
  Serial.println("Server started");

  Serial.println();
  Serial.println("Connected to WiFi");
  
  // Display Wi-Fi details
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available(); // Check for client requests

  if (client) {
    Serial.println("New client connected");
    String currentLine = "";
    
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n') {
          // Check the request to control LEDs
          if (currentLine.indexOf("GET /red/on") != -1) {
            digitalWrite(Rled, HIGH);
          } else if (currentLine.indexOf("GET /red/off") != -1) {
            digitalWrite(Rled, LOW);
          }
          // Repeat similar checks for other LEDs here
          
          // Send the response to the client
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          client.println("<html><body>");
          client.println("<h1>LED Control</h1>");
          // Create buttons to control LEDs
          client.println("<a href=\"/red/on\">Turn Red LED ON</a><br>");
          client.println("<a href=\"/red/off\">Turn Red LED OFF</a><br>");
          // Repeat for other LEDs
          client.println("</body></html>");
          break;
        } else {
          currentLine += c;
        }
      }
    }
    
    delay(10);
    client.stop();
    Serial.println("Client disconnected");
  }
}
