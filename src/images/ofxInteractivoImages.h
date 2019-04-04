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
#include "ofxSvg.h"
#define GLOBAL_LIBRARY_NAME "__global_imgs__"

struct  ofxINSvg
{
    string    name;
    vector<ofPath>  shapes;
};

class ofxInteractivoImages{
    
public:
    ofxInteractivoImages();
    ~ofxInteractivoImages();
    void    init();
    void    scan(string _folder_path,string _library_name);
    void    loadShapes(string _path,string _name);
    void    dumpShapes(string _libName,vector<ofPath>   &_dest);
    void    listen_start(string _library_name);
    void    listen_stop(string _library_name);
    //      drawing images
    void    draw_centered(ofImage &_image,float _scale = 1.0);
    //
<<<<<<< HEAD
    ofImage &get(string _image_name);
    ofImage &get(string _library_name,string _image_name);
=======
    ofImage get(string _image_name);
    ofImage get(string _library_name,string _image_name);
    ofPath  getShape(string _libName,int    _index);
    
>>>>>>> 72018f2dc077993af0e74c756862bd9771698f19
    ofxInteractivoImageLibrary  get_library(string _library_name);
private:
    std::map<std::string, ofxInteractivoImageLibrary&> libraries;
    std::map<std::string, ofxINSvg>     shapes;

    ofImage lost_image;
    //
    vector<ofxInteractivoImageLibrary*> listened_libraries;
    void    update(ofEventArgs &e);
    
};
#endif /* ofxInteractivoImages_h */
