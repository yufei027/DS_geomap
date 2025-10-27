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
	CViewPort viewport; // �洢����ͼ��ķ�Χ

	void ReadData(const std::string& filename);
	void Search(CPoint1 pt, double dist);
	
	void PrintLayer();
	void DrawLayer(CViewPort* view, const CMapProj* proj);

	void AddObject(CGeoObject* obj);

	void ReverseLinkedList(); // ��ת����
	Node<CGeoObject>* m_head = nullptr; // ͷָ�� ��һ���ڵ��λ��

	CGeoLayer();
	~CGeoLayer();
};

