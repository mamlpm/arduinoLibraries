#ifndef vectorOperations_h
#define vectorOperations_h
#define _USE_MATH_DEFINES
#include <vector>
#include <math.h>
#include <stdexcept>
using namespace std;
class vectorOperations
{
private:
    vector<float> cartesianVector_;
    vector<float> polarVector_;
    int dimension_;
    float convertAngleRad(float angle);
    float convertAngleDegree(float angle);
    vector<float> fromPolarToCartesian(vector<float> input);
    vector<float> fromCartesianToPolar(vector<float> input);

public:
    enum vectorsType
    {
        CARTESIANO,
        POLAR,
    };
    vectorOperations(float x, float y, vectorsType notacion);
    vectorOperations(float x, float y, float z);
    vectorOperations(vector<float> input, vectorsType notacion);
    vectorOperations multiplyVector(vector<vector<float>> rotationMatrix);
    vectorOperations girarNGrados(float n);
    vectorOperations sumarVector(vectorOperations sumarVector);
    vector<float> returnVector(vectorsType formatToReturn);
};
#endif