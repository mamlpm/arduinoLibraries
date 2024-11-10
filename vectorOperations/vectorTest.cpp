#include <iostream>
#include "vectorOperations.h"
#include <math.h>
#include "../mUTcPP/mUTcPP.h"
using namespace std;

float xComp = 1;
float yComp = 1;
float module = sqrt(xComp * xComp + yComp * yComp);
float angle = 45;

vector<float> testingCartesianConstructorCartesianOutput()
{
	vectorOperations testingObject(xComp, yComp, vectorOperations::CARTESIANO);
	return testingObject.returnVector(vectorOperations::CARTESIANO);
}

vector<float> testingCartesianConstructorPolarOutput()
{
	vectorOperations testingObject(xComp, yComp, vectorOperations::CARTESIANO);
	return testingObject.returnVector(vectorOperations::POLAR);
}

vector<float> testingPolarConstructorCartesianOutput()
{
	vectorOperations testingObject(module, angle, vectorOperations::POLAR);
	vector<float> cartesianOutput = testingObject.returnVector(vectorOperations::CARTESIANO);
	return testingObject.returnVector(vectorOperations::CARTESIANO);
}

vector<float> testingPolarConstructorPolarOutput()
{
	vectorOperations testingObject(module, angle, vectorOperations::POLAR);
	return testingObject.returnVector(vectorOperations::POLAR);
}

vector<float> testingCartesianConstructorCartesianOutputVectorInput()
{
	vectorOperations testingObject({xComp, yComp}, vectorOperations::CARTESIANO);
	return testingObject.returnVector(vectorOperations::CARTESIANO);
}

vector<float> testingCartesianConstructorPolarOutputVectorInput()
{
	vectorOperations testingObject({xComp, yComp}, vectorOperations::CARTESIANO);
	return testingObject.returnVector(vectorOperations::POLAR);
}

vector<float> testingPolarConstructorCartesianOutputVectorInput()
{
	vectorOperations testingObject({module, angle}, vectorOperations::POLAR);
	return testingObject.returnVector(vectorOperations::CARTESIANO);
}

vector<float> testingPolarConstructorPolarOutputVectorInput()
{
	vectorOperations testingObject({module, angle}, vectorOperations::POLAR);
	return testingObject.returnVector(vectorOperations::POLAR);
}

int main()
{
	vector<mUTcPP<vector<float>>::inputData> floatVectorData = {
		{testingCartesianConstructorCartesianOutput,
		 "testingCartesianConstructorCartesianOutput",
		 {"float", "float", "CARTESIANO"},
		 {xComp, yComp}},
		{testingCartesianConstructorCartesianOutput,
		 "testingCartesianConstructorCartesianOutput",
		 {"float", "float", "CARTESIANO"},
		 {2, 2},
		 true},
		{testingCartesianConstructorPolarOutput,
		 "testingCartesianConstructorPolarOutput",
		 {"float", "float", "CARTESIANO"},
		 {module, angle}},
		{testingCartesianConstructorPolarOutput,
		 "testingCartesianConstructorPolarOutput",
		 {"float", "float", "CARTESIANO"},
		 {module + 1, angle + 1},
		 true},
		{testingPolarConstructorCartesianOutput,
		 "testingPolarConstructorCartesianOutput",
		 {"float", "float", "POLAR"},
		 {xComp, yComp}},
		{testingPolarConstructorCartesianOutput,
		 "testingPolarConstructorCartesianOutput",
		 {"float", "float", "POLAR"},
		 {xComp + 1, yComp + 1},
		 true},
		{
			testingPolarConstructorPolarOutput,
			"testingPolarConstructorPolarOutput",
			{"float", "float", "POLAR"},
			{module, angle},
		},
		{
			testingPolarConstructorPolarOutput,
			"testingPolarConstructorPolarOutput",
			{"float", "float", "POLAR"},
			{module + 1, angle + 1},
			true,
		},
		{testingCartesianConstructorCartesianOutputVectorInput,
		 "testingCartesianConstructorCartesianOutputVectorInput",
		 {"float", "float", "CARTESIANO"},
		 {xComp, yComp}},
		{testingCartesianConstructorCartesianOutputVectorInput,
		 "testingCartesianConstructorCartesianOutputVectorInput",
		 {"float", "float", "CARTESIANO"},
		 {xComp + 1, yComp + 1},
		 true},
		{testingCartesianConstructorPolarOutputVectorInput,
		 "testingCartesianConstructorPolarOutputVectorInput",
		 {"float", "float", "POLAR"},
		 {module, angle}},
		{testingCartesianConstructorPolarOutputVectorInput,
		 "testingCartesianConstructorPolarOutputVectorInput",
		 {"float", "float", "POLAR"},
		 {module + 1, angle + 1},
		 true},
		{testingPolarConstructorCartesianOutputVectorInput,
		 "testingCartesianConstructorPolarOutputVectorInput",
		 {"float", "float", "POLAR"},
		 {xComp, yComp}},
		{testingPolarConstructorCartesianOutputVectorInput,
		 "testingCartesianConstructorPolarOutputVectorInput",
		 {"float", "float", "POLAR"},
		 {xComp + 1, yComp + 1},
		 true},
		{testingPolarConstructorPolarOutputVectorInput,
		 "testingPolarConstructorPolarOutputVectorInput",
		 {"float", "float", "POLAR"},
		 {module, angle}},
		{testingPolarConstructorPolarOutputVectorInput,
		 "testingPolarConstructorPolarOutputVectorInput",
		 {"float", "float", "POLAR"},
		 {module + 1, angle + 1},
		 true},
	};
	//TODO
	vector<mUTcPP<vectorOperations>::inputData> vectorOperationsData = {};
	mUTcPP<vector<float>> testingVectorOperationsMethodsReturningVectorFloat(floatVectorData);
	testingVectorOperationsMethodsReturningVectorFloat.runAllFunctions();
	mUTcPP<vectorOperations> testingVectorOperationsMEthodsReturnVectorOperationObject(vectorOperationsData);
	testingVectorOperationsMEthodsReturnVectorOperationObject.runAllFunctions();
	return 0;
}