//
//  Scene.cpp
//  development_interactivo
//
//  Created by Lolo on 10/11/17.
//

#include "Scene.h"


Scene::Scene()
{
    name = "";
}

Scene::~Scene()
{
    clear();
}

void    Scene::setup(string _name)
{
    name = _name;
    APP::image.scan("scenes/" + name, name);
    ofxINUIObject::setup(name);
}

void    Scene::pUpdate()
{
    ofxINUIObject::update();
    ofxINObject::update();
    update();
}

ofImage  Scene::image(string _name)
{
    return APP::image.get(name, _name);
}


