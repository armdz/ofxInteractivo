//
//  EMOscillator.cpp
//  dataViz
//
//  Created by Lolo on 8/27/15.
//
//

#include "EMOscillator.h"

EMOscillator::EMOscillator()
{
  acum = 0.0;
  vel = 0.0;
  value = 0.0;
  runing = false;
  offset = 0.0;;
}

EMOscillator::~EMOscillator()
{
  
}

void EMOscillator::setup(string _name,float  _vel,int  _type,float _offset)
{
  set_name(_name);
  vel = _vel;
  type = _type;
  offset = _offset;
  acum = 0.0;
}

void  EMOscillator::start()
{
  runing = true;
}

void  EMOscillator::stop()
{
  runing = false;
}

void EMOscillator::update()
{
  if(runing){
    value = type == EM::sin ? sin(offset+acum) : cos(offset+acum);
    acum+=vel;
  }
}

float EMOscillator::val()
{
  return value;
}