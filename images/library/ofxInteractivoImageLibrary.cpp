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
        add(dir.getFiles().at(i));
    }
}

void    ofxInteractivoImageLibrary::add(ofFile _file,string _name)
{
    ofImage *new_image = new ofImage();
    if(new_image->load(_file.getAbsolutePath()))
    {
        if(_name == "")
        {
            _name = _file.getFileName().substr(0,_file.getFileName().find_last_of("."));
            
        }
        images.insert(std::pair<string, ofImage& >(_name,*new_image));
        app_log("Added " + _name + " to " + name);
    }
}

ofImage* ofxInteractivoImageLibrary::get(string _image_name)
{
    ofImage *ptr = NULL;
    if(images.count(_image_name) != 0){
        return &images.at(_image_name);
    }else{
        return ptr;
    }
    delete ptr;
}

//  Get images scaled bounds

float   ofxInteractivoImageLibrary::get_width(string _image_name,float _scale)
{
    return images.at(_image_name).getWidth()*_scale;
}

float   ofxInteractivoImageLibrary::get_height(string _image_name,float _scale)
{
    return images.at(_image_name).getHeight()*_scale;
}

//  Get width in scale for specific height

float   ofxInteractivoImageLibrary::width_for_height(string _image_name,float _height)
{
    ofImage *image = get(_image_name);
    if(image != NULL)
    {
        return (_height*image->getWidth())/image->getHeight();
    }else{
        return 0.0f;
    }
    delete image;
}

//  Get height in scale for specific width

float   ofxInteractivoImageLibrary::height_for_width(string _image_name,float _width)
{
    ofImage *image = get(_image_name);
    if(image != NULL)
    {
        return (_width*image->getHeight())/image->getWidth();
    }else{
        return 0.0f;
    }
    delete image;}

//  Draw

void    ofxInteractivoImageLibrary::draw_centered(string _image_name,float _scale)
{
    if(exists(_image_name))
    {
        ofPushMatrix();
        ofScale(_scale, _scale);
        images.at(_image_name).draw(-images.at(_image_name).getWidth()*.5,-images.at(_image_name).getHeight()*.5);
        ofPopMatrix();
    }
}

//  Private

bool    ofxInteractivoImageLibrary::exists(string _name)
{
    return images.count(_name);
}



