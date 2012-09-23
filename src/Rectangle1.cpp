#pragma once
#include "Rectangle1.h"
#include "cinder\gl\gl.h"

using namespace ci;

/**
*  This creates a rectangle with specific data entered, this 
*  rectangle has it's own data members, pixels, kTextureSize, x, y, 
*  width, height, red, green, and blue that are set in this method.
*/
Rectangle1::Rectangle1(uint8_t* pixels2, int kTextureSize2, int x2,
	int y2, int width2, int height2, int red2, int green2, int blue2){
	
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

/**
*  This draws the rectangle to the specified surface
*/
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

/**
*  This determines whether a given point is inside a retangle
*/
bool Rectangle1::isInside(int tempX, int tempY){
	if(tempX >= x && tempX <= x+width && tempY >= y && 
		tempY <= y+height){
		return true;
	}
	else
		return false;
}

/**
* This allows for the x to be reset, so the square can be moved
*/
void Rectangle1::setX(int newX){
	x=newX;
}

/**
*  This allows for the y to be reset, so the square can be moved
*/
void Rectangle1::setY(int newY){
	y= newY;
}

/**
*  This allows for the red value to be reset, so the square can
*  change colors.
*/
void Rectangle1::setRed(int newRed){
	red= newRed;
}

/**
*  This allows for the blue value to be reset, so the square can
*  change colors.
*/
void Rectangle1::setBlue(int newBlue){
	blue= newBlue;
}

/**
*  This allows for the green value to be reset, so the square can
*  change colors.
*/
void Rectangle1::setGreen(int newGreen){
	green= newGreen;
}

/**
*  Returns the rectangle's x value
*/
int Rectangle1::getX(){
	return x;
}

/**
*  Returns the rectangle's y value
*/
int Rectangle1::getY(){
	return y;
}

/**
*  Returns the rectangle's width value
*/
int Rectangle1::getWidth(){
	return width;
}

/**
*  Returns the rectangle's height value
*/
int Rectangle1::getHeight(){
	return height;
}

/**
*  Returns the rectangle's red value
*/
int Rectangle1::getRed(){
	return red;
}

/**
*  Returns the rectangle's blue value
*/
int Rectangle1::getBlue(){
	return blue;
}

/**
*  Returns the rectangle's green value
*/
int Rectangle1::getGreen(){
	return green;
}