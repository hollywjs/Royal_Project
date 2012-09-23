/**
*  This is used to create and utilize my link list, this satifies 
*  objective A, I created a double linked never empty circular
*  link list
*/
#pragma once
#include "ListNode.h"
#include "cinder\gl\gl.h"

using namespace ci;

/**
*  Constructs a ListNode
*/
ListNode::ListNode(){
}

/**
*  Inserts a specified rectangle into the list after a a specified
*  location
*/
void insertAfter(ListNode* location, Rectangle1* newRect){
	ListNode* temp = new ListNode;
	temp->data_ = newRect;
	temp->next_ = location->next_;
	temp->previous_=location;
	location->next_ = temp;
}

/**
*  Reverses the list
*/
void reverse(ListNode* location){
	ListNode* cur = location;
	do{
		ListNode* temp = cur->next_;
		cur->next_ = cur->previous_;
		cur->previous_ = temp;
		cur = cur->previous_;
	}
	while(cur != location);
}

/**
*  Moves a square to the back of the list
*/
void reorder(ListNode* location, Rectangle1* rec){
	ListNode* temp = location->next_;
	location->next_ = temp->next_;
	insertAfter(location->firstNode->previous_, rec);
}
