//
//  EMInterpolator.h
//  dataViz
//
//  Created by Lolo on 8/27/15.
//
//

#ifndef __dataViz__EMInterpolator__
#define __dataViz__EMInterpolator__

#include <stdio.h>
#include "ofxINAbstract.h"
#include "Quad.h"
#include "Quart.h"
#include "Quint.h"
#include "Sine.h"
#include "Linear.h"
#include "Expo.h"
#include "Elastic.h"
#include "Cubic.h"
#include "Circ.h"
#include "Bounce.h"
#include "Back.h"

class ofxINInterpolator : public ofxINAbstract {
  
public:
    ofxINInterpolator();
    ~ofxINInterpolator();
    void  setup(string _name,float _init,float _final,float   _duration,float (*_type)(float,float,float,float),bool _loop = false);
    void  start();
    void  rewind();
    void  stop();
    void  reset();
    void  loop(bool _val);
    void  update();
    bool  bang();
    float val();
    float normalized();
    bool  is_runing();
    bool  is_reversed();    //  means that its rewinding
private:
    float (*type)(float,float,float,float);
    bool  do_loop;
    bool  do_bang;
    bool  started;
    bool  runing;
    bool  reverse;
    float duration_bkp;
    float sample_norm;
    float duration;
    float time;
    float normalized_value;
    float value;
    float init_value;
    float final_value;
};

#endif /* defined(__dataViz__EMInterpolator__) */
