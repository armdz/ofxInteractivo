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

}

void    ofxInteractivoSceneManager::update(ofEventArgs  &_args)
{
    
}

void    ofxInteractivoSceneManager::draw(ofEventArgs  &_args)
{
    
}
