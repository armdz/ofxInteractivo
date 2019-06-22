//
//  WebCamInput.hpp
//  development_interactivo
//
//  Created by Lolo on 11/16/17.
//

#ifndef WebCamInput_hpp
#define WebCamInput_hpp

#include "VideoInput.hpp"

namespace ofxInteractivo {
    
    class   WebCamInput : public VideoInput
    {
    public:
        WebCamInput();
        ~WebCamInput();
        void    setup(string _name,int _device_id,int _width,int _height);
        void    init();
        void    custom_update();
        void    custom_draw();
    private:
        int     device_id;
        ofVideoGrabber  grabber;
        
    };
    
}
#endif /* WebCamInput_hpp */
