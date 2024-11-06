#include "vectorOperations.h"
vectorOperations::vectorOperations(float x, float y, vectorsType notacion)
{
    if (notacion == POLAR)
    {
        polarVector_ = {x, y};
        cartesianVector_ = fromPolarToCartesian(polarVector_);
    }
    else
    {
        cartesianVector_ = {x, y};
        polarVector_ = fromCartesianToPolar(cartesianVector_);
    }
}

vectorOperations::vectorOperations(float x, float y, float z)
{
    cartesianVector_ = {x, y, z};
}

vector<float> vectorOperations::fromPolarToCartesian(vector<float> input)
{
    return {static_cast<float>(input[0] * cos(convertAngleRad(input[1]))),
            static_cast<float>(input[0] * sin(convertAngleRad(input[1])))};
}

vector<float> vectorOperations::fromCartesianToPolar(vector<float> input)
{
    return {static_cast<float>(static_cast<float>(sqrt(input[0] * input[0] + input[1] * input[1]))),
            convertAngleDegree(static_cast<float>(atan(input[1] / input[0])))};
}

float vectorOperations::convertAngleRad(float angle)
{
    return static_cast<float>(angle * 2 * M_PI / 360);
}

float vectorOperations::convertAngleDegree(float angle)
{
    return static_cast<float>(angle * 360 / (2 * M_PI));
}