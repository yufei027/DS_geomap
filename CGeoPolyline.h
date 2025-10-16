#pragma once
#include <vector>

#include "CGeoObject.h"
#include "CGeoPoint.h"
class CGeoPolyline :public CGeoObject{
public:

	int id;
	int type;
	std::vector<CGeoPoint> points; // �洢���ߵ�


	void Draw() override;
	void Print() override;
};

