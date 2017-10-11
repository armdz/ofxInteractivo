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

//

ofImage ofxInteractivoImages::get(string _library_name,string _image_name)
{
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

ofxInteractivoImageLibrary  ofxInteractivoImages::get(string _library_name)
{
    return libraries.at(_library_name);
}

