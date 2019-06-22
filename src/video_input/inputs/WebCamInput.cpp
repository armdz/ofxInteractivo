//
//  WebCamInput.cpp
//  development_interactivo
//
//  Created by Lolo on 11/16/17.
//

#include "WebCamInput.hpp"

namespace ofxInteractivo {

        WebCamInput::WebCamInput()
        {
            device_id = -1;
        }

        WebCamInput::~WebCamInput()
        {
            
        }
    
        void    WebCamInput::setup(string _name,int _device_id,int _width,int _height)
        {
            device_id = _device_id;
            VideoInput::setup(_name, _width, _height);  // the rest go in init
        }

        void    WebCamInput::init()
        {
            grabber.setDeviceID(device_id);
            grabber.initGrabber(input_width, input_height);
        }

        void    WebCamInput::custom_update()
        {
            if(grabber.isInitialized())
            {
                grabber.update();
            }
        }

        void    WebCamInput::custom_draw()
        {
            if(grabber.isInitialized())
            {
                ofSetColor(255);
                grabber.draw(0,0);
            }
        }

}
