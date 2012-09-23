#pragma once
#include "Rectangle1.h"
#include "cinder\gl\gl.h"

using namespace ci;

class ListNode{
public:
	ListNode();

	ListNode* firstNode;
	ListNode* next_;
	ListNode* previous_;
	Rectangle1* data_;
};

void insertAfter(ListNode* location, Rectangle1* newRec);
void reverse(ListNode* location);
void reorder(ListNode* location, Rectangle1* rec);
