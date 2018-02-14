//
//  ofxXVideoInput.cpp
//  development_interactivo
//
//  Created by Lolo on 11/16/17.
//

#include "VideoInputManager.hpp"

namespace ofxInteractivo {

    VideoInputManager::VideoInputManager()
    {
        
    }
    
    VideoInputManager::~VideoInputManager()
    {
        
    }
    
    void    VideoInputManager::setup()
    {
        
    }
    
    void    VideoInputManager::update()
    {
        for(auto input : inputs)
            input.second->update();
    }
    
    void    VideoInputManager::draw()
    {
        for(auto input : inputs)
            input.second->draw();
    }
    
    void    VideoInputManager::add_input(VideoInput    *_new_input)
    {
      //  inputs.insert(std::pair<string, VideoInput*>(_new_input->get_name(),_new_input));
    }
    
}
