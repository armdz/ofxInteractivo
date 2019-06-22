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
    void    draw_file_list(float _x = 20.0f,float _y = 20.0f);
    vector<string>    read_dir();
    string  get_name();
    ofImage* get(string _image_name);
    float   get_width(string _image_name,float _scale = 1.0f);
    float   get_height(string _image_name,float _scale = 1.0f);
    float   width_for_height(string _image_name,float _height);
    float   height_for_width(string _image_name,float _width);
private:
    bool    exists(string _name);
    string  get_file_name(ofFile _file);
    string  name;
    string  dir_path;
    std::map<std::string, ofImage&> images;
    ofDirectory directory;
    int     file_count;
};

#endif /* ofxInteractivoImageLibrary */
