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

using namespace std;



#define WIDTH 600
#define HEIGHT 800

#define Fx(x) (x - 72.0 ) / (136.0 -72.0 ) *  WIDTH
#define Fy(y) HEIGHT - (y - 4.0 ) / (54.0 -4.0 ) *  HEIGHT


void CGeoLayer::ReadData(const std::string& filename) {
	std::vector<CGeoPoint> points;
	points.clear();
	int size = 0;
	

	std::ifstream file(filename, ios_base::in); // ֻ��
	if (!file.is_open()) {
		std::cerr << "�ļ���ʧ�ܣ�" << std::endl;
		return;
	}
	std::string line;

	while (std::getline(file, line)) {

		istringstream istrStream(line);
		/*
		CGeoPoint p;
		istrStream >> p.id >>p.x >> p.y >> p.chnName;
		points.push_back(p);
		
		std::cout << "id=" << p.id
			<< "   x=" << p.x
			<< "   y=" << p.y
			<< "   chnName=" << p.chnName
			<< std::endl;

		size++;
		*/
		CGeoPoint* obj = new CGeoPoint;
		istrStream >> obj->id >> obj->x >> obj->y >> obj->chnName;
		// layer.AddObject(obj);

		this->AddObject(obj);  // ��Ա�����ڲ����� this ָ����ʶ���ĳ�Ա����
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
	while (currentNode != nullptr) {
		currentNode->data->Draw(); // ���ö����draw����
		currentNode = currentNode->next;
	}

	_getch();
	closegraph();
}

void CGeoLayer::PrintLayer() {
	Node* currentNode = m_head;
	while (currentNode != nullptr) {
		currentNode->data->Print();
		currentNode = currentNode->next;
	}
};