#pragma once
#include "CMapProj.h"
class CGeoObject
{
public:
	int type;
	int count;


	virtual void Draw(const CMapProj* proj) = 0;
	virtual void Print() = 0;

};

