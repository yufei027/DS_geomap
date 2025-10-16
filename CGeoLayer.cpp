#include <iostream>
#include <fstream>
#include <sstream>
#include <graphics.h>		// 引用图形库头文件
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
	

	std::ifstream file(filename, ios_base::in); // 只读
	if (!file.is_open()) {
		std::cerr << "文件打开失败！" << std::endl;
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

		this->AddObject(obj);  // 成员函数内部，用 this 指针访问对象的成员即可
	}
	
	file.close();

}





/*
void CGeoLayer::AddObject(CGeoObject* obj) // 在最前面add
{
	if(obj == nullptr) return;

	Node* newNode = new Node(obj);
	newNode->next = m_head; // 让它指向（原来的）第一个节点
	m_head = newNode; // 它现在变成第一个节点
}

*/

void CGeoLayer::AddObject(CGeoObject* obj) // 在最后add
{	
	if (obj == nullptr) return;
	Node* newNode = new Node(obj);
	if (m_head == nullptr) { // 如果为空指针，newNode就变成第一个节点
		m_head = newNode;
		return;
	}
	// 如果不是空指针，就要添加到后面
	Node* current = m_head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = newNode;
}

void CGeoLayer::Search(CPoint1 pt, double dist) {
}

void CGeoLayer::DrawLayer() {
	initgraph(HEIGHT, WIDTH);	// 创建绘图窗口，大小为 HEIGHT x WIDTH 像素
	setcolor(RGB(255, 0, 0));

	Node* currentNode = m_head;
	while (currentNode != nullptr) {
		currentNode->data->Draw(); // 调用对象的draw方法
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