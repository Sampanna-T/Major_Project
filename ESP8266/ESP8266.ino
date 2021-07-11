//including library for MQTT operations
#include "UbidotsESPMQTT.h"

//defining constants
#define TOKEN "BBFF-YhnxGwacekzqp59gJShmfbF0IzEGbN" 	// Your Ubidots TOKEN
#define WIFINAME "Redmi" 				// Wifi SSID
#define WIFIPASS "12345678" 				// Wifi Password
#define VIBRATION_PIN D5				// initializing pin of vibration sensor

Ubidots client(TOKEN);//creating an instance of Ubidots for publishing data


/*
 * this function is called whenever the subscribed value changes
 */
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);				// Necessary only for debugging
  client.setDebug(true); 			// debug messages enabled
  client.wifiConnection(WIFINAME, WIFIPASS);	// connect to wifi
  client.begin(callback);			// start connection establishment
  pinMode(VIBRATION_PIN,INPUT);			// initializing vibration sensor pin as input
  pinMode(LED_BUILTIN,OUTPUT);			// initializing built in LED pin as output
  }

void loop() {
  // put your main code here, to run repeatedly:
  if(!client.connected()){
      client.reconnect();
  }
  
  // Publish values to 'accident_status' variable label of device label 'esp8266'
  if(digitalRead(D5)==HIGH){
    client.add("accident_status", 1);
    client.ubidotsPublish("esp8266");
    digitalWrite(LED_BUILTIN,LOW);
    delay(10000);
    client.add("accident_status", 0);
    client.ubidotsPublish("esp8266");
  }
  digitalWrite(LED_BUILTIN,HIGH);
  client.loop();
  }