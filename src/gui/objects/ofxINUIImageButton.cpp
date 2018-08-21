//
//  ofxINUIImageButton.cpp
//  mapaCabildo
//
//  Created by Lolo on 20/03/2018.
//

#include "ofxINUIImageButton.hpp"


ofxINUIImageButton::ofxINUIImageButton()
{
	hasFace = false;
  delegate(true);
}

ofxINUIImageButton::~ofxINUIImageButton()
{
    
}

void    ofxINUIImageButton::setup(string _name,ofImage _face, float _x, float _y, float _resize)
{
   
    set_obj_type(OBJ_UI_TYPE_BUTTON);
    ofxINUIObject::setup(_name);
		setPosition(_x, _y);
		if (_face.isAllocated()) {
			setFace(_face,_resize);
		}
		else {
			hasFace = false;
			setSize(100,100);
		}
}

void	ofxINUIImageButton::setFace(ofImage _img, float _resize)
{
	face = _img;
	face.resize(face.getWidth()*_resize, face.getHeight()*_resize);
	setSize(face.getWidth(), face.getHeight());
	hasFace = true;
}

void	ofxINUIImageButton::resizeFace(float _w, float _h)
{
	face.resize(_w, _h);
	setSize(face.getWidth(), face.getHeight());
}

void  ofxINUIImageButton::onPressedDelegate(int _id, float _x, float _y)
{

	if (hasFace) {
		ofColor color = face.getColor((unsigned int)_x, (unsigned int)_y);
		if (color.a > 0.0)
		{
			ofxINUIButton::onPressedDelegate(_id, _x, _y);
		}
	}
	else {
		ofxINUIButton::onPressedDelegate(_id, _x, _y);
	}
    
}

void  ofxINUIImageButton::onDraw()
{

    ofEnableAlphaBlending();
    
		pushMatrix();
		if (!val)
		{
			ofSetColor(ofxINUI::skin.imageButtonIdle);
		}
		else if(val) {
			ofSetColor(ofxINUI::skin.imageButtonPressed);
		}

		if (hasFace) {
			face.draw(0, 0);
		}
		else {
			ofDrawRectangle(0, 0, rect.getWidth(), rect.getHeight());
			ofSetColor(0);
			ofNoFill();
			ofDrawLine(0, 0, getWidth(), getHeight());
			ofDrawRectangle(0, 0, rect.getWidth(), rect.getHeight());
			ofFill();
		}

		popMatrix();
    
    ofDisableAlphaBlending();
}

bool  ofxINUIImageButton::on_pressed()
{
    return dispatchBang;
}
