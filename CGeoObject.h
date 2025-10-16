#pragma once
class CGeoObject
{
public:
	int type;
	int count;


	virtual void Draw() = 0;       
	virtual void Print() = 0;

};

