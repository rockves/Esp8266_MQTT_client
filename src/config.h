#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define MQTT_CLIENT_NAME "ESP "
#define MQTT_TOPIC "esp"

#define AP_SSID "Esp"      //Nazwa punktu dostępu do konfiguracji ustawień wifi
#define AP_PASSWORD "esp123456" //Hasło do punktu dostępu (musi rozpoczynać się od litery i mieć długość 8)
#define AP_IP_OCTET_1 192       //Pierwszy oktet adresu IP
#define AP_IP_OCTET_2 168       //Drugi oktet adresu IP
#define AP_IP_OCTET_3 0         //Trzeci oktet adresu IP
#define AP_IP_OCTET_4 1         //Czwarty oktet adresu IP
#define AP_GATEWAY_OCTET_1 0    //Pierwszy oktet adresu bramy
#define AP_GATEWAY_OCTET_2 0    //Drugi oktet adresu bramy
#define AP_GATEWAY_OCTET_3 0    //Trzeci oktet adresu bramy
#define AP_GATEWAY_OCTET_4 0    //Czwarty oktet adresu bramy
#define AP_SUBNET_OCTET_1 255   //Pierwszy oktet adresu podsieci
#define AP_SUBNET_OCTET_2 255   //Drugi oktet adresu podsieci
#define AP_SUBNET_OCTET_3 255   //Trzeci oktet adresu podsieci
#define AP_SUBNET_OCTET_4 0     //Czwarty oktet adresu podsieci