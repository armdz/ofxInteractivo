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

class ofxINHIDPointer : public ofPoint{
    
public:
    ofxINHIDPointer(){
        state = HIDPointerState_Idle;
        frame_stamp = 0;
    };
    ~ofxINHIDPointer(){
        
    };
    ofxINHIDPointerState    state;
    int frame_stamp;
    int id;
};

#endif /* HIDPointer_h */
