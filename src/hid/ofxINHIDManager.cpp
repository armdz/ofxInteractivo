//
//  HIDManager.cpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#include "ofxINHIDManager.h"

ofxINHIDManager::ofxINHIDManager()
{
    is_pressed = -1;
    is_released = false;
}

ofxINHIDManager::~ofxINHIDManager()
{
    
}

void    ofxINHIDManager::init()
{
    ofRegisterMouseEvents(this);
    ofAddListener(ofEvents().update, this, &ofxINHIDManager::update);
    pointers.assign(1,ofxINHIDPointer());
    pointers.at(0).id = 0;
    is_pressed = -1;
    is_pressed_banged = false;
}

//  HID Mouse

void    ofxINHIDManager::mouseMoved(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = -1;
    pointers.at(0).set(arg.x, arg.y);
}

void    ofxINHIDManager::mouseDragged(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = arg.button;
    pointers.at(0).set(arg.x, arg.y);
}

void    ofxINHIDManager::mousePressed(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = arg.button;
    pointers.at(0).state = HIDPointerState_Pressed;
    pointers.at(0).frame_stamp = ofGetFrameNum();
    pointers.at(0).set(arg.x, arg.y);
}

void    ofxINHIDManager::mouseReleased(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = -1;
    is_pressed_banged = false;
    is_released = true;
    pointers.at(0).state = HIDPointerState_Released;
    pointers.at(0).frame_stamp = ofGetFrameNum();
}

void    ofxINHIDManager::mouseEntered(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = -1;
}

void    ofxINHIDManager::mouseExited(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = -1;
    pointers.at(0).state = HIDPointerState_Idle;
}

void    ofxINHIDManager::mouseScrolled(ofMouseEventArgs &arg)
{
    
}

void    ofxINHIDManager::update(ofEventArgs  &_args)
{
    for(auto &pointer : pointers)
    {
        switch (pointer.state) {
            case HIDPointerState_Released:
                pointer.state = ofGetFrameNum() > pointer.frame_stamp ? HIDPointerState_Idle : HIDPointerState_Released;
                break;
            case HIDPointerState_Pressed:
                pointer.state = ofGetFrameNum() > pointer.frame_stamp ? HIDPointerState_Idle : HIDPointerState_Pressed;
                break;
            default:
                break;
        }
    }
    
    x = pointers.at(0).x;
    y = pointers.at(0).y;
    
}

int     ofxINHIDManager::pressed()
{
    return is_pressed != -1;
}

bool   ofxINHIDManager::bang_pressed()
{
    bool ret = false;
    if(pressed() && !is_pressed_banged)
    {
        is_pressed_banged = true;
        ret = true;
    }
    return ret;
}

bool    ofxINHIDManager::bang_released()
{
    return pointers.at(0).state == HIDPointerState_Released;
}

vector<ofxINHIDPointer>*   ofxINHIDManager::get_pointers()
{
    return &pointers;
}
