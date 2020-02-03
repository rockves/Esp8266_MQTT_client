#include "config.h"
#include "secrets.h"

WiFiClient espClient;
PubSubClient client(espClient);


void mqtt_connect(IPAddress mqtt_server_address, int mqtt_server_port, String mqtt_client_name, String mqtt_username, String mqtt_password){
  client.setServer(IPAddress(192, 168, 0, 3), MQTT_PORT);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect(MQTT_CLIENT_NAME, MQTT_USERNAME, MQTT_PASSWORD, "homeassistant/sensor/esp/status", 0, true, "off")) {
      client.publish("homeassistant/sensor/esp/config", "{ \"name\": \"esp\", \"state_topic\": \"homeassistant/sensor/esp/state\", \"availability_topic\": \"homeassistant/sensor/esp/status\", \"payload_available\": \"on\", \"payload_not_available\": \"off\" }");
      client.publish("homeassistant/sensor/esp/status", "on");
      Serial.println("connected"); 
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
}

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());

}

void loop() {
   client.loop();
}