#include <graphics.h>
#include <iostream>
#include <iomanip>

#include "CGeoPolyline.h"
#include "CGeoObject.h"
#include "CGeoLayer.h"
#include "GeoLinkedList.h"
#include "CMapProj.h"
#include "CViewPort.h"

#define WIDTH 600
#define HEIGHT 800

#define Fx(x) (x - 72.0 ) / (136.0 -72.0 ) *  WIDTH
#define Fy(y) HEIGHT - (y - 4.0 ) / (54.0 -4.0 ) *  HEIGHT



void CGeoPolyline::AddPoint(CPoint1* pt)
{
	if (pt == nullptr) return;

	Node<CPoint1>* newNode = new Node<CPoint1>(pt);
	if (plineHead == nullptr) {
        plineHead = newNode;
		return;
	}

	Node<CPoint1>* current = plineHead;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = newNode;
}

void CGeoPolyline::Draw(CViewPort* view, const CMapProj* proj)
{
    if (!plineHead) return;

    Node<CPoint1>* current = plineHead;
    CPoint1* firstPt = current->data;
    if (!firstPt) return;

    // 经纬度 → 投影坐标
    CPoint1 p = proj->Project(firstPt->x, firstPt->y);
    moveto(Fx(p.x), Fy(p.y));


    while (current) {
        CPoint1* pt = current->data;
        if (!pt) return; 

		CPoint1 p = proj->Project(pt->x, pt->y);
        lineto(Fx(p.x), Fy(p.y));

        current = current->next;
    }
}

void CGeoPolyline::Print()
{
    std::cout 
        << "Polyline: ID=" << id << " has " << pointCount << " points." << std::endl;

    Node<CPoint1>* current = plineHead;
    while (current) {
        CPoint1* pt = current->data;
        if (pt) {
            std::cout << std::fixed << std::setprecision(2)<< "Point: x=" << pt->x << ", y=" << pt->y << std::endl;
        }
        current = current->next;
    }
}

void CGeoPolyline::ReverseLinkedList()
{
	Node<CPoint1>* prev = nullptr;
	Node<CPoint1>* current = plineHead;
	Node<CPoint1>* next = nullptr;

	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	plineHead = prev; // 更新头指针
}
