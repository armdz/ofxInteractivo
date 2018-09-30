//
//  SceneManager.cpp
//  development_interactivo
//
//  Created by Lolo on 10/11/17.
//

#include "SceneManager.h"


SceneManager::SceneManager()
{
    
}

SceneManager::~SceneManager()
{
    
}

void    SceneManager::setup(vector<ofxINHIDPointer> *_hid_pointers)
{
    ofAddListener(ofEvents().update, this, &SceneManager::update);
    ofAddListener(ofEvents().draw, this, &SceneManager::draw);
    hid_bridge.setup(_hid_pointers);
    //  gui
    gui.setup();
}
void    SceneManager::add(Scene *_scene)
{
    app_log("Added scene " + _scene->ofxINUIObject::getName());
    scenes.insert(std::pair<string,Scene* >(_scene->ofxINUIObject::getName(),_scene));
}

void    SceneManager::update(ofEventArgs  &_args)
{
    hid_bridge.update();
    gui.update();

    for(auto scene : scenes)
        scene.second->pUpdate();
}

void    SceneManager::draw(ofEventArgs  &_args)
{
    for(auto scene : scenes)
        scene.second->draw();
}

