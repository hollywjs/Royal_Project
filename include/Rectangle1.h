#pragma once
#include "cinder\gl\gl.h"

using namespace ci;

class Rectangle1{
public:
	Rectangle1(uint8_t* pixels, int kTextureSize, int x, int y, int width, int height, int red, int green, int blue);	
	void Rectangle1::draw();
	void Rectangle1::setX(int newX);
	void Rectangle1::setY(int newY);
	uint8_t* pixels;
	int kTextureSize;
	int x;
	int y;
	int width;
	int height;
	int red;
	int green;
	int blue;
};