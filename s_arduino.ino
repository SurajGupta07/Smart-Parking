#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

SoftwareSerial Arduino(5, 4, false, 256); // (RX - D1, TX - D2)

const char* ssid = "SHARAN";
const char* password = "22222222";
const char* subtopic = "inTopic";
const char* pubtopic = "out";
const char* mqtt_user = "ltehsyix";
const char* mqtt_pass = "IxB91cuGMkBD";
int mqtt_port = 18094;

const char* mqtt_server = "m12.cloudmqtt.com";


WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
char empty_spots[1];

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(9600);
  Arduino.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
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

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client", mqtt_user, mqtt_pass)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish(pubtopic, "Connected!");
      // ... and resubscribe
      client.subscribe(subtopic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
    if(Arduino.available())
      //empty_spots[0] = Arduino.read();

    //snprintf (msg, 10, "%.2f", t);
    Serial.print("Publish message:");
    Serial.println(Arduino.read());
    client.publish(pubtopic, empty_spots);

    delay(5000);
}


