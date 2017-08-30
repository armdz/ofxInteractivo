//
//  ofxInteractivoHID.cpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#include "ofxInteractivoHID.h"

ofxInteractivoHID::ofxInteractivoHID()
{
    is_pressed = -1;
}

ofxInteractivoHID::~ofxInteractivoHID()
{
    
}

void    ofxInteractivoHID::init()
{
    ofRegisterMouseEvents(this);
    is_pressed = -1;
    is_pressed_banged = false;
}

//  HID Mouse

void    ofxInteractivoHID::mouseMoved(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = -1;
}

void    ofxInteractivoHID::mouseDragged(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = arg.button;
}

void    ofxInteractivoHID::mousePressed(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = arg.button;
}

void    ofxInteractivoHID::mouseReleased(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = -1;
    is_pressed_banged = false;
}

void    ofxInteractivoHID::mouseEntered(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = -1;
}

void    ofxInteractivoHID::mouseExited(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = -1;
}

void    ofxInteractivoHID::mouseScrolled(ofMouseEventArgs &arg)
{
    
}

//

int    ofxInteractivoHID::pressed()
{
    return is_pressed != -1;
}

bool   ofxInteractivoHID::bang_pressed()
{
    bool ret = false;
    if(pressed() && !is_pressed_banged)
    {
        is_pressed_banged = true;
        ret = true;
    }
    return ret;
}
