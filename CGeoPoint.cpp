#include <graphics.h>
#include <conio.h>

#include "CGeoPoint.h"


#define isTextMode  false
#define WIDTH 600
#define HEIGHT 800

#define Fx(x) (x - 72.0 ) / (136.0 -72.0 ) *  WIDTH
#define Fy(y) HEIGHT - (y - 4.0 ) / (54.0 -4.0 ) *  HEIGHT


void CGeoPoint::Draw(Node* head) //  输入的是points，一个链表
{

	initgraph(HEIGHT, WIDTH);	// 创建绘图窗口，大小为 HEIGHT x WIDTH 像素
	setcolor(RGB(255, 0, 0));

	for (int i = 0; i < points.size(); i++) {
		circle(Fx(points.x), Fy(points.y), 2);
	}

	_getch();
	closegraph();

}
