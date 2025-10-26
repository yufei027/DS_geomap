#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "CGeoPoint.h"
#include "CMapProj.h"
using namespace std;


#define WIDTH 600
#define HEIGHT 800

#define Fx(x) (x - 72.0 ) / (136.0 -72.0 ) *  WIDTH
#define Fy(y) HEIGHT - (y - 4.0 ) / (54.0 -4.0 ) *  HEIGHT




void CGeoPoint::Draw(const CMapProj* proj){
	//circle(Fx(x), Fy(y), 2);
	CPoint1 p = proj->Project(x, y);
	circle(Fx(p.x), Fy(p.y), 2);

}

void CGeoPoint::Print() {
	std::cout 
		<< "Point	Id=" << id
		<< "	x=" << x
		<< "	y=" << y
		<< "	name=" << chnName 
		<< std::endl;
}