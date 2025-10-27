#pragma once
#include "CMapProj.h"
#include "CViewPort.h"
class CGeoObject
{
public:
	int type;
	int count;

	// 因为我不会修改对象状态，所以对CMapProj用const，但是我会修改CViewPort的对象状态，例如里面的xminymin
	virtual void Draw(CViewPort* view, const CMapProj* proj) = 0; 
	virtual void Print() = 0;

};

