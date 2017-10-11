//
//  ofxInteractivoScene.hpp
//  development_interactivo
//
//  Created by Lolo on 10/11/17.
//

#ifndef ofxInteractivoScene_h
#define ofxInteractivoScene_h

#include "ofMain.h"
#include "EMObject.h"

class ofxInteractivoScene : public EMObject{
    
public:
    ofxInteractivoScene();
    ~ofxInteractivoScene();
    void    setup(string _name);
    void    on_show();  //  prev to show
    void    on_hide();  //  prev to hide
    void    reset();    //  called when is totally hided
    void    custom_update();
    void    draw();
private:
    
};

#endif /* ofxInteractivoScene_h */
