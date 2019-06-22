//
//  ofxINHIDEvent.hpp
//  development_interactivo
//
//  Created by Lolo on 13/02/2018.
//

#ifndef ofxINHIDEvent_h
#define ofxINHIDEvent_h

#include "ofMain.h"
#include "ofxINHIDPointer.h"

class ofxINHIDEvent : public ofEventArgs
{
public:
    ofxINHIDEvent();
    ~ofxINHIDEvent();
    
    static ofEvent <ofxINHIDEvent> move;
    static ofEvent <ofxINHIDEvent> pressed;
    static ofEvent <ofxINHIDEvent> released;

    ofxINHIDPointer pointer;
    
};


#endif /* ofxINHIDEvent_h */

