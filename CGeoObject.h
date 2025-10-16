#pragma once
class CGeoObject
{
public:
	int type;
	int count;

	virtual void ReadObject(); 
	virtual void Output();

	virtual void Draw() = 0;       // 所有子类都能绘制

};

