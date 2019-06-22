//
//  UIConstants.cpp
//  Cajas
//
//  Created by lolo on 11/26/16.
//
//

#include "UIConstants.h"


ofTrueTypeFont  VSUI::font;

VSUI::VSUI()
{
}

VSUI::~VSUI()
{
  
}

void  VSUI::init()
{
  //font.load("font/menlo_regular.ttf",UI_FONT_SIZE,true,true,false,true);
}

ofRectangle  VSUI::calculate_bbox(string _text)
{
  return VSUI::font.getStringBoundingBox(_text, 0, 0);
}

bool VSUI::is_number(const std::string& s)
{
  double d;
  istringstream is(s);
  is >> d;
  return !is.fail() && is.eof();
}
  

