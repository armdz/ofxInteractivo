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
#include "ofxJSON.h"

namespace ofxInteractivo  {
    
    class APP {
        
    public:
        static void init();
        
    private:
        static void    app_log(string _msg);
        
        static ofxJSONElement json_config;
        
    };
}



#endif /* ofxAPP_h */
