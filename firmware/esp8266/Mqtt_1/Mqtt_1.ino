#include <PubSubClient.h>
#include <WiFi.h>

// WiFi
const char* ssid = "HydroBK";                
const char* wifi_password = "Hydrolink";

// MQTT
const char* mqtt_server = "192.168.108.47"; 
const char* humidity_topic = "humidity";
const char* temperature_topic = "temperature";
const char* mqtt_username = "prabath"; // MQTT username
const char* mqtt_password = "1234"; // MQTT password
const char* clientID = "Mqtt_Test"; // MQTT client ID

// Initialise the WiFi and MQTT Client objects
WiFiClient wifiClient;

// 1883 is the listener port for the Broker
PubSubClient client(wifiClient);

// Function to connect to the MQTT broker via WiFi
void connect_MQTT(){
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Connect to the WiFi
  WiFi.begin(ssid, wifi_password);

  // Wait until the connection is confirmed
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Debugging – Output the IP Address of the ESP8266
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Connect to MQTT Broker
  if (client.connect(clientID, mqtt_username, mqtt_password)) {
    Serial.println("Connected to MQTT Broker!");
  }
  else {
    Serial.println("Connection to MQTT Broker failed...");
  }

  // client.setServer(mqtt_server,1883);
  // client.connect(clientID)
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  connect_MQTT();
  Serial.setTimeout(2000);

  // Simulated temperature and humidity readings
  float simulated_humidity = random(0, 100);
  float simulated_temperature = random(10, 40);

  Serial.print("Simulated Humidity: ");
  Serial.print(simulated_humidity);
  Serial.println(" %");
  Serial.print("Simulated Temperature: ");
  Serial.print(simulated_temperature);
  Serial.println(" *C");

  // MQTT can only transmit strings
  String hs = "Hum: " + String(simulated_humidity) + " % ";
  String ts = "Temp: " + String(simulated_temperature) + " C ";

  // PUBLISH to the MQTT Broker (topic = Temperature)
  if (client.publish(temperature_topic, String(simulated_temperature).c_str())) {
    Serial.println("Temperature sent!");
  }
  else {
    Serial.println("Temperature failed to send. Reconnecting to MQTT Broker and trying again");
    client.connect(clientID, mqtt_username, mqtt_password);
    delay(10); // This delay ensures that client.publish doesn’t clash with the client.connect call
    client.publish(temperature_topic, String(simulated_temperature).c_str());
  }

  // PUBLISH to the MQTT Broker (topic = Humidity)
  if (client.publish(humidity_topic, String(simulated_humidity).c_str())) {
    Serial.println("Humidity sent!");
  }
  else {
    Serial.println("Humidity failed to send. Reconnecting to MQTT Broker and trying again");
    client.connect(clientID, mqtt_username, mqtt_password);
    delay(10); // This delay ensures that client.publish doesn’t clash with the client.connect call
    client.publish(humidity_topic, String(simulated_humidity).c_str());
  }
  client.disconnect();  // disconnect from the MQTT broker
  delay(1000*60);       // print new values after 1 Minute
}
