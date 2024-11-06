#ifndef vectorOperations_h
#define vectorOperations_h
#define _USE_MATH_DEFINES
#include <vector>
#include <math.h>
using namespace std;
class vectorOperations
{
private:
    enum vectorsType {
        CARTESIANO,
        POLAR,
    };
    vector<float> cartesianVector_;
    vector<float> polarVector_;
    int dimension_;
    float returnAngleRad();

public:
    vectorOperations(float x, float y, vectorsType notacion);
    vectorOperations(float x, float y, float z);
    //TODO
    vector<float> girarNGrados(float n, vectorsType returnNotacion);
    //TODO
    vector<float> sumarVector(float n, vectorsType returnNotacion);
};
#endif