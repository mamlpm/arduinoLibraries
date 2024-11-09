#include <iostream>
#include "vectorOperations.h"
#include <math.h>
using namespace std;

enum supportedColours
{
	standard = 0,
	red = 31,
	green = 32
};
void setColor(supportedColours color)
{
	cout << "\033[" << color << "m";
}
static void resetColor() { cout << "\033[0m"; }

bool testCreateVector()
{
	float xComp = 1;
	float yComp = 1;
	float module = sqrt(xComp * xComp + yComp * yComp);
	float angle = 45;
	vectorOperations testingObject(xComp, yComp, vectorOperations::CARTESIANO);
	vector<float> returnedVectorCartesian = testingObject.returnVector(vectorOperations::CARTESIANO);
	vector<float> returnedVectorPolar = testingObject.returnVector(vectorOperations::POLAR);

	if (returnedVectorCartesian[0] != xComp || returnedVectorCartesian[1] != yComp || returnedVectorPolar[0] != module || returnedVectorPolar[1] != angle)
	{
		cerr << "Crear un vector con variables cartesianas no ha funcionado";
	}
	return false;
}

int main()
{
	setColor(red);
	cout << "Hello world";
	return 0;
}