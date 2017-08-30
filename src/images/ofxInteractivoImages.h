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

class ofxInteractivoImages{
    
public:
    ofxInteractivoImages();
    ~ofxInteractivoImages();
    void    init();
    void    scan(string _folder_path,string _library_name);
    void    listen(string _library_name);
    ofImage get(string _library_name,string _image_name);
    ofxInteractivoImageLibrary  get(string _library_name);
private:
    std::map<std::string, ofxInteractivoImageLibrary&> libraries;
    ofImage lost_image;
    //
    vector<ofxInteractivoImageLibrary*> listened_libraries;
    void    update(ofEventArgs &e);
    
};
#endif /* ofxInteractivoImages_h */
