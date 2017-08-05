//
//  odxInteractivoImageLibrary.hpp
//  development_interactivo
//
//  Created by Lolo on 8/3/17.
//
//

#ifndef ofxInteractivoImageLibrary_h
#define ofxInteractivoImageLibrary_h

#include "ofMain.h"
#include "ofxInteractivoConstants.h"

class ofxInteractivoImageLibrary
{
public:
    ofxInteractivoImageLibrary();
    ~ofxInteractivoImageLibrary();
    void    setup(string _name);
    void    scan(string _dir_path);
    void    add(ofFile _file,string _name = "");
    void    draw_centered(string _image_name,float _scale = 1.0f);
    ofImage* get(string _image_name);
private:
    string  name;
    std::map<std::string, ofImage&> images;
    bool    exists(string _name);
};

#endif /* ofxInteractivoImageLibrary */
