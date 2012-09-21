#pragma once
#include "cinder\gl\gl.h"

using namespace ci;

class Rectangle1{
public:
	Rectangle1(uint8_t* pixels, int kTextureSize, int x, int y, int width, int height, int red, int green, int blue);	
	void draw();
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