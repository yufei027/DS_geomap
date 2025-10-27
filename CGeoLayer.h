#pragma once
#include "CGeoObject.h"
#include "CPoint1.h"
#include "GeoLinkedList.h"
#include <vector>
#include "CMapProj.h"
#include "CViewPort.h"
class CGeoLayer
{
public:
	CViewPort viewport; // 存储整个图层的范围

	void ReadData(const std::string& filename);
	void Search(CPoint1 pt, double dist);
	
	void PrintLayer();
	void DrawLayer(CViewPort* view, const CMapProj* proj);

	void AddObject(CGeoObject* obj);

	void ReverseLinkedList(); // 反转链表
	Node<CGeoObject>* m_head = nullptr; // 头指针 第一个节点的位置

	CGeoLayer();
	~CGeoLayer();
};

