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
		setEnable(true);
		onSetup();
}

void    Scene::pUpdate()
{
		ofxINUI::resetClickPropagation();
    ofxINUIObject::update();
    ofxINObject::update();
		if (ofxINUIObject::stopPropagate()) {
			ofxINUI::stopClickPropagation();
		}
    update();
}

ofImage  Scene::image(string _name)
{
    return APP::image.get(name, _name);
}


