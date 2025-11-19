#pragma once
#include <string>
#include "CGeoObject.h"
#include "CMapProj.h"
#include "CViewPort.h"
class CGeoPoint : public CGeoObject {
public:

	int id = 0;
	int type = 0;
	double x = 0, y = 0;	
	char chnName[40];
	char engName[40];



	void Draw(CViewPort* view, const CMapProj* proj) override ;
	void Print() override ;
	
	CGeoPoint() = default;
	CGeoPoint(const CGeoPoint&);// 拷贝构造函数
};

