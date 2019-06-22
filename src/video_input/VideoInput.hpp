//
//  VideoInput.hpp
//  development_interactivo
//
//  Created by Lolo on 11/16/17.
//

#ifndef VideoInput_hpp
#define VideoInput_hpp

#include "ofMain.h"
#include "ofxINUIObject.hpp"

namespace ofxInteractivo {

    class   VideoInput
    {
    public:
        VideoInput();
        ~VideoInput();
        virtual void    setup(string _name,int _width,int _height);
        void    update();
        void    draw();
        virtual void    init(){};
        virtual void    custom_update(){};
        virtual void    custom_draw(){};
    protected:
        int    input_width;
        int    input_height;
        
    };
    
};

#endif /* VideoInput_hpp */
