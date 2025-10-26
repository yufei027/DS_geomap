#pragma once
#include <vector>

#include "CGeoObject.h"
#include "CGeoPoint.h"
#include "CGeoLayer.h"
#include "CMapProj.h"
class CGeoPolyline :public CGeoObject{
public:

	int id = 0;
	int type = 0;
	int pointCount = 0;

	Node<CPoint1>* plineHead;  // ������洢���ߵ�

	void AddPoint(CPoint1* pt); // ��ӵ㵽����
	void Draw(const CMapProj* proj) override;
	void Print() override;
	void ReverseLinkedList(); // ��ת���ߵ�����
};

