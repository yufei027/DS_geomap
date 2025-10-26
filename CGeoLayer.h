#pragma once
#include "CGeoObject.h"
#include "CPoint1.h"
#include "GeoLinkedList.h"
#include <vector>

class CGeoLayer
{
public:

	void ReadData(const std::string& filename);
	void Search(CPoint1 pt, double dist);
	
	void PrintLayer();
	void DrawLayer();

	void AddObject(CGeoObject* obj);


	Node* m_head = nullptr; // 头指针 第一个节点的位置

	CGeoLayer();
	~CGeoLayer();
};

