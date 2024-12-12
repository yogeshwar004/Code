const express = require('express');
const mqtt = require('mqtt');
const bodyParser = require('body-parser');
const cors = require('cors');
const path = require('path'); // For handling file paths

// MQTT Broker and Topics
const mqttBroker = 'mqtt://mqtt.platinumrobotics.com';
const mqttUser = 'mqtt_user';  // Replace with your MQTT username
const mqttPassword = '8655167646'; // Replace with your MQTT password
const mqttTopicLED = 'ctrlFreaks/LED';  // Topic for LED control
const mqttTopicTemp = 'ctrlFreaks/Sensors/Temperature'; // Topic for temperature data
const mqttTopicHum = 'ctrlFreaks/Sensors/Humidity'; // Topic for humidity data
const mqttTopicProximity = 'ctrlFreaks/Sensors/Proximity'; // Proximity topic

// Variables to store sensor data
let temperature = null;
let humidity = null;
let proximity = null;

// Create MQTT client
const client = mqtt.connect(mqttBroker, {
    username: mqttUser,
    password: mqttPassword,
});

// MQTT Event Handlers
client.on('connect', () => {
    console.log('Connected to MQTT Broker');
    // Subscribe to sensor topics
    client.subscribe([mqttTopicTemp, mqttTopicHum, mqttTopicProximity], (err) => {
        if (err) {
            console.error('Failed to subscribe to topics:', err);
        } else {
            console.log(`Subscribed to topics: ${mqttTopicTemp}, ${mqttTopicHum}, ${mqttTopicProximity}`);
        }
    });
});

client.on('error', (err) => {
    console.log('MQTT Connection Error:', err);
});

client.on('message', (topic, message) => {
    const payload = message.toString();
    console.log(`Received message: Topic = ${topic}, Payload = ${payload}`);

    // Update sensor data based on topic
    if (topic === mqttTopicTemp) {
        temperature = parseFloat(payload);
        console.log(`Temperature updated: ${temperature} °C`);
    } else if (topic === mqttTopicHum) {
        humidity = parseFloat(payload);
        console.log(`Humidity updated: ${humidity} %`);
    } else if (topic === mqttTopicProximity) {
        proximity = payload; // Update proximity status
        console.log(`Proximity updated: ${proximity}`);
    }
});

// Express App Setup
const app = express();
const port = 3000;

// Middleware
app.use(bodyParser.json());
app.use(cors());

// Serve static files (for index.html and assets)
app.use(express.static(path.join(__dirname, 'public')));

// Route to control LED
app.post('/api/led', (req, res) => {
    const command = req.body.command;
    console.log('Received LED Command:', command);

    // Publish the LED command to MQTT topic
    client.publish(mqttTopicLED, command, (err) => {
        if (err) {
            console.error('Error publishing to MQTT:', err);
            return res.status(500).json({ message: 'Error sending MQTT message' });
        }
        res.json({ message: `LED Command sent: ${command}` });
    });
});

// Route to fetch sensor data
app.get('/api/sensors', (req, res) => {
    res.json({
        temperature: temperature,
        humidity: humidity,
        proximity: proximity,
    });
});

// Start the server
app.listen(port, '0.0.0.0', () => {
    console.log(`Node.js server running on http://0.0.0.0:${port}`);
    console.log(`Access the server from other devices via: http://<your-ip>:${port}`);
});
