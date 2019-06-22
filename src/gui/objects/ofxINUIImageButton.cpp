//
//  ofxINUIImageButton.cpp
//  mapaCabildo
//
//  Created by Lolo on 20/03/2018.
//

#include "ofxINUIImageButton.hpp"


ofxINUIImageButton::ofxINUIImageButton()
{
    delegate(true);
}

ofxINUIImageButton::~ofxINUIImageButton()
{
    
}

void    ofxINUIImageButton::setup(string _name,ofImage _img)
{
    face = _img;
    set_obj_type(OBJ_UI_TYPE_BUTTON);
    ofxINUIObject::setup(_name);
    set(0,0,face.getWidth(),face.getHeight());
}

void  ofxINUIImageButton::setup(string _name,string _label)
{
    set_obj_type(OBJ_UI_TYPE_BUTTON);
    ofxINUIObject::setup(_name);
    label = _label;
    label_bbox = VSUI::calculate_bbox(_label);
}

void  ofxINUIImageButton::init()
{
    set_interactive(true);
    bang_pressed = false;
    dispatch_bang = false;
}

void  ofxINUIImageButton::behavior()
{
    
    if(dispatch_bang)
        dispatch_bang = false;
    if(is_pressed())
    {
        /*
        if(!bang_pressed)
        {
            bang_pressed = true;
            dispatch_bang = true;
        }*/
    }else{
        dispatch_bang = false;
        bang_pressed = false;
    }
    
}

void  ofxINUIImageButton::on_pressed_delegate(ofxINHIDEvent   &_e)
{
    
    int     px = abs(_e.pointer.x-x);
    int     py = abs(_e.pointer.y-y);
    
    ofColor color = face.getColor(px, py);
    if(color.a > 0.0)
    {
        status = INUIObject_Pressed;
    }

    
}

void  ofxINUIImageButton::draw()
{
    
    ofxINUIObject::draw();

    ofEnableAlphaBlending();
    
    ofPushMatrix();
    ofTranslate(x,y);
    ofSetColor(255,is_pressed() ? 100 : 255);
    face.draw(0,0);
    ofPopMatrix();
    
    ofDisableAlphaBlending();
}

bool  ofxINUIImageButton::on_pressed()
{
    return dispatch_bang;
}
