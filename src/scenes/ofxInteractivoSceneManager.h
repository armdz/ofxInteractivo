//
//  ofxInteractivoSceneManager.hpp
//  development_interactivo
//
//  Created by Lolo on 10/11/17.
//

#ifndef ofxInteractivoSceneManager_h
#define ofxInteractivoSceneManager_h

#include "ofxInteractivoScene.h"

class ofxInteractivoSceneManager {
    
public:
    ofxInteractivoSceneManager();
    ~ofxInteractivoSceneManager();
    void    init();
    void    update(ofEventArgs  &_args);
    void    draw(ofEventArgs  &_args);

};


#endif /* ofxInteractivoSceneManager_h */
