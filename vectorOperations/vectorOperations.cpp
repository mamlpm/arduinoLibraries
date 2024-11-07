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

vectorOperations::vectorOperations(vector<float> input, vectorsType notacion)
{
    polarVector_ = (notacion == POLAR) ? input : fromCartesianToPolar(input);
    cartesianVector_ = (notacion == POLAR) ? fromPolarToCartesian(input) : input;
    dimension_ = cartesianVector_.size();
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

vector<float> vectorOperations::returnVector(vectorsType formatToReturn)
{
    return formatToReturn == CARTESIANO ? cartesianVector_ : polarVector_;
}

vectorOperations vectorOperations::sumarVector(vectorOperations sumarVector)
{
    if (sumarVector.returnVector(CARTESIANO).size() != cartesianVector_.size())
    {
        throw invalid_argument("Vector dimensions must be the same");
    }
    else if (dimension_ != 2)
    {
        throw invalid_argument("As to now, this library only supports 2D vectors");
    }
    vector<float> cartesianReturnVector;
    for (int i = 0; i < sumarVector.returnVector(CARTESIANO).size(); i++)
        cartesianReturnVector.push_back(sumarVector.returnVector(CARTESIANO)[i] + cartesianVector_[i]);
    vectorOperations returnVector(cartesianReturnVector, CARTESIANO);
    return returnVector;
}

vectorOperations vectorOperations::girarNGrados(float n)
{
    if (dimension_ != 2)
    {
        throw invalid_argument("As to now, this library only supports 2D vectors");
    }
    vectorOperations rotatedPolarVector({polarVector_[0], polarVector_[1] + n}, POLAR);
    return rotatedPolarVector;
}

vectorOperations vectorOperations::multiplyVector(vector<vector<float>> multiplyMatrix)
{
    vector<float> returnCartesianVector;
    for (vector<float> i : multiplyMatrix)
    {
        float result = 0;
        for (int j = 0; j < i.size(); j++)
        {
            result += (i[j] * cartesianVector_[j]);
        }
        returnCartesianVector.push_back(result);
    }
    vectorOperations returnVector(returnCartesianVector, CARTESIANO);
    return returnVector;
}