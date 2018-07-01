//
//  EMInterpolator.cpp
//  dataViz
//
//  Created by Lolo on 8/27/15.
//
//

#include "ofxINInterpolator.h"

ofxINInterpolator::ofxINInterpolator()
{
    normalized_value = 0.0;
    value = 0.0;
    runing = false;
    do_loop = false;
    do_bang = false;
    reverse = false;
    started = false;
    init_value = 0.0;
    final_value = 0.0;
}

ofxINInterpolator::~ofxINInterpolator()
{

}

void  ofxINInterpolator::setup(string _name,float _init,float _final,float   _duration, float (*_type)(float,float,float,float),bool _loop)
{
    set_name(_name);
    type = _type;
    init_value = _init;
    final_value = _final;
    duration = _duration;
    duration_bkp = duration;
    normalized_value = 0.0;
    sample_norm = 0.0;
    started = false;
    value = 0.0f;
    runing = false;
    loop(_loop);
}

void  ofxINInterpolator::start()
{
    if(!started){
        started = true;
        reverse = false;
        runing = true;
        do_bang = false;
        sample_norm = normalized_value;
        duration = (1.0-sample_norm)*duration_bkp;
        time = ofGetElapsedTimef();
    }
}

void ofxINInterpolator::rewind()
{
    started = false;
    reverse = true;
    runing = true;
    do_bang = false;
    sample_norm = normalized_value;
    duration = sample_norm*duration_bkp;
    time = ofGetElapsedTimef();
}

void  ofxINInterpolator::stop()
{
    runing = false;
    started = false;
}

void  ofxINInterpolator::reset()
{
    normalized_value = 0.0;
    sample_norm = 0.0;
    value = 0.0;
    runing = false;
    do_bang = false;
    reverse = false;
    started = false;
}


void  ofxINInterpolator::loop(bool _val)
{
    do_loop = _val;
}

void  ofxINInterpolator::update()
{
    do_bang = false;
    if(runing)
    {
        float current_time = fabs(time-ofGetElapsedTimef());
        if(reverse)
        {
          normalized_value = sample_norm-type(current_time, 0.0, sample_norm, duration);
        }else{
          normalized_value = type(current_time, sample_norm, 1.0, duration);
        }
        normalized_value = ofClamp(normalized_value, 0.0, 1.0);
        if(current_time >= duration)
        {
          runing = false;
          normalized_value = reverse ? 0.0 : 1.0;
          do_bang = true;
          if(do_loop){
            start();
          }
        }
    }
}

void  ofxINInterpolator::setDuration(float _val)
{
    duration_bkp = duration = _val;
}

bool  ofxINInterpolator::bang()
{
    return do_bang;
}

float ofxINInterpolator::val()
{
    return normalized_value == 0.0 ? init_value : ofMap(normalized_value, 0.0, 1.0, init_value, final_value);
}

float ofxINInterpolator::normalized()
{
    return normalized_value;
}

bool  ofxINInterpolator::is_runing()
{
    return runing;
}
bool  ofxINInterpolator::is_reversed()
{
    return reverse;
}

