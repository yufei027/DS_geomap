#pragma once
#include "CGeoObject.h"
#include "CPoint1.h"

struct Node {
	CGeoObject* data = nullptr; // ָ��object����
	CPoint1* ptdata = nullptr;

	Node* next = nullptr;		  // ָ����һ���ڵ�


	Node(CGeoObject* d) : data(d), next(nullptr) {}
	Node(CPoint1* pt) : ptdata(pt), next(nullptr) {}

};

