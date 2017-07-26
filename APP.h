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
#include "ofxInteractivoFont.h"
#include "ofxInteractivoColorPalette.h"
#include "ofxJSON.h"

namespace ofxInteractivo  {
    
    class APP {
        
    public:
        static void init();
        
        static ofxInteractivoFont  font;
        static ofxInteractivoColorPalette   color;
    private:
        
        static ofxJSONElement json_config;
        
    };
}



#endif /* ofxAPP_h */
