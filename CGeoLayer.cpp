#include <iostream>
#include <fstream>
#include <sstream>
#include <graphics.h>		
#include <conio.h>
#include <windows.h>
#include <vector>

#include "CGeoLayer.h"
#include "CGeoObject.h"
#include "CGeoPoint.h"
#include "CGeoPolyline.h"
#include "CPoint1.h"
#include "GeoLinkedList.h"
#include "CMapProj.h"
using namespace std;



#define WIDTH 600
#define HEIGHT 800

#define Fx(x) (x - 72.0 ) / (136.0 -72.0 ) *  WIDTH
#define Fy(y) HEIGHT - (y - 4.0 ) / (54.0 -4.0 ) *  HEIGHT


void CGeoLayer::ReadData(const string& filename) {

	std::ifstream file(filename, ios_base::in);
	if (!file.is_open()) {
		std::cerr << "无法打开" << std::endl;
		return;
	}

	string line;
	string ext = filename.substr(filename.find_last_of('.') + 1);

	if (ext == "txt" || ext == "TXT") {
		while (getline(file, line)) { 
			
			istringstream istrStream(line);
			CGeoPoint* obj = new CGeoPoint;
			istrStream >> obj->id >> obj->x >> obj->y >> obj->chnName;

			AddObject(obj);
			//delete obj;
		}
	}
	else if (ext == "mif" || ext == "MIF") {

		while (getline(file, line)) {
			if (line.empty()) continue;
			if (line.find("Data") != string::npos) break;
		}
		int id = 1;

		// 外层循环：读取每个 polyline
		while (getline(file, line)) {
			if (line.empty()) continue;


			// 检测到 Pline 开头，开始读取一个新的 polyline
			if (line.find("Pline") != string::npos || 
				line.find("pline") != string::npos) {
				CGeoPolyline* obj = new CGeoPolyline;

				istringstream plineStream(line); // 点的数量
				string keyword;
				int pointCount = 0;
				plineStream >> keyword >> pointCount;
				obj->pointCount = pointCount;
				obj->id = id++;

				// 内层循环：读取 polyline 的点
				while (std::getline(file, line)) {
					if (line.empty()) continue;
					if (line.find("Pen") != string::npos) break;


					istringstream istrStream(line);
					double x, y;
					if (!(istrStream >> x >> y)) continue;
					CPoint1* pt = new CPoint1(x, y);
					obj->AddPoint(pt);

				}
				AddObject(obj);
			}
		}
	}

	file.close();
}

void CGeoLayer::Search(CPoint1 pt, double dist)
{
}





/*
void CGeoLayer::AddObject(CGeoObject* obj) // 从前面add
{
	if(obj == nullptr) return;

	Node* newNode = new Node(obj);
	newNode->next = m_head;
	m_head = newNode;
}

*/

void CGeoLayer::AddObject(CGeoObject* obj) // 从后面add
{	
	if (obj == nullptr) return;
	Node<CGeoObject>* newNode = new Node<CGeoObject>(obj);
	if (m_head == nullptr) {
		m_head = newNode;
		return;
	}

	Node<CGeoObject>* current = m_head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = newNode;  
}




void CGeoLayer::DrawLayer(const CMapProj* proj) {
	initgraph(HEIGHT, WIDTH);
	setcolor(RGB(255, 0, 0));

	Node<CGeoObject>* current = m_head;
	while (current) {
		current->data->Draw(proj);
		current = current->next;
	}

	(void)_getch();
	closegraph();
}

void CGeoLayer::PrintLayer() {
	Node<CGeoObject>* current = m_head;
	while (current) {
		current->data->Print();
		current = current->next;
	}
}


void CGeoLayer::ReverseLinkedList()
{
	Node<CGeoObject>* prev = nullptr;
	Node<CGeoObject>* current = m_head;
	Node<CGeoObject>* next = nullptr;

	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	m_head = prev;
}


CGeoLayer::CGeoLayer()
{

}

CGeoLayer::~CGeoLayer() {

	Node<CGeoObject>* current = m_head;
	while (current) {
		Node<CGeoObject>* next = current->next;
		delete current->data;
		delete current;
		current = next;
	}
}

;

