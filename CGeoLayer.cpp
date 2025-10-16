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


#define isTextMode  false
#define WIDTH 600
#define HEIGHT 800

#define Fx(x) (x - 72.0 ) / (136.0 -72.0 ) *  WIDTH
#define Fy(y) HEIGHT - (y - 4.0 ) / (54.0 -4.0 ) *  HEIGHT


void CGeoLayer::ReadData() {
	points.clear();
	int size = 0;
	

	ifstream file("E:\\GISʵϰ\\ʵϰ����\\chnCities.txt", ios_base::in);
	if (!file.is_open()) {
		std::cerr << "�ļ���ʧ�ܣ�" << std::endl;
		return;
	}
	std::string line;

	if (!isTextMode) {

		initgraph(HEIGHT, WIDTH);	// ������ͼ���ڣ���СΪ HEIGHT x WIDTH ����
		setcolor(RGB(255, 0, 0));
	}

	while (std::getline(file, line)) {

		istringstream istrStream(line);
		CGeoPoint p;
		istrStream >> p.id >>p.x >> p.y >> p.chnName;
		points.push_back(p);



		if (isTextMode) {

			std::cout << "id=" << p.id
				<< "   x=" << p.x
				<< "   y=" << p.y
				<< "   chnName=" << p.chnName
				<< std::endl;
		}
		else {
			// circle(Fx(pts[size].x), Fy(pts[size].y), 2);
			circle(Fx(p.x), Fy(p.y), 2);
		}

		size++;

	}
	
	file.close();

	if (!isTextMode) {

		_getch();				// �����������
		closegraph();			// �رջ�ͼ����
	}

}



void CGeoLayer::Search(CPoint1 pt, double dist) {
}

void CGeoLayer::DrawLayer() {
	Node* currentNode = m_head;
	while (currentNode != nullptr) {
		currentNode->data->Draw(); // ���ö����draw����
		currentNode = currentNode->next;
	}
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


void CGeoLayer::Output() {
	std::cout << "Output����";
	for(int i=0 ; i<points.size() ; i++){

		std::cout<< "id=" << points[i].id
			<< "   x=" << points[i].x
			<< "   y=" << points[i].y
			<< "   chnName=" << points[i].chnName
			<< std::endl;
	}
};