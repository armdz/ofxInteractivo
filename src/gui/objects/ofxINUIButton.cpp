//
//  GUIButton.cpp
//  Cajas
//
//  Created by lolo on 11/22/16.
//
//

#include "ofxINUIButton.hpp"


ofxINUIButton::ofxINUIButton()
{
	delegate(true);
	skin = ofxINUI::skin;
	bangPressed = false;
	dispatchBang = false;
	isToggle = false;
	val = false;
	dispatchBang = false;
	dispatchFrame = -1;
}

ofxINUIButton::~ofxINUIButton()
{

}

void  ofxINUIButton::setup(string _name,string _label, float _x, float _y, float _w, float _h)
{
		ofxINUIObject::setup(_name);
		setPosition(_x, _y);
		setSize(_w, _h);
    set_obj_type(OBJ_UI_TYPE_BUTTON);
    label = _label;
		labelBox = APP::font.getBitmapBox(label);
}

void	ofxINUIButton::setAsToggle(bool _val)
{
	isToggle = _val;
}

void	ofxINUIButton::setColor(ofFloatColor _color)
{
	skin.idle = _color;
	_color.setBrightness(.5);
	skin.pressed = _color;
}

void  ofxINUIButton::behavior()
{

	if (dispatchBang && ofGetFrameNum() > dispatchFrame)
	{
		dispatchBang = false;
		dispatchFrame = -1;
	}
	if (!isToggle) {
		if (!dispatchBang && !APP::hid.pressed()) {
			val = false;
		}
	}

}

void  ofxINUIButton::onDraw()
{

	pushMatrix();

	ofSetColor(skin.idle);

	if(val){
		ofSetColor(skin.pressed);
	}

	ofDrawRectangle(rect);

	ofPushMatrix();
	ofTranslate(getCenter());
	ofTranslate(-labelBox.getWidth()*.5, labelBox.getHeight()*.5);
	ofSetColor(0);
	ofDrawBitmapString(label, 0, 0);
	ofPopMatrix();

	popMatrix();

}

void  ofxINUIButton::onPressedDelegate(int _id, float _x, float _y)
{
	dispatchFrame = ofGetFrameNum();
	dispatchBang = true;
	if (isToggle)
		val = !val;
	else
		val = true;
}

void	ofxINUIButton::off()
{
	val = false;
}

void	ofxINUIButton::reset()
{
	val = false;
	dispatchBang = false;
	dispatchFrame = -1;
}

bool  ofxINUIButton::onPressed()
{
    return dispatchBang && val;
}

bool	ofxINUIButton::isOn()
{
	return val;
}

