//
//  ofxInteractivoScene.cpp
//  development_interactivo
//
//  Created by Lolo on 10/11/17.
//

#include "ofxInteractivoScene.h"

ofxInteractivoScene::ofxInteractivoScene()
{

}

ofxInteractivoScene::~ofxInteractivoScene()
{
    clear();
}

void    ofxInteractivoScene::setup(string _name)
{
    GUIObject::setup(_name);
    init();
}

void    ofxInteractivoScene::update()
{
    GUIObject::update();
    EMObject::update();
    custom_update();
}
