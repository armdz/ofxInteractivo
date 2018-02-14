//
//  ofxINHIDBridge.cpp
//  development_interactivo
//
//  Created by Lolo on 13/02/2018.
//

#include "ofxINHIDBridge.hpp"

ofxINHIDBridge::ofxINHIDBridge()
{
    
}

ofxINHIDBridge::~ofxINHIDBridge()
{
    
}

void    ofxINHIDBridge::setup(vector<ofxINHIDPointer> *_pointers)
{
    pointers = _pointers;
}

void    ofxINHIDBridge::update()
{
    for(auto pointer : *pointers)
    {
        
        dispatch_move(&pointer);
        
        switch (pointer.state) {
            case HIDPointerState_Pressed:
                dispatch_pressed(&pointer);
                break;
            case HIDPointerState_Released:
                dispatch_released(&pointer);
                break;
            default:
                break;
        }
    }
}

void    ofxINHIDBridge::dispatch_move(ofxINHIDPointer    *_pointer)
{
    ofxINHIDEvent   event;
    event.pointer = *_pointer;
    ofNotifyEvent(ofxINHIDEvent().move, event);
}

void    ofxINHIDBridge::dispatch_pressed(ofxINHIDPointer    *_pointer)
{
    ofxINHIDEvent   event;
    event.pointer = *_pointer;
    ofNotifyEvent(ofxINHIDEvent().pressed, event);
}

void    ofxINHIDBridge::dispatch_released(ofxINHIDPointer    *_pointer)
{
    ofxINHIDEvent   event;
    event.pointer = *_pointer;
    ofNotifyEvent(ofxINHIDEvent().released, event);
}




