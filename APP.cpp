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
    
    //  MODULES
    
    ofxInteractivoHID   APP::hid;
    ofxInteractivoFont  APP::font;
    ofxInteractivoColorPalette   APP::color;

    //  PUBLIC
    
    void    APP::init(int _output_width,int _output_height)
    {
        if(json_config.open("config.json")){
            if(json_config["config"] != Json::nullValue)
            {
                json_config = json_config["config"];
            }
        }else{
            //app_log("config.json doesnt exists");
        }
        if(_output_width != 0 && _output_height != 0)
        {
            //  can get the resolution from config.json
            //  if not we can take from here
            width = _output_width;
            height = _output_height;
        }
        //
        hid.init();
        
    }
    
    //  PRIVATES
  

};
