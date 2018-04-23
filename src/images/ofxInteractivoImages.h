//
//  ofxInteractivoImages.hpp
//  development_interactivo
//
//  Created by Lolo on 8/3/17.
//
//

#ifndef ofxInteractivoImages_h
#define ofxInteractivoImages_h

#include "ofMain.h"
#include "ofxInteractivoImageLibrary.h"
#define GLOBAL_LIBRARY_NAME "__global_imgs__"

class ofxInteractivoImages{
    
public:
    ofxInteractivoImages();
    ~ofxInteractivoImages();
    void    init();
    void    scan(string _folder_path,string _library_name);
    void    listen_start(string _library_name);
    void    listen_stop(string _library_name);
    //      drawing images
    void    draw_centered(ofImage &_image,float _scale = 1.0);
    //
    ofImage get(string _image_name);
    ofImage get(string _library_name,string _image_name);
    ofxInteractivoImageLibrary  get_library(string _library_name);
private:
    std::map<std::string, ofxInteractivoImageLibrary&> libraries;
    ofImage lost_image;
    //
    vector<ofxInteractivoImageLibrary*> listened_libraries;
    void    update(ofEventArgs &e);
    
};
#endif /* ofxInteractivoImages_h */
