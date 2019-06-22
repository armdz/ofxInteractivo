//
//  SceneManager.hpp
//  development_interactivo
//
//  Created by Lolo on 10/11/17.
//

#ifndef SceneManager_h
#define SceneManager_h

#include "Scene.h"
#include "GUIManager.hpp"
#include "ofxInteractivoConstants.h"
#include "ofxINHIDBridge.hpp"
#include "ofxINHIDPointer.h"

class SceneManager {
    
public:
    SceneManager();
    ~SceneManager();
    void    setup(vector<ofxINHIDPointer> *_hid_pointers);
    void    add(Scene *_scene);
    void    update(ofEventArgs  &_args);
    void    draw(ofEventArgs  &_args);
private:
    GUIManager      gui;
    ofxINHIDBridge  hid_bridge;
    map<string,Scene* >    scenes;
    
};


#endif /* SceneManager_h */
