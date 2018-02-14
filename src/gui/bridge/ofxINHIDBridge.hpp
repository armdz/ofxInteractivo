//
//  ofxINHIDBridge.hpp
//  development_interactivo
//
//  Created by Lolo on 13/02/2018.
//

//  this class work as bridge between the HID input class and the UI of the project

#ifndef ofxINHIDBridge_hpp
#define ofxINHIDBridge_hpp


#include "ofMain.h"
#include "ofxINHIDPointer.h"
#include "ofxINHIDEvent.h"

enum ofxINHIDBridgeMode
{
    HIDBridgeMode_Single,
    HIDBridgeMode_Multi
};

class ofxINHIDBridge {
    
public:
    ofxINHIDBridge();
    ~ofxINHIDBridge();
    void    setup(vector<ofxINHIDPointer> *_pointers);
    void    update();
    void    dispatch_move(ofxINHIDPointer    *_pointer);
    void    dispatch_pressed(ofxINHIDPointer    *_pointer);
    void    dispatch_released(ofxINHIDPointer    *_pointer);

private:
    ofxINHIDBridgeMode  mode;
    vector<ofxINHIDPointer> *pointers;
    
};

#endif /* ofxINHIDBridge_hpp */
