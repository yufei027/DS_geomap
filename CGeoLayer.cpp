#include <iostream>
#include <fstream>
#include <sstream>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <windows.h>
#include <vector>

#include "CGeoLayer.h"
#include "CGeoObject.h"
#include "CGeoPoint.h"
#include "CGeoPolyline.h"

using namespace std;



#define WIDTH 600
#define HEIGHT 800

#define Fx(x) (x - 72.0 ) / (136.0 -72.0 ) *  WIDTH
#define Fy(y) HEIGHT - (y - 4.0 ) / (54.0 -4.0 ) *  HEIGHT


void CGeoLayer::ReadData(const string& filename) {

	std::ifstream file(filename, ios_base::in); // ֻ��
	if (!file.is_open()) {
		std::cerr << "�ļ���ʧ�ܣ�" << std::endl;
		return;
	}

	string line;
	string ext = filename.substr(filename.find_last_of('.') + 1);

	if (ext == "txt" || ext == "TXT") {// ���ļ���ȡ
		while (getline(file, line)) { 
			
			istringstream istrStream(line);
			CGeoPoint* obj = new CGeoPoint;
			istrStream >> obj->id >> obj->x >> obj->y >> obj->chnName;

			AddObject(obj);
			//delete obj;
		}
	}
	else if (ext == "mif" || ext == "MIF") {

		while (getline(file, line)) { // ����ͷ��
			if (line.empty()) continue;
			if (line == "DATA") break; 
		}

		while (getline(file, line)) { // ���ļ���ȡ
			if (line.empty()) continue;

			istringstream istrStream(line);
			CGeoPolyline* obj = new CGeoPolyline;

			double x, y;
			CGeoPoint pt;
			if (!(istrStream >> x >> y)) break; // // �����������оͽ���
			istrStream >> x >> y; pt.x = x; pt.y = y;

			obj->points.push_back(pt);
			
			AddObject(obj);
			//delete obj;

		}
	}


	file.close();

}





/*
void CGeoLayer::AddObject(CGeoObject* obj) // ����ǰ��add
{
	if(obj == nullptr) return;

	Node* newNode = new Node(obj);
	newNode->next = m_head; // ����ָ��ԭ���ģ���һ���ڵ�
	m_head = newNode; // �����ڱ�ɵ�һ���ڵ�
}

*/

void CGeoLayer::AddObject(CGeoObject* obj) // �����add
{	
	if (obj == nullptr) return;
	Node* newNode = new Node(obj);
	if (m_head == nullptr) { // ���Ϊ��ָ�룬newNode�ͱ�ɵ�һ���ڵ�
		m_head = newNode;
		return;
	}
	// ������ǿ�ָ�룬��Ҫ��ӵ�����
	Node* current = m_head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = newNode;  
}

void CGeoLayer::Search(CPoint1 pt, double dist) {
}

void CGeoLayer::DrawLayer() {
	initgraph(HEIGHT, WIDTH);	// ������ͼ���ڣ���СΪ HEIGHT x WIDTH ����
	setcolor(RGB(255, 0, 0));

	Node* currentNode = m_head;
	while (currentNode) {
		currentNode->data->Draw(); // ���ö����draw����
		currentNode = currentNode->next;
	}

	(void)_getch();
	closegraph();
}

void CGeoLayer::PrintLayer() {
	Node* currentNode = m_head;
	while (currentNode) {
		currentNode->data->Print();
		currentNode = currentNode->next;
	}
}

CGeoLayer::~CGeoLayer() {

	Node* current = m_head;
	while (current) {
		Node* next = current->next;
		delete current->data; // �ͷŶ���
		delete current; // �ͷŽڵ�
		current = next;
	}
}

;

