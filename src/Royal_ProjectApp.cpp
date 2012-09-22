#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include <windows.h>
#include "Rectangle1.h"
#include "Circle.h"
#include "ListNode.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Royal_ProjectApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings(Settings* settings);

private:
	 Surface* mySurface_;
	 uint8_t* pixels;
	 static const int kAppWidth=900;	
	 static const int kAppHeight=700;	
	 static const int kTextureSize=1024;

	 int circleX;
	 int circleY;

	 Rectangle1 *rec, *rec1,*rec2,*rec3,*rec4;
	 //Rectangle1 *smallRec;

	 //Circle *circle;
	 //Circle *smallCircle;

	 ListNode* first_node;
	 ListNode* currentNode;
};

void Royal_ProjectApp::prepareSettings(Settings* settings){
	(*settings).setWindowSize(kAppWidth,kAppHeight);
	(*settings).setResizable(false);
}

void Royal_ProjectApp::setup()
{
	mySurface_ = new Surface(kTextureSize,kTextureSize,false);
	pixels = (*mySurface_).getData();
	//circleX=425;
	//circleY=400;
	first_node = new ListNode;
	first_node->next_ = first_node;
}

void Royal_ProjectApp::mouseDown( MouseEvent event )
{
	//circleX=event.getX();
	//circleY=event.getY();
}

/**void Royal_SocietyApp::keyDown(KeyEvent event){	
	if( event.getChar() == '?' ) {

	}
}
*/

void Royal_ProjectApp::update(){
	rec = new Rectangle1(pixels,kTextureSize,0,0,kAppWidth,kAppHeight,255,255,255);
	rec->draw();
	//smallRec = new Rectangle1(pixels,kTextureSize,100,350,650,100,0,150,150);
	//insertAfter(first_node, smallRec);
	rec3 = new Rectangle1(pixels,kTextureSize,230,162,100,100,50,50,50);
	insertAfter(first_node,rec3);
	rec2 = new Rectangle1(pixels,kTextureSize,330,182,75,75,100,100,100);
	insertAfter(first_node,rec2);
	rec1 = new Rectangle1(pixels,kTextureSize,400,200,50,50,150,150,150);
	insertAfter(first_node,rec1);
	currentNode=first_node->next_;
	while(currentNode != first_node){
		currentNode->data_->draw();
		currentNode=currentNode->next_;
	}
	//circle = new Circle(pixels,kTextureSize,kAppWidth,kAppHeight,425,400,50,0,100,0);
	//circle = new Circle(pixels,kTextureSize,kAppWidth,kAppHeight,circleX,circleY,100,155,0,255);
}

void Royal_ProjectApp::draw()
{
	gl::draw(*mySurface_);
}

CINDER_APP_BASIC( Royal_ProjectApp, RendererGl )