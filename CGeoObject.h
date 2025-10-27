#pragma once
#include "CMapProj.h"
#include "CViewPort.h"
class CGeoObject
{
public:
	int type;
	int count;

	// ��Ϊ�Ҳ����޸Ķ���״̬�����Զ�CMapProj��const�������һ��޸�CViewPort�Ķ���״̬�����������xminymin
	virtual void Draw(CViewPort* view, const CMapProj* proj) = 0; 
	virtual void Print() = 0;

};

