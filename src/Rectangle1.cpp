#pragma once
#include "Rectangle1.h"
#include "cinder\gl\gl.h"

using namespace ci;

Rectangle1::Rectangle1(uint8_t* pixels2, int kTextureSize2, int x2, int y2, int width2, int height2, int red2, int green2, int blue2){
	this->pixels=pixels2;
	this->kTextureSize=kTextureSize2;
	this->x=x2;
	this->y=y2;
	this->width=width2;
	this->height=height2;
	this->red=red2;
	this->green=green2;
	this->blue=blue2;
}

void Rectangle1::draw()
{
	int rectHeight = y+height;
	int rectWidth = x+width;
	int index;
	for(int tempY=y;tempY<rectHeight;tempY++){
		for(int i=x;i<rectWidth;i++){
			index=(i+tempY*kTextureSize)*3;
			pixels[index]=red;
			pixels[index+1]=green;
			pixels[index+2]=blue;
		}
	}
}


void Rectangle1::setX(int newX){
	x=newX;
}

void Rectangle1::setY(int newY){
	y= newY;
}