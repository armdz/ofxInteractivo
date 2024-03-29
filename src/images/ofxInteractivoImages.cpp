//
//  ofxInteractivoImages.cpp
//  development_interactivo
//
//  Created by Lolo on 8/3/17.
//
//

#include "ofxInteractivoImages.h"

ofxInteractivoImages::ofxInteractivoImages()
{

}

ofxInteractivoImages::~ofxInteractivoImages()
{
    
}

void    ofxInteractivoImages::init()
{
    //  In case of get a null image , return this image
    ofFbo   fbo_lost_image;
    fbo_lost_image.allocate(200,200,GL_RGB);
    fbo_lost_image.begin();
    ofBackground(255, 0, 0);
    ofSetColor(255);
    string text_lost = "IMAGE LOST";
    int corner_size = 15;
    ofDrawBitmapStringHighlight(text_lost, (fbo_lost_image.getWidth()*.5)-(text_lost.size()*8)*.5,fbo_lost_image.getHeight()*.5);
    ofSetColor(0);
    ofDrawRectangle(0, 0, corner_size, corner_size);
    ofDrawRectangle(fbo_lost_image.getWidth()-corner_size, 0, corner_size, corner_size);
    ofDrawRectangle(fbo_lost_image.getWidth()-corner_size, fbo_lost_image.getHeight()-corner_size, corner_size, corner_size);
    ofDrawRectangle(0, fbo_lost_image.getHeight()-corner_size,corner_size, corner_size);
    fbo_lost_image.end();
    fbo_lost_image.readToPixels(lost_image.getPixels());
    lost_image.update();
    fbo_lost_image.clear();
    //
    
    ofAddListener(ofEvents().update, this, &ofxInteractivoImages::update);
    
    //  get global images
    
    ofDirectory dir("global_imgs");
    if(dir.exists())
    {
        scan("global_imgs", GLOBAL_LIBRARY_NAME);
    }
}

void    ofxInteractivoImages::scan(string _folder_path,string _library_name)
{
    ofxInteractivoImageLibrary* new_library = new ofxInteractivoImageLibrary();
    new_library->setup(_library_name);
    new_library->scan(_folder_path);
    libraries.insert(std::pair<string, ofxInteractivoImageLibrary& >(_library_name,*new_library));
}

void    ofxInteractivoImages::listen_start(string _library_name)
{
    if(libraries.count(_library_name) != 0)
    {
        listened_libraries.push_back(&libraries.at(_library_name));
        app_log("Listening START " + _library_name);
    }
}

void    ofxInteractivoImages::listen_stop(string _library_name)
{
    int library_index = libraries.count(_library_name);
    if(library_index != 0)
    {
        listened_libraries.erase(listened_libraries.begin()+library_index);
        app_log("Listening STOP " + _library_name);
    }
}

//

void    ofxInteractivoImages::update(ofEventArgs &e)
{
    //  check the listened libraries
    for(int i=0;i<listened_libraries.size();i++)
    {
        vector<string>  new_files_in_dir = listened_libraries.at(i)->read_dir();
        if(new_files_in_dir.size() > 0)
        {
            for(int f=0;f<new_files_in_dir.size();f++)
            {
                ofFile  file = ofFile(new_files_in_dir.at(f));
                while(file.getSize() < 1);
                //  por que me agarra mal el archivo///
                listened_libraries.at(i)->add(file);
            }
        }
        new_files_in_dir.clear();
    }
    
}

//  SVG
//void    loadShapes(string _path,string _name);

void ofxInteractivoImages::loadShapes(string _path,string _name)
{
    
    ofxSVG  file;
    file.load(_path);
    
    shapes.insert(pair<string,ofxINSvg>(_name,ofxINSvg()));
    for(int i=0;i<file.getNumPath();i++)
    {
        shapes.at(_name).shapes.push_back(file.getPathAt(i));
    }
    
}


void    ofxInteractivoImages::dumpShapes(string _libName,vector<ofPath>   &_dest)
{
    for(int i=0;i<shapes.at(_libName).shapes.size();i++)
    {
        _dest.push_back(shapes.at(_libName).shapes.at(i));
    }
}

ofPath  ofxInteractivoImages::getShape(string _libName,int    _index)
{
    return shapes.at(_libName).shapes.at(_index);
}


//  Drawing

void    ofxInteractivoImages::draw_centered(ofImage &_image,float _scale)
{
    ofPushMatrix();
    ofScale(_scale,_scale);
    _image.draw(-_image.getWidth()*.5, -_image.getHeight()*.5);
    ofPopMatrix();
}




//

//  for global images, scope : all app
ofImage ofxInteractivoImages::get(string _image_name)
{
    return get(GLOBAL_LIBRARY_NAME,_image_name);
}

ofImage ofxInteractivoImages::get(string _library_name,string _image_name)
{
    
    //cout << _library_name << " " << _image_name << "    =    " << libraries.count(_library_name) << endl;
    
    if(libraries.count(_library_name) == 0){
        return lost_image;
    }else{
        ofImage *ptr = libraries.at(_library_name).get(_image_name);
        if(ptr == NULL)
        {
            return lost_image;
        }else{
            return *libraries.at(_library_name).get(_image_name);
        }
        ptr = NULL;
        delete ptr;
    }
}

ofxInteractivoImageLibrary  ofxInteractivoImages::get_library(string _library_name)
{
    return libraries.at(_library_name);
}

