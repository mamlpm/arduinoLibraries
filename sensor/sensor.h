#ifndef sensor_h
#define sensor_h
#include "sensorReader.h"
class sensor: public sensorReader {
    public:
        sensor(unsigned triggerPin, unsigned echoPin, float mountAngle);
    private:
        float mountAngle_;
};
#endif