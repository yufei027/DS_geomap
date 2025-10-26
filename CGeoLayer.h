#pragma once
#include "CGeoObject.h"
#include "CPoint1.h"
#include "GeoLinkedList.h"
#include <vector>
#include "CMapProj.h"
class CGeoLayer
{
public:

	void ReadData(const std::string& filename);
	void Search(CPoint1 pt, double dist);
	
	void PrintLayer();
	void DrawLayer(const CMapProj* proj);

	void AddObject(CGeoObject* obj);

	void ReverseLinkedList(); // ��ת����
	Node<CGeoObject>* m_head = nullptr; // ͷָ�� ��һ���ڵ��λ��

	CGeoLayer();
	~CGeoLayer();
};

