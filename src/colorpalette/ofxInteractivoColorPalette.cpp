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

void ofxInteractivoColorPalette::add(string _paletteName,string _colorName,ofFloatColor _newColor)
{
    if(palettes.count(_paletteName) == 0){
        palettes.insert(pair<string,ofxINColorPalette>(_paletteName,ofxINColorPalette()));
    }
    palettes.at(_paletteName).colors.insert(pair<string,ofFloatColor>(_colorName,_newColor));
}

void ofxInteractivoColorPalette::add(string _paletteName,string _colorName,int          _newColor)
{
    ofFloatColor    color;
    color.setHex(_newColor);
    add(_paletteName,_colorName,color);
}


ofFloatColor ofxInteractivoColorPalette::get(string _paletteName,string _colorName)
{
    return palettes.at(_paletteName).colors.at(_colorName);
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

ofFloatColor    ofxInteractivoColorPalette::getRandomFrom(string _paletteName)
{
    map<string,ofFloatColor>::iterator item = palettes.at(_paletteName).colors.begin();
    std::advance(item, (int)ofRandom(0,palettes.at(_paletteName).colors.size()));
    return item->second;
}

ofFloatColor ofxInteractivoColorPalette::get(string _paletteName,int    _index)
{
    map<string,ofFloatColor>::iterator item = palettes.at(_paletteName).colors.begin();
    std::advance(item, _index);
    return item->second;
}

int     ofxInteractivoColorPalette::count()
{
    return palette.size();
}


