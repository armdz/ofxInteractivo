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
#include "EMTimer.h"
#include "EMInterpolator.h"
#include "EMOscillator.h"

class EMObject : public EMAbstract
{
  
public:
    EMObject();
    ~EMObject();
    void  update();
    virtual void custom_update(){};   //  override
    //  TIMER
    void  add_timer(string _name,float _duration,int _times = 1,bool _start = false);
    void  timer(string _name,float _duration,int _times = 1,bool _start = false);
    bool  timer_bang(string _name);
    EMTimer&  timer(string _name);
    EMTimer&  get_timer(string _name);
    //  INTERPOLATOR
    void  interpolator(string _name,float _duration,float _init,float _final,float (*_type)(float,float,float,float) = Linear::easeIn,bool  _loop = false,bool _start = false);
    EMInterpolator& interpolator(string _name);
    void  add_interpolator(string  _name,float _duration,float _init,float _final,float (*_type)(float,float,float,float) = Linear::easeIn,bool  _loop = false,bool _start = false);
    EMInterpolator& get_interpolator(string _name);
    float interp_value(string   _name);

    //  OSCILLATOR
    void  osc(string _name,float  _vel,EMOSCType  _type = EM_OSC_SIN,float _offset = 0.0,bool  _start = false);
    EMOscillator& osc(string _name);
    //
    void    clear();
    void    set_enable(bool _val);
    bool    is_enabled();
protected:  
    //  TIMER
    void    update_timers();
    std::map<std::string, EMTimer& >  timers;
    //  INTERPOLATOR
    void    update_interpolators();
    std::map<std::string, EMInterpolator& >  interpolators;
    //  OSCILLATOR
    void    update_oscillators();
    std::map<std::string, EMOscillator& >  oscilators;
    //
    bool    enable;
};


#endif /* defined(__dataViz__EMObject__) */
