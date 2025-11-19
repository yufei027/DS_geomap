
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

	Node<CGeoObject>* m_head = nullptr; // 链表头指针

	CGeoObject* m_btreeRoot = nullptr; // 二叉树根节点

	// 数组
	std::vector<CGeoPoint*> points;
	// 栈和队列定义，栈和队列的存取

	void ReadData(const std::string& filename);

	void ReadDataBtree(const std::string& filename);

	void Search(CPoint1 pt, double dist);
	
	void PrintLayer();

	void DrawLayer(CViewPort* view, const CMapProj* proj);

	void AddObject(CGeoObject* obj); // 在链表中添加

	void AddBtreeObject(CGeoObject** rt, CGeoObject* obj); // 在二叉树中添加

	void LDR_Order(CGeoObject* rt);
	void DLR_Order(CGeoObject* rt);
	void LRD_Order(CGeoObject* rt);
	void LevelOrder(CGeoObject* root);
	int getBTreeHeight(CGeoObject* rt);
	void ReverseLinkedList(); // 反转链表

	void SortList(std::string& type, std::vector<CGeoPoint*>& points);
	void SwapPoints(CGeoPoint* pt1, CGeoPoint* pt2);
	void SearchList(std::string& type, const std::vector<CGeoPoint*>& points, double target);

	CGeoLayer();
	~CGeoLayer();
};

