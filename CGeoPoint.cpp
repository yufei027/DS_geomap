#include <graphics.h>
#include <conio.h>

#include "CGeoPoint.h"


#define isTextMode  false
#define WIDTH 600
#define HEIGHT 800

#define Fx(x) (x - 72.0 ) / (136.0 -72.0 ) *  WIDTH
#define Fy(y) HEIGHT - (y - 4.0 ) / (54.0 -4.0 ) *  HEIGHT


void CGeoPoint::Draw(Node* head) //  �������points��һ������
{

	initgraph(HEIGHT, WIDTH);	// ������ͼ���ڣ���СΪ HEIGHT x WIDTH ����
	setcolor(RGB(255, 0, 0));

	for (int i = 0; i < points.size(); i++) {
		circle(Fx(points.x), Fy(points.y), 2);
	}

	_getch();
	closegraph();

}
