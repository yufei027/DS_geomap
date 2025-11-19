#include <iostream>
#include <fstream>
#include <sstream>
#include <graphics.h>		
#include <conio.h>
#include <windows.h>
#include <vector>
#include <queue>

#include "CGeoLayer.h"
#include "CGeoObject.h"
#include "CGeoPoint.h"
#include "CGeoPolyline.h"
#include "CPoint1.h"
#include "GeoLinkedList.h"
#include "CMapProj.h"
#include "CViewPort.h"
using namespace std;

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

			viewport.UpdExtent(obj->x, obj->y);

			points.push_back(obj);
			AddObject(obj);
			

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
					CPoint1 pt(x, y);

					viewport.UpdExtent(pt.x, pt.y); // 更新范围
					obj->AddPoint(&pt);

				}
				AddObject(obj);
			}
		}
	}

	file.close();
}

void CGeoLayer::ReadDataBtree(const string& filename)
{
	
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

void CGeoLayer::AddBtreeObject(CGeoObject** rt, CGeoObject* obj) // root 和新的obj
{
	if (*rt == nullptr) 
		*rt = obj;
	else
	{
		if (obj->id < (*rt)->id)
			AddBtreeObject(&((*rt)->leftChild), obj);
		else
			AddBtreeObject(&((*rt)->rightChild), obj);
	}
}

void CGeoLayer::LDR_Order(CGeoObject* rt)
{
	if (rt != nullptr)
	{
		LDR_Order(rt->leftChild);
		cout << rt->id << " "; // rt->Print();
		LDR_Order(rt->rightChild);
	}
}

void CGeoLayer::DLR_Order(CGeoObject* rt)
{
	if (rt != nullptr)
	{
		cout << rt->id << " ";           
		DLR_Order(rt->leftChild);        
		DLR_Order(rt->rightChild);       
	}
}

void CGeoLayer::LRD_Order(CGeoObject* rt)
{
	if (rt != nullptr)
	{
		LRD_Order(rt->leftChild);        
		LRD_Order(rt->rightChild);       
		cout << rt->id << " ";           
	}
}


void CGeoLayer::LevelOrder(CGeoObject* root)
{
	if (root == nullptr)
		return;

	queue<CGeoObject*> q;  
	q.push(root);           // 根节点

	while (!q.empty())
	{
		CGeoObject* node = q.front();  
		q.pop();

		cout << node->id << " ";       

		if (node->leftChild)           
			q.push(node->leftChild);
		if (node->rightChild)          
			q.push(node->rightChild);
	}
}
void CGeoLayer::SortList(std::string& type, std::vector<CGeoPoint*>& points)
{
	int n = points.size();

	if (type == "bubble") {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (points[j]->x > points[j + 1]->x) {
					SwapPoints(points[j], points[j + 1]);  // swap 函数
				}
			}
		}
	}
	else if (type == "selection") {
		for (int i = 0; i < n - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < n; j++) {
				if (points[j]->x < points[minIndex]->x) {
					minIndex = j;
				}
			}
			if (minIndex != i) {
				SwapPoints(points[i], points[minIndex]); // swap 函数
			}
		}
	}
}
void CGeoLayer::SwapPoints(CGeoPoint* pt1, CGeoPoint* pt2)
{
	if (!pt1 || !pt2) return;

	CGeoPoint temp(*pt1);

	*pt1 = CGeoPoint(*pt2);
	*pt2 = CGeoPoint(temp);
}
void CGeoLayer::SearchList(std::string& type, const std::vector<CGeoPoint*>& points, double target)
{
	if (type == "Linear") { // 顺序查找
	}
	else if (type == "Binary") { // 二分查找

	}
}
int CGeoLayer::getBTreeHeight(CGeoObject* rt) 
{
	if (rt == nullptr)
		return 0;
	else
	{
		int leftHeight = getBTreeHeight(rt->leftChild);
		int rightHeight = getBTreeHeight(rt->rightChild);
		return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
	}
}


void CGeoLayer::DrawLayer(CViewPort* view, const CMapProj* proj) {

	// 为了更新画布正常显示数据，我们需要遍历所有对象，计算投影后的数值范围
	Node<CGeoObject>* current = m_head;
	while (current != nullptr) {
		CGeoObject* obj = current->data;  // 取出对象

		if (auto point = dynamic_cast<CGeoPoint*>(obj)) {
			CPoint1 p = proj->Project(point->x, point->y);
			view->UpdExtent(p.x, p.y);
		}
		else if (auto polyline = dynamic_cast<CGeoPolyline*>(obj)) {
			for (auto pt : polyline->points) {
				CPoint1 p = proj->Project(pt->x, pt->y);
				view->UpdExtent(p.x, p.y);
			}
		}

		current = current->next;  // 移动到下一个节点
	}

	view->BeginDraw(view->lineColor);

	// 重新遍历链表进行绘制
	current = m_head;
	while (current) {
		current->data->Draw(view, proj);
		current = current->next;
	}

	view->EndDraw();
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

