#pragma once
#include "CGeoObject.h"
#include "CPoint1.h"

template<typename T>
struct Node {
	T* data; // 指向object对象
	Node* next; // 指向下一个节点


	Node(T* d) : data(d), next(nullptr) {}
};

