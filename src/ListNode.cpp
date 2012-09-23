/**
*  This is used to create and utilize my link list, this satifies 
*  objective A, I created a single linked never empty circular
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
	location->next_ = temp;
}

/**
*  Reverses the list, this meets the goal E
*/
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

