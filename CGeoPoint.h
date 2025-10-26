#pragma once
#include <string>
#include "CGeoObject.h"
class CGeoPoint : public CGeoObject {
public:

	int id = 0;
	int type = 0;
	double x = 0, y = 0;	
	char chnName[40];
	char engName[40];



	void Draw() override ;
	void Print() override ;

};

