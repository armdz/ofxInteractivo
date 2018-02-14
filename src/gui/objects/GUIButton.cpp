//
//  GUIButton.cpp
//  Cajas
//
//  Created by lolo on 11/22/16.
//
//

#include "GUIButton.hpp"


GUIButton::GUIButton()
{
}

GUIButton::~GUIButton()
{

}

void  GUIButton::setup(string _name,string _label)
{
    set_obj_type(OBJ_UI_TYPE_BUTTON);
    ofxINUIObject::setup(_name);
    label = _label;
    label_bbox = VSUI::calculate_bbox(_label);
}

void  GUIButton::init()
{
    set_interactive(true);
    bang_pressed = false;
    dispatch_bang = false;
}

void  GUIButton::behavior()
{
    
    if(dispatch_bang)
      dispatch_bang = false;
    if(is_pressed())
    {
      if(!bang_pressed)
      {
        bang_pressed = true;
        dispatch_bang = true;
      }
    }else{
      dispatch_bang = false;
      bang_pressed = false;
    }
}

void  GUIButton::draw()
{

    ofxINUIObject::draw();
    if(is_pressed())
    {
      ofSetColor(VSUI_COLOR_OVER);
      ofDrawRectangle(*this);
    }
    ofSetColor(VSUI_COLOR_TEXT);
    ofPushMatrix();
    ofTranslate(x,y);
    ofPushMatrix();
    ofTranslate(0, getHeight()/2);
    ofTranslate(UI_FONT_SIZE, (label_bbox.getHeight()/2));
    //VSUI::font.drawString(label, 0, 0);
    ofPopMatrix();
    ofPushStyle();
    ofNoFill();
    ofSetColor(0);
    ofDrawRectangle(0,0,getWidth(),getHeight());
    ofPopStyle();
    ofPopMatrix();
}

bool  GUIButton::on_pressed()
{
    return dispatch_bang;
}


