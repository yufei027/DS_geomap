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

	Node* plineHead;  // ������洢���ߵ�

	void AddPoint(CPoint1* pt); // ��ӵ㵽����
	void Draw() override;
	void Print() override;
};

