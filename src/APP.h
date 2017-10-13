//
//  APP.hpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#ifndef ofxAPP_h
#define ofxAPP_h

#include "ofMain.h"
#include "ofxInteractivoHID.h"
#include "ofxInteractivoFont.h"
#include "ofxInteractivoColorPalette.h"
#include "ofxInteractivoImages.h"
#include "ofxJSON.h"

namespace ofxInteractivo  {
    
    class APP {
        
    public:
        static void init(string _name,int _output_width = 0,int _output_height = 0);
        
        static ofxInteractivoHID   hid;
        static ofxInteractivoFont  font;
        static ofxInteractivoColorPalette   color;
        static ofxInteractivoImages image;
        
        static int  width,height;
        static string name;
        
        //  App config
        
        static  ofxJSONElement  config();
        static  int     config_i(string _key_name);
        static  float   config_f(string _key_name);
        static  string  config_s(string _key_name);
        
        //  APP events
        

        //  APP related functions
        
        static  void    background(ofColor _color);
        static  void    background(string   _color_name);

        static  void    push_center();
        static  void    pop_center();
        static  void    show_fps();

    private:
        
        static ofxJSONElement json_config;
        
    };
}



#endif /* ofxAPP_h */
