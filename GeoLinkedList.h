#pragma once
#include "CGeoObject.h"
#include "CPoint1.h"

struct Node {
	CGeoObject* data = nullptr; // 指向object对象
	CPoint1* ptdata = nullptr;

	Node* next = nullptr;		  // 指向下一个节点


	Node(CGeoObject* d) : data(d), next(nullptr) {}
	Node(CPoint1* pt) : ptdata(pt), next(nullptr) {}

};

