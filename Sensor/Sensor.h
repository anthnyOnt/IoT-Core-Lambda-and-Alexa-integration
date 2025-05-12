#ifndef SENSOR_H
#define SENSOR_H
#define DELAY_TIME 500
#include <ArduinoJson.h>

class Sensor
{
private:
    byte pin;
    int lightValue;
    String sensorState;
    int threshold;

public:
    Sensor(const byte &pin)
        : pin(pin), sensorState("CLEAR"), lightValue(0), threshold(100)
    {
    }

    int getLightValue(){ return this->lightValue; }
    void readLightValue(){ this->lightValue = analogRead(pin); }
    
    String getSensorState(){ return this->sensorState; }
    void setSensorState(const String &sensorState) { this->sensorState = sensorState; }

    int getThreshold(){ return this->threshold; }
    void setThreshold(const int &threshold ){ this->threshold = threshold; }

    String classifyState(const int &lightValue){ return (lightValue < this->threshold) ? "BLOCKED" : "CLEAR";}
    
    bool stateHasChanged(const String &newState){ return (this->sensorState != newState); }


};

#endif