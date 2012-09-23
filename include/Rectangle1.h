#pragma once
#include "cinder\gl\gl.h"

using namespace ci;

class Rectangle1{
public:
	Rectangle1(uint8_t* pixels, int kTextureSize, int x, int y, int width, int height, int red, int green, int blue);	
	void Rectangle1::draw();
	void Rectangle1::setX(int newX);
	void Rectangle1::setY(int newY);
	void Rectangle1::setRed(int newRed);
	void Rectangle1::setBlue(int newBlue);
	void Rectangle1::setGreen(int newGreen);
	bool Rectangle1::isInside(int tempX, int tempY);
	uint8_t* Rectangle1::getPixels();
	int Rectangle1::getKTextureSize();
	int Rectangle1::getX();
	int Rectangle1::getY();
	int Rectangle1::getWidth();
	int Rectangle1::getHeight();
	int Rectangle1::getRed();
	int Rectangle1::getBlue();
	int Rectangle1::getGreen();
private:
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