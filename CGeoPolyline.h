#pragma once
#include <vector>

#include "CGeoObject.h"
#include "CGeoPoint.h"
#include "CGeoLayer.h"
class CGeoPolyline :public CGeoObject{
public:

	int id = 0;
	int type = 0;
	int pointCount = 0;

	Node* plineHead;  // 用链表存储折线点

	void AddPoint(CPoint1* pt); // 添加点到链表
	void Draw() override;
	void Print() override;
};

