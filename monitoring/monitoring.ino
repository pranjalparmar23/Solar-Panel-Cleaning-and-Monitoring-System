#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ThingSpeak.h>
#include <Wire.h>
#include <WiFiClient.h>

// DHT Sensor
#define DHTTYPE DHT11  // DHT 11
#define DHTPIN D5 // Use digital pin D5 for the DHT sensor
DHT_Unified dht(DHTPIN, DHTTYPE);


// Current Sensor
const int analogInputPin = A0; // ACS712 sensor
float sensitivity = 100.0;     // For ACS712-05B, it's typically 100 mV/A

//Dust Sensor
const int dustSensorPin = A0;  // Digital pin for the dust sensor
float dustValue = 0.0; // Variable to store the dust sensor reading

// LDR Sensor
const int ldrPin = D7; // Use digital pin D7 for the LDR sensor

const char* ssid = "vivo 1818";  // Replace with your WiFi SSID
const char* password = "dhwani1234";  // Replace with your WiFi password
const String apiKey = "KB0ANVI8H4UCXSBK";  // Replace with your ThingSpeak API Key
const String channelID = "2300020";  // Replace with your ThingSpeak Channel ID
const char* server = "api.thingspeak.com";
WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();
  connectToWiFi();
}


void loop() {
  // Read dust sensor data
  int dustSensorValue = analogRead(dustSensorPin); // Read an analog value from D2
  String dustValue = String(map(dustSensorValue, 0, 1023, 0, 100));// Map the analog reading to your dust concentration range
  Serial.print("Dust: ");
  Serial.println(dustValue);

  //Read temperature and humidity from DHT11 sensor
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  Serial.print(F("Temperature: "));
  Serial.print(event.temperature);
  Serial.println(F("°C"));
  dht.humidity().getEvent(&event);
  Serial.print(F("Humidity: "));
  Serial.print(event.relative_humidity);
  Serial.println(F("%"));
  


  // Read current from ACS712 sensor
  int sensorValue = analogRead(analogInputPin);
  float voltage = (sensorValue / 1023.0) * 5000.0; // 5V reference voltage
  String current = String((voltage - 2500) / sensitivity); // 2500 mV is the sensor's zero current output
  Serial.print("Current (A): ");
  Serial.println(current); // Display with 2 decimal places


  // Read LDR sensor value
  String ldrValue = String(analogRead(ldrPin));
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  String temperature=String(event.temperature);
  String Humidity=String(event.relative_humidity);

  String url="/update?api_key="+apiKey+"&field1=" +temperature+ "&field2=" +Humidity+"&field3="+current+"&field4="+ldrValue+"&field5="+dustValue;

  Serial.print(url);
  if (client.connect(server, 80)) {
  // Rest of the code for sending data to ThingSpeak...
  client.print("POST" + url + " HTTP/1.1\n");
  client.print("Host: "+String(server)+ "\n");
  client.print("Connection: close\n");
  //client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
  //client.print("Content-Type: application/x-www-form-urlencoded\n");
  //client.print("Content-Length: ");
  //client.print(data.length());
  Serial.println("Data sent to ThingSpeak");
  }else {
  Serial.println("Connection to ThingSpeak failed");
}
 client.stop();


  delay(500);
} 


void connectToWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("connected");
    break;
  }
  Serial.println();
  Serial.println("Connected to Wi-Fi (test2)");
}
