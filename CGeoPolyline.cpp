#include <graphics.h>
#include <iostream>

#include "CGeoPolyline.h"

#define WIDTH 600
#define HEIGHT 800

#define Fx(x) (x - 72.0 ) / (136.0 -72.0 ) *  WIDTH
#define Fy(y) HEIGHT - (y - 4.0 ) / (54.0 -4.0 ) *  HEIGHT



void CGeoPolyline::Draw()
{
	moveto(Fx(points[0].x), Fy(points[0].y));

    for (int i = 1; i < points.size(); ++i) {
        lineto(Fx(points[i].x), Fy(points[i].y));
    }
}

void CGeoPolyline::Print()
{
    std::cout << "Polyline: ";
    for (auto& p : points)
        //std::cout << "(" << p.x << "," << p.y << ") ";
    std::cout << std::endl;
}
