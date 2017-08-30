//
//  APP.cpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#include "APP.h"
#include "ofxInteractivoConstants.h"

namespace ofxInteractivo  {
    
    // APP CONFIGS
    
    ofxJSONElement  APP::json_config;
    int APP::width;
    int APP::height;
    string APP::name;
    
    //  MODULES
    
    ofxInteractivoHID   APP::hid;
    ofxInteractivoFont  APP::font;
    ofxInteractivoColorPalette   APP::color;
    ofxInteractivoImages    APP::image;

    //  PUBLIC

    void    APP::init(string _name,int _output_width,int _output_height)
    {
        if(json_config.open("config.json")){
            if(json_config["config"] != Json::nullValue)
            {
                if(json_config["config"] != Json::nullValue){
                    json_config = json_config["config"];
                }
            }
        }else{
            //app_log("config.json doesnt exists");
        }
        //  app name
        name = _name;
        if(_output_width != 0 && _output_height != 0)
        {
            //  can get the resolution from config.json
            //  if not we can take from here
            width = _output_width;
            height = _output_height;
        }
        if(width == 0 || height == 0)
        {
            width = ofGetWidth();
            height = ofGetHeight();
        }
        //
        hid.init();
        image.init();
        
    }
    
    //
    
    ofxJSONElement  APP::config()
    {
        return json_config;
    }
    
    int     APP::config_i(string _key_name)
    {
        return json_config[_key_name].asInt();
    }
    
    float   APP::config_f(string _key_name)
    {
        return json_config[_key_name].asFloat();
    }
    
    string  APP::config_s(string _key_name)
    {
        return json_config[_key_name].asString();
    }

    
    //
    
    void    APP::push_center()
    {
        ofPushMatrix();
        ofTranslate(width*.5f, height*.5f);
    }
    
    void    APP::pop_center()
    {
        ofPopMatrix();
    }
    
    //  PRIVATES
  

};
