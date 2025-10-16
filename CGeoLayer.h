#pragma once
#include "CGeoObject.h"
#include "CGeoPoint.h"

#include "CPoint1.h"
#include <vector>

class CGeoLayer
{
public:

	std::vector<CGeoPoint> points; 
	// CGeoPoint* pts = new CGeoPoint[350];

	int count;


	void ReadData();
	void Search(CPoint1 pt, double dist);
	void Output();

	void DrawLayer();
	void AddObject(CGeoObject* obj);


	struct Node {
		CGeoObject* data; // 指向object对象
		Node* next;		  // 指向下一个节点
		Node(CGeoObject* d) : data(d), next(nullptr) {}
	};
	Node* m_head = nullptr; // 头指针 第一个节点的位置
};

