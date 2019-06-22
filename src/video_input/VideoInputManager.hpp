//
//  VideoInputManager
//  development_interactivo
//
//  Created by Lolo on 11/16/17.
//

#ifndef VideoInputManager_hpp
#define VideoInputManager_hpp

#include "ofMain.h"
#include "VideoInput.hpp"

using namespace ofxInteractivo;
namespace ofxInteractivo {

class VideoInputManager {
    
public:
    VideoInputManager();
    ~VideoInputManager();
    void    setup();
    void    update();
    void    draw();
    void    add_input(VideoInput    *_new_input);
private:
    std::map<string,VideoInput*>  inputs;
};

}


#endif /* VideoInputManager_hpp */
