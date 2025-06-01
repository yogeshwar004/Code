const express = require('express');
const mqtt = require('mqtt');
const bodyParser = require('body-parser');
const cors = require('cors');
const path = require('path');

// MQTT Broker and Topics
const mqttBroker = 'mqtt://mqtt.platinumrobotics.com';
const mqttUser = 'mqtt_user';            // Replace with your MQTT username
const mqttPassword = '8655167646';       // Replace with your MQTT password

const mqttTopicLED = 'ctrlFreaks/LED';                   // Topic for LED control
const mqttTopicTemp = 'ctrl/Sensor/Temperature';         // Topic for temperature
const mqttTopicHum = 'ctrl/Sensor/Humidity';             // Topic for humidity
const mqttTopicProximity = 'ctrlFreaks/Sensors/Proximity'; // Proximity topic

// Variables to hold sensor values
let temperature = null;
let humidity = null;
let proximity = null;

// Create MQTT client
const mqttClient = mqtt.connect(mqttBroker, {
    username: mqttUser,
    password: mqttPassword
});

// MQTT Connection
mqttClient.on('connect', () => {
    console.log('✅ Connected to MQTT Broker');

    mqttClient.subscribe([mqttTopicTemp, mqttTopicHum, mqttTopicProximity], (err) => {
        if (err) {
            console.error('❌ Failed to subscribe to topics:', err);
        } else {
            console.log('📡 Subscribed to sensor topics');
        }
    });
});

mqttClient.on('error', (err) => {
    console.error('❌ MQTT connection error:', err);
});

// Handle incoming MQTT messages
mqttClient.on('message', (topic, message) => {
    const payload = message.toString();
    console.log(`📥 MQTT message - Topic: ${topic}, Message: ${payload}`);

    if (topic === mqttTopicTemp) {
        temperature = parseFloat(payload);
    } else if (topic === mqttTopicHum) {
        humidity = parseFloat(payload);
    } else if (topic === mqttTopicProximity) {
        proximity = payload;
    }
});

// Express setup
const app = express();
const PORT = 3000;

// Middleware
app.use(bodyParser.json());
app.use(cors());

// Serve static files (like HTML/CSS/JS)
app.use(express.static(path.join(__dirname, 'public')));

// API to control LEDs
app.post('/api/led', (req, res) => {
    const command = req.body.command;
    console.log(`🔧 LED Control Command: ${command}`);

    mqttClient.publish(mqttTopicLED, command, (err) => {
        if (err) {
            console.error('❌ Error publishing LED command:', err);
            return res.status(500).json({ message: 'Failed to send LED command' });
        }
        res.json({ message: `✅ LED command sent: ${command}` });
    });
});

// API to get sensor data
app.get('/api/sensors', (req, res) => {
    res.json({
        temperature: temperature ?? 'N/A',
        humidity: humidity ?? 'N/A',
        proximity: proximity ?? 'N/A'
    });
});

const os = require('os');

function getLocalIP() {
  const interfaces = os.networkInterfaces();
  for (const name of Object.keys(interfaces)) {
    for (const iface of interfaces[name]) {
      if (iface.family === 'IPv4' && !iface.internal) {
        return iface.address;
      }
    }
  }
  return '0.0.0.0';
}

//const ip=get
console.log('Local IP Address:http://'+ getLocalIP());

// Start the server
app.listen(PORT, '0.0.0.0', () => {
    console.log(`🚀 Server is running at http://0.0.0.0:${PORT}`);
});
