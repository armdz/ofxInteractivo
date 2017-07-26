//
//  ofxInteractivoHID.hpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#ifndef ofxInteractivoHID_h
#define ofxInteractivoHID_h

#include "ofMain.h"

class ofxInteractivoHID : public ofPoint{
    
public:
    ofxInteractivoHID();
    ~ofxInteractivoHID();
    void    init();
    void    mouseMoved(ofMouseEventArgs &arg);
    void    mouseDragged(ofMouseEventArgs &arg);
    void    mousePressed(ofMouseEventArgs &arg);
    void    mouseReleased(ofMouseEventArgs &arg);
    void    mouseEntered(ofMouseEventArgs &arg);
    void    mouseExited(ofMouseEventArgs &arg);
    void    mouseScrolled(ofMouseEventArgs &arg);
    int     pressed();
    bool    bang_pressed();
private:
    int     is_pressed;
    bool    is_pressed_banged;

};

#endif /* ofxInteractivoHID_h */
