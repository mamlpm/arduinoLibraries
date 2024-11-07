#include "vectorOperations.h"
vectorOperations::vectorOperations(float x, float y, vectorsType notacion)
{
    dimension_ = 2;
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
    throw invalid_argument("As to now, this library only supports 2D vectors");
    dimension_ = 3;
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

vector<float> vectorOperations::sumarVector(vector<float> sumarVector, vectorsType returnNotation)
{
    if (sumarVector.size() != cartesianVector_.size())
    {
        throw invalid_argument("Vector dimensions must be the same");
    }
    else if (dimension_ != 2)
    {
        throw invalid_argument("As to now, this library only supports 2D vectors");
    }
    vector<float> cartesianReturnVector;
    for (int i = 0; i < sumarVector.size(); i++)
        cartesianReturnVector.push_back(sumarVector[i] + cartesianVector_[i]);
    return (returnNotation == CARTESIANO) ? cartesianReturnVector : fromCartesianToPolar(cartesianReturnVector);
}

vector<float> vectorOperations::girarNGrados(float n, vectorsType returnNotation)
{
    if (dimension_ != 2)
    {
        throw invalid_argument("As to now, this library only supports 2D vectors");
    }
    vector<vector<float>> rotationMatrix =
        {
            {static_cast<float>(cos(convertAngleRad(n))), static_cast<float>(-1 * sin(convertAngleRad(n)))},
            {static_cast<float>(sin(convertAngleRad(n))), static_cast<float>(cos(convertAngleRad(n)))}};
    
    return multiplyVector(rotationMatrix);
}

vector<float> vectorOperations::multiplyVector(vector<vector<float>> rotationMatrix)
{
    vector<float> returnVector;
    for (vector<float> i : rotationMatrix)
    {
        float result = 0;
        for (int j = 0; j < i.size(); j++)
        {
            result += (i[j] * cartesianVector_[j]);
        }
        returnVector.push_back(result);
    }
    return returnVector;
}