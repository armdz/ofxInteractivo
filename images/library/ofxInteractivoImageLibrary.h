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
    void    add(string _image_path,string _name = "");
private:
    string  name;
    std::map<std::string, ofImage&> images;

};

#endif /* ofxInteractivoImageLibrary */
