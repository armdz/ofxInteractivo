//
//  VideoInput.cpp
//  development_interactivo
//
//  Created by Lolo on 11/16/17.
//

#include "VideoInput.hpp"


VideoInput::VideoInput()
{
    
}

VideoInput::~VideoInput()
{
    
}

void    VideoInput::setup(string _name,int _width,int _height)
{
 //   GUIObject::setup(_name);
    input_width = _width;
    input_height = _height;
    init();
}

void    VideoInput::update()
{
    custom_update();
}

void    VideoInput::draw()
{
    custom_draw();
}

