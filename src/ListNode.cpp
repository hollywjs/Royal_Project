#pragma once
#include "ListNode.h"
#include "cinder\gl\gl.h"

using namespace ci;

ListNode::ListNode(){

}

void insertAfter(ListNode* location, Rectangle1* newRect){
	ListNode* temp = new ListNode;
	temp->data_ = newRect;
	temp->next_ = location->next_;
	location->next_ = temp;
}
