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

class ofxInteractivoColorPalette{
    
public:
    ofxInteractivoColorPalette();
    ~ofxInteractivoColorPalette();
    void add(string _name,ofColor _color);
    void add(string _name,int _color);
    ofColor get(string _name);
    ofColor get(int _index);
    ofColor get_random();
    int     count();
private:
    std::map<std::string, ofColor> palette;
    vector<string> color_names;

};


#endif /* ofxInteractivoColorPalette_h */
