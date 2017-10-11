//
//  EMTimer.cpp
//  dataViz
//
//  Created by Lolo on 8/27/15.
//
//

#include "EMTimer.h"

EMTimer::EMTimer()
{
  is_runing = false;
  do_bang = false;
  times_counter = 0;
  norm_val = 0.0f;
}

EMTimer::~EMTimer()
{
  
}

void  EMTimer::setup(string _name,float  _duration,int  _times)
{
    set_name(_name);
    duration = _duration;
    times_limit = _times;
    norm_val = 0.0f;
}

void  EMTimer::start()
{
    is_runing = true;
    do_bang = false;
    times_counter = 0;
    norm_val = 0.0f;
    ellapsed = ofGetElapsedTimef();
}

void  EMTimer::stop()
{
    is_runing = false;
    do_bang = false;
    norm_val = 0.0f;
}

void  EMTimer::update()
{
    if(times_limit != -1 && (do_bang && times_counter == times_limit))
    {
        stop();
    }
    float _ellapsed = fabs(ellapsed-ofGetElapsedTimef());
    if(is_runing)
    {
        do_bang = false;
        if(_ellapsed >= duration)
        {
            ellapsed = ofGetElapsedTimef();
            do_bang = true;
            times_counter++;
        }
        norm_val = ofClamp(_ellapsed/duration,0.0f,1.0f);
    }else{
        norm_val = 0.0f;
    }
}

void  EMTimer::set_duration(float _duration)
{
    duration = _duration;
}

bool  EMTimer::bang()
{
    return do_bang;
}

bool  EMTimer::runing()
{
    return is_runing;
}

int   EMTimer::times()
{
    return times_counter;
}

float EMTimer::val()
{
    return norm_val;
}

float EMTimer::get_duration()
{
    return duration;
}
