#include "../config.h"
#include "../SmartParking/SmartParking.h"

SmartParking* smartParking;

void setup()
{
  Serial.begin(115200);
  delay(100); 
  smartParking = new SmartParking(SSID, password, clientId, broker, port, actuatorPin, sensorPin, updateTopic, deltaTopic);
  smartParking->init();
}

void loop()
{
  smartParking->loop();
}