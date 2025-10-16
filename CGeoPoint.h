#pragma once
#include <string>
#include "CGeoObject.h"
class CGeoPoint : public CGeoObject {
public:

	int id;
	int count;
	double x, y;	
	char chnName[40];
	char engName[40];

	void Draw();
};

