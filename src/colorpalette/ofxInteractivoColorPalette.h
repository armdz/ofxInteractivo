//
//  ofxInteractivoColoPalette.hpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#ifndef ofxInteractivoColorPalette_h
#define ofxInteractivoColorPalette_h

#include "ofMain.h"

struct ofxINColorPalette
{
    string name;
    map<string,ofFloatColor> colors;
};


class ofxInteractivoColorPalette{
    
public:
    ofxInteractivoColorPalette();
    ~ofxInteractivoColorPalette();
    void add(string _name,ofColor _color);
    void add(string _name,int _color);
    void add(string _paletteName,string _colorName,ofFloatColor _newColor);
    void add(string _paletteName,string _colorName,int          _newColor);

    ofColor      get(string _name);
    ofFloatColor get(string _paletteName,string _colorName);
    ofFloatColor get(string _paletteName,int    _index);

    ofColor     get(int _index);
    ofColor     get_random();
    ofFloatColor    getRandomFrom(string _paletteName);
    int     count();
private:
    std::map<std::string, ofxINColorPalette>    palettes;
    std::map<std::string, ofColor> palette;
    vector<string> color_names;

};


#endif /* ofxInteractivoColorPalette_h */
