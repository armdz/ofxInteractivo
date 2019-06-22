//
//  EMObject.cpp
//  dataViz
//
//  Created by Lolo on 8/27/15.
//
//

#include "ofxINObject.h"

ofxINObject::ofxINObject()
{
  enable = true;
}

ofxINObject::~ofxINObject()
{
    clear();
}

void    ofxINObject::update()
{
    if(enable){
        update_timers();
        update_interpolators();
        update_oscillators();
    }
}


void    ofxINObject::clear()
{
    timers.clear();
    interpolators.clear();
    oscilators.clear();
}

void    ofxINObject::set_enable(bool _val)
{
    enable = _val;
}

//  TIMERS

void    ofxINObject::add_timer(string _name,float _duration,int _times,bool  _start)
{
    ofxINTimer* _new_timer = new ofxINTimer();
    _new_timer->setup(_name,_duration,_times);
    if(_start)  _new_timer->start();
    timers.insert(std::pair<string, ofxINTimer& >(_name,*_new_timer));
}

void    ofxINObject::timer(string _name,float _duration,int _times,bool  _start)
{
    add_timer(_name,_duration,_times,_start);
}

ofxINTimer& ofxINObject::timer(string _name)
{
    return timers.at(_name);
}

ofxINTimer& ofxINObject::get_timer(string _name)
{
    return timers.at(_name);
}

bool  ofxINObject::bang_t(string _name)
{
    return get_timer(_name).bang();
}

void  ofxINObject::update_timers()
{
    for (auto timer=timers.begin(); timer != timers.end(); timer++)
    {
        timer->second.update();
    }
}

//  INTERPOLATORS

void  ofxINObject::interpolator(string  _name,float _duration,float _init,float _final,float (*_type)(float,float,float,float),bool  _loop,bool _start)
{
    add_interpolator(_name,_duration,_init,_final,_type,_loop,_start);
}

ofxINInterpolator& ofxINObject::interpolator(string _name)
{
    return get_interpolator(_name);
}

void  ofxINObject::add_interpolator(string  _name,float _duration,float _init,float _final,float (*_type)(float,float,float,float),bool  _loop,bool _start)
{
    ofxINInterpolator* _new_interpolator = new ofxINInterpolator();
    _new_interpolator->setup(_name, _init, _final, _duration,_type,_loop);
    interpolators.insert(std::pair<string, ofxINInterpolator& >(_name,*_new_interpolator));
    if(_start)
    {
        _new_interpolator->start();
    }
}

void  ofxINObject::update_interpolators()
{
    for (auto interpolator=interpolators.begin(); interpolator != interpolators.end(); interpolator++)
    {
      interpolator->second.update();
    }
}

float ofxINObject::value_i(string   _name)
{
    return interpolators.at(_name).val();
}

bool    ofxINObject::bang_i(string _name)
{
    return interpolators.at(_name).bang();
}


ofxINInterpolator& ofxINObject::get_interpolator(string _name)
{
    return interpolators.at(_name);
}

//  OSCILLATOR

void  ofxINObject::update_oscillators()
{
    for (auto osc=oscilators.begin(); osc != oscilators.end(); osc++)
    {
        osc->second.update();
    }
}

void  ofxINObject::osc(string _name,float  _vel,EMOSCType  _type,float _offset,bool  _start)
{
    ofxINOscillator* new_osc = new ofxINOscillator();
    new_osc->setup(_name,_vel,_type,_offset);
    oscilators.insert(std::pair<string, ofxINOscillator& >(_name,*new_osc));
    if(_start){
        new_osc->start();
    }
}

ofxINOscillator& ofxINObject::osc(string _name)
{
    return oscilators.at(_name);
}

//

bool    ofxINObject::is_enabled()
{
    return enable;
}
