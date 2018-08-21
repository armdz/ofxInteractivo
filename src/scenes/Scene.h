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
#include "ofxINUIButton.hpp"
#include "ofxINUIImageButton.hpp"
#include "ofxINUIComboColor.h"
#include "ofxINUISlider.h"

#include "ofxInteractivo.h"

class Scene : public ofxINUIObject,private ofxINObject{
    
public:
    Scene();
    ~Scene();
    void    setup(string _name);
    virtual void    onSetup(){};
    virtual void    on_show(){};  //  prev to show
    virtual void    on_hide(){};  //  prev to hide
    virtual void    reset(){};   //  called when is totally hided
    virtual void    update(){};
    virtual void    draw(){};
    ofImage image(string _name);
    void    pUpdate();
protected:
    string  name;
};

#endif /* Scene_h */
