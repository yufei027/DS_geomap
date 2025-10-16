#pragma once
#include <string>
#include "CGeoObject.h"
class CGeoPoint : public CGeoObject {
public:

	int id;
	int type;
	double x, y;	
	char chnName[40];
	char engName[40];



	void Draw() override ;
	void Print() override ;

	// CGeoPoint(double xVal, double yVal): x(xVal), y(yVal) {}
};

