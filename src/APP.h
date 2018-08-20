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
#include "ofxINHIDManager.h"
#include "ofxInteractivoFont.h"
#include "ofxInteractivoColorPalette.h"
#include "ofxInteractivoImages.h"
#include "VideoInputManager.hpp"
#include "ofxJSON.h"

class APP {
    
public:
    static void init(string _name,int _output_width = 0,int _output_height = 0,bool	 _touch = false);
    static ofxINHIDManager              hid;
    static ofxInteractivoFont           font;
    static ofxInteractivoColorPalette   color;
    static ofxInteractivoImages         image;
    static VideoInputManager    video_input;
    
    static int  width,height;
    static string name;
    
    //  App config
    
    static  ofxJSONElement  config();
    static  int     getInt(string _name);
    static  float   getFloat(string _name);
    static  string  getString(string _name);
    
    static  void    setInt(string _name,int _val);
    static  void    setFloat(string _name,float _val);
    static  void    setString(string _name,string _val);
    
    //  APP events
    

    //  APP related functions
    
    static  void    background(ofColor _color);
    static  void    background(string   _color_name);

    static  void    pushCenter();
    static  void    popCenter();
    static  void    showFps();
    
    static  void    setPropertie(string _id,float _val);
    static  float   getPropertie(string _id);
    static  map<string,float>   floatProperties;

private:
    
    static ofxJSONElement json_config;
    
};




#endif /* ofxAPP_h */
