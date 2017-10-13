//
//  ofxInteractivoSceneManager.hpp
//  development_interactivo
//
//  Created by Lolo on 10/11/17.
//

#ifndef ofxInteractivoSceneManager_h
#define ofxInteractivoSceneManager_h

#include "ofxInteractivoScene.h"
#include "GUIManager.hpp"
#include "ofxInteractivoConstants.h"

using namespace ofxInteractivo::gui;

class ofxInteractivoSceneManager {
    
public:
    ofxInteractivoSceneManager();
    ~ofxInteractivoSceneManager();
    void    init();
    void    add(ofxInteractivoScene *_scene);
    void    update(ofEventArgs  &_args);
    void    draw(ofEventArgs  &_args);
private:
    GUIManager  gui;
    map<string,ofxInteractivoScene* >    scenes;
};


#endif /* ofxInteractivoSceneManager_h */
