//
//  HIDPointer.h
//  development_interactivo
//
//  Created by Lolo on 13/02/2018.
//

#ifndef HIDPointer_h
#define HIDPointer_h

#include "ofMain.h"

enum ofxINHIDPointerState
{
    HIDPointerState_Idle,
    HIDPointerState_Press,
    HIDPointerState_Pressed,
    HIDPointerState_Released
};

class ofxINHIDPointer {
    
public:
    ofxINHIDPointer(){
        state = HIDPointerState_Idle;
        frame_stamp = 0;
        x=px=y=py=0.0f;
    };
    ~ofxINHIDPointer(){
        
    };
    
    void    set(float _x,float _y)
    {
        px = x;
        py = y;
        x = _x;
        y = _y;
        angle = atan2(py-y,px-x);
    }
    
    ofxINHIDPointerState    state;
    ofPoint prev;
    float angle;
    float x,y;
    float px,py;
    int frame_stamp;
    int id;
};

#endif /* HIDPointer_h */
