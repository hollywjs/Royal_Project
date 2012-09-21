#pragma once
#include "Circle.h"
#include "cinder\gl\gl.h"

using namespace ci;

Circle::Circle(uint8_t* pixels, int kTextureSize, int kAppWidth, int kAppHeight, double x, double y, int radius, int red, int green, int blue){	
	for(int y1=0;y1<kAppHeight;y1++){
		for(int x1=0;x1<kAppWidth;x1++){
			double distance=pow((x1-x),2);
			distance = distance + pow((y1-y),2);
			distance = sqrt(distance);
			if(distance <= radius){
				pixels[(x1+y1*kTextureSize)*3]=red;
				pixels[(x1+y1*kTextureSize)*3+1]=green;
				pixels[(x1+y1*kTextureSize)*3+2]=blue;
			}
		}
	}
}
