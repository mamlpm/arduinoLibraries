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
    template <size_t dimcount, typename T>
    struct multidimensional_vector
    {
        typedef std::vector<typename multidimensional_vector<dimcount - 1, T>::type> type;
    };

    template <typename T>
    struct multidimensional_vector<0, T>
    {
        typedef T type;
    };
    vector<float> cartesianVector_;
    vector<float> polarVector_;
    const vector<vector<float>> rotationMatrix_;
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
    // TODO
    vector<float> girarNGrados(float n, vectorsType returnNotacion);
    vector<float> sumarVector(vector<float> sumarVector, vectorsType returnNotacion);
};
#endif