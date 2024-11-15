#include <WiFi.h>
#include <DHT.h>

const char* ssid = "Pixel 8a";      
const char* password = "87654321";   

#define DHTPIN 27                     
#define DHTTYPE DHT11                
DHT dht(DHTPIN, DHTTYPE);           


#define LED1 26 //yellow
#define LED2 32 //white
#define LED3 5  //red
#define LED4 17 //green

WiFiServer server(80);               

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  server.begin();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available(); 
  
  if (client) {
    Serial.println("New client connected");
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    if (request.indexOf("/LED1=ON") != -1) digitalWrite(LED1, HIGH);
    if (request.indexOf("/LED1=OFF") != -1) digitalWrite(LED1, LOW);
    if (request.indexOf("/LED2=ON") != -1) digitalWrite(LED2, HIGH);
    if (request.indexOf("/LED2=OFF") != -1) digitalWrite(LED2, LOW);
    if (request.indexOf("/LED3=ON") != -1) digitalWrite(LED3, HIGH);
    if (request.indexOf("/LED3=OFF") != -1) digitalWrite(LED3, LOW);
    if (request.indexOf("/LED4=ON") != -1) digitalWrite(LED4, HIGH);
    if (request.indexOf("/LED4=OFF") != -1) digitalWrite(LED4, LOW);
     if (request.indexOf("/LED5=ON") != -1) {digitalWrite(LED1, HIGH);digitalWrite(LED2, HIGH);digitalWrite(LED3, HIGH);digitalWrite(LED4, HIGH);}
    if (request.indexOf("/LED5=OFF") != -1) {digitalWrite(LED1, LOW);digitalWrite(LED2, LOW);digitalWrite(LED3, LOW);digitalWrite(LED4, LOW);}
    
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    String htmlContent = "<!DOCTYPE html>"
                         "<html><head>"
                         "<style>body {font-family: Times New Roman; text-align: center; background-color: pink; border: 3px solid #333;}"
                         "p{border:2px; border-color:blue}"
                         "h1 {color: #333;}"
                         ".container {width: 100%; max-width: 600px; margin: auto; padding: 20px;}"
                         ".button {padding: 10px 20px; margin: 10px; border: none; border-radius: 5px;}"
                         ".on {background-color: #4CAF50; color: white;}"
                         ".off {background-color: #f44336; color: white;}"
                         ".status1 {padding: 10px; margin-top: 20px; background-color: lightblue; border-radius: 5px;font-size: 20px;}"
                         ".status2 {padding: 10px; margin-top: 20px; background-color: lightgreen; border-radius: 5px;font-size: 20px;}</style>"
                         "</head><body><div class='container'>"
                         "<h1>Home Automation System</h1>";
    
    if (isnan(temperature) || isnan(humidity)) {
      htmlContent += "<p>Failed to read data from sensor.</p>";
    } 
    else {
      htmlContent += "<div class='status1'><p>Temperature: " + String(temperature) + " &deg;C</p>"
                      "</p></div>"+"<div class='status2'>"+"<p>Humidity: " + String(humidity) +"%</p></div> ";
    }

    htmlContent += "<h2>LED Controls</h2>"
                   "<p>LED1=YELLOW<BR>LED2=WHITE<BR>LED3=RED<BR>LED4=GREEN<BR>LED5=ALL OF THE ABOVE</p>"
                   "<p><a href='/LED1=ON'><button class='button on'>LED 1 ON</button></a>"
                   "<a href='/LED1=OFF'><button class='button off'>LED 1 OFF</button></a></p>"
                   "<p><a href='/LED2=ON'><button class='button on'>LED 2 ON</button></a>"
                   "<a href='/LED2=OFF'><button class='button off'>LED 2 OFF</button></a></p>"
                   "<p><a href='/LED3=ON'><button class='button on'>LED 3 ON</button></a>"
                   "<a href='/LED3=OFF'><button class='button off'>LED 3 OFF</button></a></p>"
                   "<p><a href='/LED4=ON'><button class='button on'>LED 4 ON</button></a>"
                   "<a href='/LED4=OFF'><button class='button off'>LED 4 OFF</button></a></p>"
                   "<p><a href='/LED5=ON'><button class='button on'>LED 5 ON</button></a>"
                   "<a href='/LED5=OFF'><button class='button off'>LED 5 OFF</button></a></p>";

    htmlContent += "</div></body></html>";

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html;");
    client.println("Connection: close");
    client.println();
    client.println(htmlContent);

    delay(10);
    client.stop();
    Serial.println("Client disconnected");
  }
  
  delay(2000);
}
