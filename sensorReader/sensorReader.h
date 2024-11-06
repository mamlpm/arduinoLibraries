#ifndef sensorReader_h
#define sensorReader_h
#include "Arduino.h"
class sensorReader
{
public:
    sensorReader(unsigned triggerPin, unsigned echoPin);
    unsigned int returnDuracionVueloMs();
    float returnDistanciaCm();
    void computeDistance();
private:
    unsigned int triggerPin_;
    unsigned int echoPin_;
    unsigned int duracionVueloMs_;
    float distanciaCm_;
    void writteNMilisecondsDigital(unsigned miliseconds, unsigned pin, bool setValue);
    void checkAndUpdateFlightTime();
    void calcularDistanciaCm();
    void triggerSensor();    
};
#endif