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

void    ofxINHIDManager::init(ofxINHIDType	_type)
{
    
    type = _type;
    ofAddListener(ofEvents().update, this, &ofxINHIDManager::update);
    is_pressed = -1;
    is_pressed_banged = false;
    if (type == INHID_Touch)
    {
        setup_touch();
    }else {
        ofRegisterMouseEvents(this);
        ofxINHIDPointer	mouse_pointer;
        mouse_pointer.id = 0;
        pointers.insert(std::pair<int, ofxINHIDPointer>(0, mouse_pointer));
    }
}

//  HID Mouse

void    ofxINHIDManager::mouseMoved(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = -1;
    pointers[0].set(arg.x, arg.y);
}

void    ofxINHIDManager::mouseDragged(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = arg.button;
    pointers[0].set(arg.x, arg.y);
}

void    ofxINHIDManager::mousePressed(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = arg.button;
    pointers[0].state = HIDPointerState_Pressed;
    pointers[0].frame_stamp = ofGetFrameNum();
    pointers[0].set(arg.x, arg.y);
}

void    ofxINHIDManager::mouseReleased(ofMouseEventArgs &arg)
{
    x = arg.x;
    y = arg.y;
    is_pressed = -1;
    is_pressed_banged = false;
    is_released = true;
    pointers[0].state = HIDPointerState_Released;
    pointers[0].frame_stamp = ofGetFrameNum();
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
    pointers[0].state = HIDPointerState_Idle;
}

void    ofxINHIDManager::mouseScrolled(ofMouseEventArgs &arg)
{
    
}

//	Touch

void		ofxINHIDManager::setup_touch()
{
	#ifdef TARGET_WIN32 || TARGET_WIN64

	//ofxWin8TouchSetup();

	#endif
    
    ofRegisterTouchEvents(this);

}

//#ifdef TARGET_WIN32 || TARGET_WIN64

void		ofxINHIDManager::touchDown(ofTouchEventArgs & touch)
{
	ofxINHIDPointer	new_pointer;
	new_pointer.id = touch.id;
    new_pointer.set(touch.x,touch.y);
	new_pointer.state = HIDPointerState_Pressed;
	new_pointer.frame_stamp = ofGetFrameNum();
	pointers.insert(std::pair<int, ofxINHIDPointer>(new_pointer.id, new_pointer));
}

void		ofxINHIDManager::touchMoved(ofTouchEventArgs & touch)
{
	pointers[touch.id].set(touch.x, touch.y);
}

void		ofxINHIDManager::touchUp(ofTouchEventArgs & touch)
{

	is_pressed = -1;
	is_pressed_banged = false;
	is_released = true;

	pointers[touch.id].state = HIDPointerState_Released;
	pointers[touch.id].frame_stamp = ofGetFrameNum();
}

void		ofxINHIDManager::touchDoubleTap(ofTouchEventArgs & touch)
{

}

void		ofxINHIDManager::touchCancelled(ofTouchEventArgs & touch)
{
	//pointers.erase(touch.id);
	is_pressed = -1;
	is_pressed_banged = false;
	is_released = true;

	pointers[touch.id].state = HIDPointerState_Released;
	pointers[touch.id].frame_stamp = ofGetFrameNum();
}

//#endif

//


void    ofxINHIDManager::update(ofEventArgs  &_args)
{

	//	Remove the unused pointers
    if(type == INHID_Touch){
        std::map<int, ofxINHIDPointer>::iterator it = pointers.begin();
        while (it != pointers.end()) {
            if (it->second.state == HIDPointerState_Idle) {
                it = pointers.erase(it);
            }
            else
                it++;
        }
    }
    
	//

	for (auto &pointer : pointers)
	{
		switch (pointer.second.state) {
		case HIDPointerState_Released:
			pointer.second.state = ofGetFrameNum() > pointer.second.frame_stamp ? HIDPointerState_Idle : HIDPointerState_Released;
			break;
		case HIDPointerState_Pressed:
			pointer.second.state = ofGetFrameNum() > pointer.second.frame_stamp ? HIDPointerState_Press : HIDPointerState_Pressed;
			break;
		default:
			break;
		}
	}
		
    if (type == INHID_Mouse && pointers.size() > 0) {
		x = pointers.at(0).x;
		y = pointers.at(0).y;
	}

	vec_pointers.clear();
	for (auto &pointer : pointers)
	{
		vec_pointers.push_back(pointer.second);
	}
    
}

void		ofxINHIDManager::draw()
{
	for (auto &pointer : pointers)
	{
		ofSetColor(255, 0, 0);
		ofDrawCircle(pointer.second.x, pointer.second.y, 50);
		ofSetColor(255);
		ofDrawBitmapStringHighlight(ofToString(pointer.second.id), pointer.second.x, pointer.second.y);
	}
	ofDrawBitmapStringHighlight(ofToString(pointers.size()),200,20);
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
    return pointers[0].state == HIDPointerState_Released;
}

vector<ofxINHIDPointer>*   ofxINHIDManager::get_pointers()
{
    return &vec_pointers;
}

ofxINHIDPointer             ofxINHIDManager::get_with_id(int _id)
{
    return pointers.at(_id);
}
