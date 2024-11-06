#include "vectorOperations.h"
vectorOperations::vectorOperations(float x, float y, vectorsType notacion)
{
    if (notacion == POLAR)
    {
        polarVector_ = {x, y};
        cartesianVector_ = {static_cast<float>(x * cos(returnAngleRad())),
                            static_cast<float>(x * sin(returnAngleRad()))};
    }
    else
    {
        cartesianVector_ = {x, y};
        polarVector_ = {static_cast<float>(sqrt(x * x + y * y)),
                        static_cast<float>((atan(y / x) * 360) / (2 * M_PI))};
    }
}

vectorOperations::vectorOperations(float x, float y, float z)
{
    cartesianVector_ = {x, y, z};
}

float vectorOperations::returnAngleRad()
{
    return static_cast<float>(polarVector_[1] * 2 * M_PI / 360);
}