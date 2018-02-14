//
//  EMObject.h
//  dataViz
//
//  Created by Lolo on 8/27/15.
//  Easy motion its a set of classes to make more easy animate simple stuff
//
//

#ifndef __dataViz__EMObject__
#define __dataViz__EMObject__

#include <stdio.h>
#include "ofMain.h"
#include "ofxINTimer.h"
#include "ofxINInterpolator.h"
#include "ofxINOscillator.h"

class ofxINObject : protected ofxINAbstract
{
  
public:
    ofxINObject();
    ~ofxINObject();
    void  update();
    //  TIMER
    void  add_timer(string _name,float _duration,int _times = 1,bool _start = false);
    void  timer(string _name,float _duration,int _times = 1,bool _start = false);
    bool  bang_t(string _name);
    ofxINTimer&  timer(string _name);
    ofxINTimer&  get_timer(string _name);
    //  INTERPOLATOR
    void   add_interpolator(string  _name,float _duration,float _init,float _final,float (*_type)(float,float,float,float) = Linear::easeIn,bool  _loop = false,bool _start = false);
    void   interpolator(string _name,float _duration,float _init,float _final,float (*_type)(float,float,float,float) = Linear::easeIn,bool  _loop = false,bool _start = false);
    bool   bang_i(string _name);
    ofxINInterpolator& interpolator(string _name);
    ofxINInterpolator& get_interpolator(string _name);
    float  value_i(string   _name);
    
    //  OSCILLATOR
    void  osc(string _name,float  _vel,EMOSCType  _type = EM_OSC_SIN,float _offset = 0.0,bool  _start = false);
    ofxINOscillator& osc(string _name);
    //
    void    clear();
    void    set_enable(bool _val);
    bool    is_enabled();
protected:  
    //  TIMER
    void    update_timers();
    std::map<std::string, ofxINTimer& >  timers;
    //  INTERPOLATOR
    void    update_interpolators();
    std::map<std::string, ofxINInterpolator& >  interpolators;
    //  OSCILLATOR
    void    update_oscillators();
    std::map<std::string, ofxINOscillator& >  oscilators;
    //
    bool    enable;
};


#endif /* defined(__dataViz__EMObject__) */
