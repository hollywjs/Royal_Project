#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include <windows.h>
#include "Rectangle1.h"
#include "Circle.h"
#include "ListNode.h"
#include "cinder/Text.h"

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
	void displayHelp();
	void Royal_ProjectApp::render();

private:
	 Surface* mySurface_;
	 uint8_t* pixels;
	 static const int kAppWidth=900;	
	 static const int kAppHeight=700;	
	 static const int kTextureSize=1024;

	 bool isDisplayed;
	 Font wordFont;
	 gl::Texture textureFont;
	 int circleX;
	 int circleY;
	 int recX;
	 int recY;
	 int eventTimes;
		 
	 Rectangle1 *rec, *rec1,*rec2,*rec3,*rec4;
	 Rectangle1 *tempRec;
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
	wordFont = Font("Tahoma",32);
	render();		
	isDisplayed = false;
	//circleX=425;
	//circleY=400;
	recX = 325;
	recY = 215;
	first_node = new ListNode;
	first_node->firstNode = first_node;
	first_node->next_ = first_node;
	rec4 = new Rectangle1(pixels,kTextureSize,recX-225,recY-75,150,150,0,0,0);
	insertAfter(first_node,rec4);
	rec3 = new Rectangle1(pixels,kTextureSize,recX-150,recY-50,125,125,50,50,50);
	insertAfter(first_node,rec3);
	rec2 = new Rectangle1(pixels,kTextureSize,recX-75,recY-25,100,100,100,100,100);
	insertAfter(first_node,rec2);
	rec1 = new Rectangle1(pixels,kTextureSize,recX,recY,75,75,150,150,150);
	insertAfter(first_node,rec1);
	tempRec = new Rectangle1(pixels, kTextureSize, 0, 0, 0, 0, 0, 0, 0);
}

void Royal_ProjectApp::render(){	
	string txt = "Welcome to the help box!\n\n Key Controls: \n ?      Turns on and off help message \n r      Reverses the shapes order \n\n Mouse Control: \n Click on a shape and move the mouse to move one shape or a group of shapes from one place to another";	
	TextBox tbox = TextBox().alignment( TextBox::CENTER ).font(wordFont).size( Vec2i( 512, 511) ).text( txt );	
	tbox.setColor( Color( 1.0f, 1.0f, 1.0f ) );	
	tbox.setBackgroundColor( ColorA( 0.5, 0, 0.25, 1 ) );	
	textureFont = gl::Texture( tbox.render() );
}

void Royal_ProjectApp::mouseDown( MouseEvent event )
{
	recX = event.getX();
	recY = event.getY();
	eventTimes=0;
	currentNode=first_node->next_;
	//reorder(currentNode,currentNode->data_);
	//while(currentNode != first_node){
	//	currentNode->data_->setX(recX-(eventTimes*75));
	//	currentNode->data_->setY(recY-(eventTimes*25));
	//	eventTimes++;
	//	currentNode=currentNode->next_;
	//}
/**
	while(currentNode != first_node){
		if(currentNode->data_->isInside(recX, recY)){
			currentNode->data_->setX(recX-(eventTimes*75));
			currentNode->data_->setY(recY-(eventTimes*25));
			eventTimes++;
			currentNode=currentNode->next_;
		}
	}
*/
	//circleX=event.getX();
	//circleY=event.getY();
}

/**void Royal_ProjectApp::keyDown(KeyEvent event){	
	if( event.getChar() == '?' ) {
		if(isDisplayed == true){
			isDisplayed == false;
		}
		else
			isDisplayed == true;
	}
	else if(event.getChar() == 'r'){
		reverse(first_node);
	}
}
*/


void Royal_ProjectApp::update(){
	rec = new Rectangle1(pixels,kTextureSize,0,0,kAppWidth,kAppHeight,255,255,255);
	rec->draw();
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
	if (textureFont && isDisplayed)		
		gl::draw(textureFont);
}

CINDER_APP_BASIC( Royal_ProjectApp, RendererGl )