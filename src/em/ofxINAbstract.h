//
//  EMAbstract.h
//  dataViz
//
//  Created by Lolo on 8/27/15.
//
//

#ifndef dataViz_EMAbstract_h
#define dataViz_EMAbstract_h

#include "ofMain.h"

class ofxINAbstract {
  
public:
    ofxINAbstract(){};
    ~ofxINAbstract(){};
    bool    runing;
protected:
    void    set_name(string _name){
        name = _name;
    };
    string  getName()
    {
        return name;
    };
    string  name;
  
};

#endif
