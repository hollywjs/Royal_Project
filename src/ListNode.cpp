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

void reverse(ListNode* location){
	ListNode* temp = location->next_;
	int tempRed,tempBlue,tempGreen;
	if(location != location->next_){
		location->next_ = temp->next_;
		reverse(location);
		temp->next_->next_=temp;
		temp->next_=location;
	}
}