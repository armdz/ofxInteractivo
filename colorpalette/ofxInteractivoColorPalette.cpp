//
//  ofxInteractivoColoPalette.cpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#include "ofxInteractivoColorPalette.h"

ofxInteractivoColorPalette::ofxInteractivoColorPalette()
{
    
}

ofxInteractivoColorPalette::~ofxInteractivoColorPalette()
{
    
}

void ofxInteractivoColorPalette::add(string _name,ofColor _color)
{
    color_names.push_back(_name);
    palette.insert(std::pair<string, ofColor >(_name,_color));
}

void ofxInteractivoColorPalette::add(string _name,int _color)
{
    color_names.push_back(_name);
    ofColor _new_color;
    _new_color.setHex(_color);
    palette.insert(std::pair<string, ofColor >(_name,_new_color));
}

ofColor ofxInteractivoColorPalette::get(string _name)
{
    return palette.at(_name);
}

ofColor ofxInteractivoColorPalette::get(int _index)
{
    return palette.at(color_names.at(_index));
}

ofColor ofxInteractivoColorPalette::get_random()
{
    return palette.at(color_names.at((int)ofRandom(color_names.size())));
}

int     ofxInteractivoColorPalette::count()
{
    return palette.size();
}


