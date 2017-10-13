//
//  ofxInteractivoSceneManager.cpp
//  development_interactivo
//
//  Created by Lolo on 10/11/17.
//

#include "ofxInteractivoSceneManager.h"

ofxInteractivoSceneManager::ofxInteractivoSceneManager()
{
    
}

ofxInteractivoSceneManager::~ofxInteractivoSceneManager()
{
    
}

void    ofxInteractivoSceneManager::init()
{
    ofAddListener(ofEvents().update, this, &ofxInteractivoSceneManager::update);
    ofAddListener(ofEvents().draw, this, &ofxInteractivoSceneManager::draw);
    //  gui
    gui.setup();
}
void    ofxInteractivoSceneManager::add(ofxInteractivoScene *_scene)
{
    app_log("Added scene " + _scene->GUIObject::get_name());
    scenes.insert(std::pair<string,ofxInteractivoScene* >(_scene->GUIObject::get_name(),_scene));
}

void    ofxInteractivoSceneManager::update(ofEventArgs  &_args)
{
    gui.update();
    for(auto scene : scenes)
        scene.second->update();
}

void    ofxInteractivoSceneManager::draw(ofEventArgs  &_args)
{
    for(auto scene : scenes)
        scene.second->draw();
}
