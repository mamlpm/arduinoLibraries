#ifndef vectorOperations_h
#define vectorOperations_h
#define _USE_MATH_DEFINES
#include <vector>
#include <math.h>
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
    enum vectorsType
    {
        CARTESIANO,
        POLAR,
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
    vectorOperations(float x, float y, vectorsType notacion);
    vectorOperations(float x, float y, float z);
    // TODO
    vector<float> girarNGrados(float n, vectorsType returnNotacion);
    // TODO
    vector<float> sumarVector(float n, vectorsType returnNotacion);
};
#endif