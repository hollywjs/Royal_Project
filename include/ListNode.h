#pragma once
#include "Rectangle1.h"
#include "cinder\gl\gl.h"

using namespace ci;

class ListNode{
public:
	ListNode();

	ListNode* next_;
	ListNode* previous_;
	Rectangle1* data_;
};

void insertAfter(ListNode* n, Rectangle1* r);
