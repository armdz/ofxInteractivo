//
//  EMObject.cpp
//  dataViz
//
//  Created by Lolo on 8/27/15.
//
//

#include "EMObject.h"

EMObject::EMObject()
{
  enable = true;
}

EMObject::~EMObject()
{
  
}

void  EMObject::update()
{
  update_timers();
  update_interpolators();
  update_oscillators();
}


void  EMObject::clear()
{
  timers.clear();
  interpolators.clear();
  oscilators.clear();
}

//  TIMERS

void  EMObject::add_timer(string _name,float _duration,int _times,bool  _start)
{
  EMTimer* _new_timer = new EMTimer();
  _new_timer->setup(_name,_duration,_times);
  if(_start)  _new_timer->start();
  timers.insert(std::pair<string, EMTimer& >(_name,*_new_timer));
}

void  EMObject::timer(string _name,float _duration,int _times,bool  _start)
{
  add_timer(_name,_duration,_times,_start);
}

EMTimer& EMObject::timer(string _name)
{
  return timers.at(_name);
}

EMTimer& EMObject::get_timer(string _name)
{
  return timers.at(_name);
}

bool  EMObject::timer_bang(string _name)
{
  return get_timer(_name).bang();
}

void  EMObject::update_timers()
{
  
  for (auto timer=timers.begin(); timer != timers.end(); timer++)
  {
    timer->second.update();
  }
    
}

//  INTERPOLATORS

void  EMObject::interpolator(string  _name,float _duration,float _init,float _final,float (*_type)(float,float,float,float),bool  _loop,bool _start)
{
  add_interpolator(_name,_duration,_init,_final,_type,_loop,_start);
}

EMInterpolator& EMObject::interpolator(string _name)
{
  return get_interpolator(_name);
}

void  EMObject::add_interpolator(string  _name,float _duration,float _init,float _final,float (*_type)(float,float,float,float),bool  _loop,bool _start)
{
  EMInterpolator* _new_interpolator = new EMInterpolator();
  _new_interpolator->setup(_name, _init, _final, _duration,_type,_loop);
  interpolators.insert(std::pair<string, EMInterpolator& >(_name,*_new_interpolator));

  if(_start)
  {
    _new_interpolator->start();
  }
}

void  EMObject::update_interpolators()
{
  for (auto interpolator=interpolators.begin(); interpolator != interpolators.end(); interpolator++)
  {
    interpolator->second.update();
  }
}

float EMObject::interp_value(string   _name)
{
  return interpolators.at(_name).val();
}

EMInterpolator& EMObject::get_interpolator(string _name)
{
  return interpolators.at(_name);
}

//  OSCILLATOR

void  EMObject::update_oscillators()
{
  for (auto osc=oscilators.begin(); osc != oscilators.end(); osc++)
  {
    osc->second.update();
  }
}

void  EMObject::osc(string _name,float  _vel,int  _type,float _offset,bool  _start)
{
  EMOscillator* new_osc = new EMOscillator();
  new_osc->setup(_name,_vel,_type,_offset);
  oscilators.insert(std::pair<string, EMOscillator& >(_name,*new_osc));
  if(_start){
    new_osc->start();
  }
}

EMOscillator& EMObject::osc(string _name)
{
  return oscilators.at(_name);
}
