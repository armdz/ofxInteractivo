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
    ofxINUIObject::setup(name);
    APP::image.scan("scenes/" + name, name);

}

void    Scene::update()
{
    ofxINUIObject::update();
    ofxINObject::update();
    custom_update();
}

ofImage  Scene::image(string _name)
{
    return APP::image.get(name, _name);
}


