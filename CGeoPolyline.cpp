#include <graphics.h>
#include <iostream>
#include <iomanip>

#include "CGeoPolyline.h"
#include "CGeoObject.h"
#include "CGeoLayer.h"
#include "GeoLinkedList.h"

#define WIDTH 600
#define HEIGHT 800

#define Fx(x) (x - 72.0 ) / (136.0 -72.0 ) *  WIDTH
#define Fy(y) HEIGHT - (y - 4.0 ) / (54.0 -4.0 ) *  HEIGHT



void CGeoPolyline::AddPoint(CPoint1* pt)
{
	if (pt == nullptr) return;

	Node* newNode = new Node(pt);
	if (plineHead == nullptr) {
        plineHead = newNode;
		return;
	}

	Node* current = plineHead;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = newNode;
}

void CGeoPolyline::Draw()
{
    if (!plineHead) return;

    Node* current = plineHead;
    CPoint1* firstPt = current->ptdata;
    if (!firstPt) return;
    moveto(Fx(firstPt->x), Fy(firstPt->y));
    /*
    if (plineHead == nullptr || plineHead->ptdata == nullptr) return;
    moveto(Fx(plineHead->ptdata->x), Fy(plineHead->ptdata->y));
    */

    while (current) {
        CPoint1* pt = current->ptdata;
        if (!pt) return; 
        lineto(Fx(pt->x), Fy(pt->y));

        current = current->next;
    }
}

void CGeoPolyline::Print()
{
    std::cout 
        << "Polyline: ID=" << id << " has " << pointCount << " points." << std::endl;

    Node* current = plineHead;
    while (current) {
        CPoint1* pt = current->ptdata;
        if (pt) {
            //std::cout << std::fixed << std::setprecision(2)<< "Point: x=" << pt->x << ", y=" << pt->y << std::endl;
        }
        current = current->next;
    }
}
