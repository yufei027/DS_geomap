#pragma once
#include "CMapProj.h"
#include "CViewPort.h"
class CGeoObject
{
public:
	int type = 0;
	int count = 0;

	int id = 0;
	CGeoObject* leftChild = nullptr;   // 左子节点
	CGeoObject* rightChild = nullptr;  // 右子节点

	virtual void Draw(CViewPort* view, const CMapProj* proj) = 0; 
	virtual void Print() = 0;

};

