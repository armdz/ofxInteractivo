//
//  HIDManager.hpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#ifndef HIDManager_h
#define HIDManager_h

#include "ofMain.h"
#include "ofxINHIDPointer.h"

class ofxINHIDManager : public ofPoint{
    
public:
    ofxINHIDManager();
    ~ofxINHIDManager();
    void    init();
    void    update(ofEventArgs  &_args);
    void    mouseMoved(ofMouseEventArgs &arg);
    void    mouseDragged(ofMouseEventArgs &arg);
    void    mousePressed(ofMouseEventArgs &arg);
    void    mouseReleased(ofMouseEventArgs &arg);
    void    mouseEntered(ofMouseEventArgs &arg);
    void    mouseExited(ofMouseEventArgs &arg);
    void    mouseScrolled(ofMouseEventArgs &arg);
    int     pressed();
    bool    bang_pressed();
    bool    bang_released();
    vector<ofxINHIDPointer> *get_pointers();
private:
    vector<ofxINHIDPointer> pointers;
    
    int     is_pressed;
    bool    is_pressed_banged;
    bool    is_released;
    bool    is_releassed_banged;

};

#endif /* HIDManager_h */
