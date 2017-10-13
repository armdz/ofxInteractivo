//
//  ofxInteractivoScene.hpp
//  development_interactivo
//
//  Created by Lolo on 10/11/17.
//

#ifndef ofxInteractivoScene_h
#define ofxInteractivoScene_h

#include "ofMain.h"
#include "EMObject.h"
#include "GUIObject.hpp"
#include "GUIButton.hpp"

using namespace ofxInteractivo::gui;

class ofxInteractivoScene : public GUIObject,protected EMObject{
    
public:
    ofxInteractivoScene();
    ~ofxInteractivoScene();
    void    setup(string _name);
    virtual void    on_show(){};  //  prev to show
    virtual void    on_hide(){};  //  prev to hide
    virtual void    reset(){};   //  called when is totally hided
    virtual void    custom_update(){};
    virtual void    draw(){};
    void    update();
private:
    
};

#endif /* ofxInteractivoScene_h */
