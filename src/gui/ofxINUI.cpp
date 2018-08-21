//
//  ofxINUI.cpp
//  Cajas
//
//  Created by lolo on 11/26/16.
//
//

#include "ofxINUI.h"


ofTrueTypeFont  ofxINUI::font;
ofxINUISkin			ofxINUI::skin;

ofxINUI::ofxINUI()
{
}

ofxINUI::~ofxINUI()
{
  
}

void  ofxINUI::init()
{
  //font.load("font/menlo_regular.ttf",UI_FONT_SIZE,true,true,false,true);
}

ofRectangle  ofxINUI::calculate_bbox(string _text)
{
  return ofxINUI::font.getStringBoundingBox(_text, 0, 0);
}

bool ofxINUI::is_number(const std::string& s)
{
  double d;
  istringstream is(s);
  is >> d;
  return !is.fail() && is.eof();
}
  

