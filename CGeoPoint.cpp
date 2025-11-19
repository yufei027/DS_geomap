#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>
#include "CGeoPoint.h"
#include "CMapProj.h"
#include "CViewPort.h"

using namespace std;



void CGeoPoint::Draw(CViewPort* view, const CMapProj* proj){
	
	//assert(view != nullptr && "view 为空！");assert(proj != nullptr && "proj 为空！");

	CPoint1 p = proj->Project(x, y);
	circle(view->Fx(p.x), view->Fy(p.y), 2); // 用view里面的FxFy而不是写在开头

}

void CGeoPoint::Print() {
	std::cout 
		<< "Point	Id=" << id
		<< "	x=" << x
		<< "	y=" << y
		<< "	name=" << chnName 
		<< std::endl;
}

CGeoPoint::CGeoPoint(const CGeoPoint& p) // 拷贝构造函数的参数必须是 const 引用
{
	
	id = p.id;
	type = p.type;
	x = p.x;
	y = p.y;

	
	strcpy_s(chnName, sizeof(chnName), p.chnName);
	strcpy_s(engName, sizeof(engName), p.engName);

}
