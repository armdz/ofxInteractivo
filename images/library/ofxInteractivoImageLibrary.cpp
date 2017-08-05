//
//  odxInteractivoImageLibrary.cpp
//  development_interactivo
//
//  Created by Lolo on 8/3/17.
//
//


#include "ofxInteractivoImageLibrary.h"

ofxInteractivoImageLibrary::ofxInteractivoImageLibrary()
{
    
}

ofxInteractivoImageLibrary::~ofxInteractivoImageLibrary()
{
    
    
}

void    ofxInteractivoImageLibrary::setup(string _name)
{
    name = _name;
}

void    ofxInteractivoImageLibrary::scan(string _dir_path)
{
    ofDirectory dir;
    dir.allowExt("jpg");
    dir.allowExt("png");
    dir.allowExt("jpg");
    dir.open(ofToDataPath(_dir_path));
    for(int i=0;i<dir.getFiles().size();i++)
    {
        add(dir.getFiles().at(i).getAbsolutePath());
    }
}

void    ofxInteractivoImageLibrary::add(string _image_path,string _name)
{
    ofImage *new_image;
    if(new_image->load(_image_path))
    {
        if(_name == "")
        {
            _name = _image_path.find_last_of(".");
        }
        images.insert(std::pair<string, ofImage& >(_name,*new_image));
        app_log("Added " +_name + " to " + name);
    }
}




