#include "Arduino.h"
#include "sensorReader.h"

sensorReader::sensorReader(unsigned triggerPin, unsigned echoPin)
{
    triggerPin_ = triggerPin;
    echoPin_ = echoPin;
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}
void sensorReader::triggerSensor()
{
    writteNMilisecondsDigital(4, triggerPin_, 0);
    writteNMilisecondsDigital(10, triggerPin_, 1);
}
void sensorReader::writteNMilisecondsDigital(unsigned miliseconds, unsigned pin, bool setValue)
{
    digitalWrite(pin, setValue);
    delayMicroseconds(miliseconds);
}

void sensorReader::checkAndUpdateFlightTime()
{
    duracionVueloMs_ = pulseIn(echoPin_, HIGH);
}

void sensorReader::calcularDistanciaCm()
{
    checkAndUpdateFlightTime();
    distanciaCm_ = 343.2 * 100 * pow(10, -6) * duracionVueloMs_ / 2;
}
void sensorReader::computeDistance()
{
    triggerSensor();
    calcularDistanciaCm();
}

unsigned int sensorReader::returnDuracionVueloMs()
{
    return duracionVueloMs_;
}

float sensorReader::returnDistanciaCm()
{
    return distanciaCm_;
}