#pragma once
#include "CGeoObject.h"
#include "CPoint1.h"

template<typename T>
struct Node {
	T* data; // ָ��object����
	Node* next; // ָ����һ���ڵ�


	Node(T* d) : data(d), next(nullptr) {}
};

