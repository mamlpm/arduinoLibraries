#include "sensor.h"

sensor::sensor(unsigned triggerPin, unsigned echoPin, float mountAngle) : sensorReader(triggerPin, echoPin)
{
    mountAngle_ = mountAngle;
}