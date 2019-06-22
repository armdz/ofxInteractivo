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
    file_count = 0;
}

void    ofxInteractivoImageLibrary::scan(string _dir_path)
{
    directory.allowExt("jpg");
    directory.allowExt("png");
    directory.allowExt("jpg");
    directory.open(ofToDataPath(_dir_path));
    for(int i=0;i<directory.getFiles().size();i++)
    {
        add(directory.getFiles().at(i));
    }
}

void    ofxInteractivoImageLibrary::add(ofFile _file,string _name)
{
    ofImage *new_image = new ofImage();
    if(new_image->load(_file.getAbsolutePath()))
    {
        if(_name == "")
        {
            _name = get_file_name(_file);
        }
        images.insert(std::pair<string, ofImage& >(_name,*new_image));
        file_count++;
        app_log("Added " + _name + " to " + name);
    }
}

//  Listen the folder waiting new files

vector<string>    ofxInteractivoImageLibrary::read_dir()
{
    vector<string>  new_files;
    if(file_count != directory.listDir())
    {
        for(int i=0;i<directory.listDir();i++)
        {
            string file_name = get_file_name(directory.getFile(i));
            if(!exists(file_name))
                new_files.push_back(directory.getFile(i).getAbsolutePath());
        }
    }
    return new_files;
}

void    ofxInteractivoImageLibrary::draw_file_list(float _x,float _y)
{
    ofDrawBitmapStringHighlight("Library : '" + name + "'",_x,_y);
    int index = 0;
    for(auto img : images)
    {
        ofSetColor(255);
        ofDrawBitmapStringHighlight(img.first, _x, _y+16+(16*index));
        index++;
    }
}

//

string  ofxInteractivoImageLibrary::get_name()
{
    return name;
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
    delete image;
    
}

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

//  Get file name without extension

string  ofxInteractivoImageLibrary::get_file_name(ofFile _file)
{
    return _file.getFileName().substr(0,_file.getFileName().find_last_of("."));
}



