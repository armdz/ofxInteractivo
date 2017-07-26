//
//  APP.cpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#include "APP.h"

namespace ofxInteractivo  {
    
    ofxJSONElement  APP::json_config;
    
    void    APP::init(){
      
        if(json_config.open("config.json")){
            
        }else{
            app_log("config.json doesnt exists");
        }
        
    }
    
    //  PRIVATES
    
    void    APP::app_log(string _msg)
    {
        ofLogNotice() << "APP : " << _msg;
    }

};
