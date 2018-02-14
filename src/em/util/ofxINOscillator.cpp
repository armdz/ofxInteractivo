//
//  EMOscillator.cpp
//  dataViz
//
//  Created by Lolo on 8/27/15.
//
//

#include "ofxINOscillator.h"

ofxINOscillator::ofxINOscillator()
{
  acum = 0.0;
  vel = 0.0;
  value = 0.0;
  runing = false;
  offset = 0.0;;
}

ofxINOscillator::~ofxINOscillator()
{
  
}

void ofxINOscillator::setup(string _name,float  _vel,EMOSCType  _type,float _offset)
{
  set_name(_name);
  vel = _vel;
  type = _type;
  offset = _offset;
  acum = 0.0;
}

void  ofxINOscillator::start()
{
  runing = true;
}

void  ofxINOscillator::stop()
{
  runing = false;
}

void ofxINOscillator::update()
{
  if(runing){
    //value = type == EM::sin ? sin(offset+acum) : cos(offset+acum);
    acum+=vel;
  }
}

float ofxINOscillator::val()
{
  return value;
}
