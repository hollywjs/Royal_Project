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

bool Rectangle1::isInside(int tempX, int tempY){
	if(tempX >= x && tempX <= x+width && tempY >= y && tempY <= y+height){
		return true;
	}
	else
		return false;
}

void Rectangle1::setX(int newX){
	x=newX;
}

void Rectangle1::setY(int newY){
	y= newY;
}

void Rectangle1::setRed(int newRed){
	red= newRed;
}

void Rectangle1::setBlue(int newBlue){
	blue= newBlue;
}

void Rectangle1::setGreen(int newGreen){
	green= newGreen;
}

uint8_t* Rectangle1::getPixels(){
		return pixels;
}

int Rectangle1::getKTextureSize(){
	return kTextureSize;
}

int Rectangle1::getX(){
	return x;
}

int Rectangle1::getY(){
	return y;
}

int Rectangle1::getWidth(){
	return width;
}

int Rectangle1::getHeight(){
	return height;
}
	
int Rectangle1::getRed(){
	return red;
}

int Rectangle1::getBlue(){
	return blue;
}

int Rectangle1::getGreen(){
	return green;
}