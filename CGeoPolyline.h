#pragma once
#include <vector>

#include "CGeoObject.h"
#include "CGeoPoint.h"
#include "CGeoLayer.h"
#include "CMapProj.h"
#include "CViewPort.h"
class CGeoPolyline :public CGeoObject{
public:

	int id = 0;
	int type = 0;
	int pointCount = 0;

	Node<CPoint1>* plineHead = nullptr;  // 用链表存储折线点

	void AddPoint(CPoint1* pt); // 添加点到链表

	void Draw(CViewPort* view, const CMapProj* proj) override;
	void Print() override;

	void ReverseLinkedList(); // 反转折线点链表
};

