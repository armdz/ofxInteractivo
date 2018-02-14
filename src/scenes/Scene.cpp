//
//  Scene.cpp
//  development_interactivo
//
//  Created by Lolo on 10/11/17.
//

#include "Scene.h"


Scene::Scene()
{

}

Scene::~Scene()
{
    clear();
}



void    Scene::update()
{
    ofxINUIObject::update();
    ofxINObject::update();
    custom_update();
}


