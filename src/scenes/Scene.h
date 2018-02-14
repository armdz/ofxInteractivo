//
//  Scene.hpp
//  development_interactivo
//
//  Created by Lolo on 10/11/17.
//

#ifndef Scene_h
#define Scene_h

#include "ofMain.h"
#include "ofxINObject.h"
#include "ofxINUIObject.hpp"
#include "GUIButton.hpp"

class Scene : public ofxINUIObject,private ofxINObject{
    
public:
    Scene();
    ~Scene();
    virtual void    on_show(){};  //  prev to show
    virtual void    on_hide(){};  //  prev to hide
    virtual void    reset(){};   //  called when is totally hided
    virtual void    custom_update(){};
    virtual void    draw(){};
    void    update();
protected:
    string  name;
};

#endif /* Scene_h */
