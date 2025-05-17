#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "tsaleh-TIME2.4Ghz_EXT";   // Your Network SSID
const char* password = "Tanisha2004";       // Your Network Password

int val;
int pin = A0; // LM35 Pin Connected at A0 Pin

WiFiClient client;

unsigned long myChannelNumber = 2944159; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "K65JEFBATV41E4CV"; //Your Write API Key

void setup()
{
  Serial.begin(9600);
  delay(10);
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}

void loop()
{
  val = analogRead(pin); // Read Analog values and Store in val variable
  Serial.print("Temperature: ");
  Serial.print(val);                 // Print on Serial Monitor
  Serial.println("*C");
  delay(1000);
  ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
}