#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "CGeoPoint.h"
#include "CMapProj.h"
#include "CViewPort.h"
using namespace std;



void CGeoPoint::Draw(CViewPort* view, const CMapProj* proj){
	//circle(Fx(x), Fy(y), 2);
	CPoint1 p = proj->Project(x, y);
	circle(view->Fx(p.x), view->Fy(p.y), 2);

}

void CGeoPoint::Print() {
	std::cout 
		<< "Point	Id=" << id
		<< "	x=" << x
		<< "	y=" << y
		<< "	name=" << chnName 
		<< std::endl;
}