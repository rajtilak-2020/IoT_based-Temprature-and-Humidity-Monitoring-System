#define BLYNK_TEMPLATE_ID "TMPL3HsBJMZM7"
#define BLYNK_TEMPLATE_NAME "DHT Project"
#define BLYNK_AUTH_TOKEN "dL56ieMTL0-YmCuGFXFva0RYXJqH8xkh"

#include "DHT.h"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_Sensor.h>

char auth[] = BLYNK_AUTH_TOKEN;

#define DPIN 32             //Pin of DHT sensor (GPIO number)
#define DTYPE DHT11         // DHT 11 sensor type

DHT dht(DPIN,DTYPE);

char ssid[] = "Desktop";    //WiFi SSID
char pass[] = "78480201";   //WiFi password
                            //wifi band should be set to 2.4ghz for a successful connection with ESP32 Board.
void setup()
 {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin(); 
}

void loop() 

{
  delay(2800);
  Blynk.run();
  
  float tc = dht.readTemperature(false);  //Read temperature in C
  float tf = dht.readTemperature(true);   //Read Temperature in F
  float hu = dht.readHumidity(true);      //Read Humidity in percentage

  Serial.print("Temp: ");
  Serial.print(tc);
  Serial.print(" C, ");
  Serial.print(tf);
  Serial.print(" Hum:, % ");
  Serial.print(hu);
  Serial.println("%");
  Serial.print("RZero: ");
 
  Blynk.virtualWrite(V0, tc);     // Virtual pin V0 for temperature
  Blynk.virtualWrite(V1, tf);     // Virtual pin V1 for humidity
  
  delay(1500);
}