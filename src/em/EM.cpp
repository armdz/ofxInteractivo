//
//  EM.cpp
//  dataViz
//
//  Created by Lolo on 8/27/15.
//
//

#include "EM.h"

int EM::sin = 0;
int EM::cos = 1;
float EM::INPUT_X;
float EM::INPUT_Y;
float EM::P_INPUT_X;
float EM::P_INPUT_Y;
bool  EM::PRESSED = false;
ofVec2f EM::DELTA_INPUT = ofVec2f(0.0,0.0);
//static vector<ofColor> palette;
static std::map<std::string, ofTrueTypeFont* > fonts;
static std::map<std::string, ofImage&> images;
static std::map<std::string, ofColor> palette;


static vector<string> color_names;
static vector<ofPath> shapes;

string EM::bienalista = ""; //muy malo hacer esto...

ofFbo  EM::fbo;
ofFbo  EM::fbo_final;


int EM::OUTPUT_WIDTH  = 1280;
int EM::OUTPUT_HEIGHT = 640;

ofxJSONElement  EM::config;
ofTrueTypeFont  EM::font;

//  config

void  EM::load()
{
  bool  config_ok = config.open("config.json");
  //  typos

}

//  COLORS

void    EM::init_font()
{
}

ofColor EM::random_color()
{
 
 return palette.at(color_names.at((int)ofRandom(color_names.size())));
}

void  EM::add_color(string _name,ofColor _color)
{
  color_names.push_back(_name);
  palette.insert(std::pair<string, ofColor >(_name,_color));
}


void EM::add_color(string _name,int _color)
{
  ofColor _new_color;
  _new_color.setHex(_color,255.0);
  color_names.push_back(_name);
  palette.insert(std::pair<string, ofColor >(_name,_color));

}

int EM::color_count()
{
  return palette.size();
}

void  EM::add_font(string _name,string _path,float _size)
{
  ofTrueTypeFont*  _font = new ofTrueTypeFont();
  _font->load(_path, _size,true,true,true,false,96);
  fonts.insert(std::pair<string, ofTrueTypeFont* >(_name,_font));
}

ofTrueTypeFont*  EM::get_font(string _name)
{
  return fonts.at(_name);
}

ofRectangle EM::string_box(string _font_name,string _text)
{
  return fonts.at(_font_name)->getStringBoundingBox(_text, 0, 0);
}

void  EM::string_centered(string _font_name,string _text)
{
  ofRectangle rec = string_box(_font_name,_text);
  get_font(_font_name)->drawString(_text,-rec.getWidth()/2, rec.getHeight()/2);
}

ofColor  EM::get_color(int _index)
{
  return palette.at(color_names.at(_index));
}

ofColor  EM::get_color(string _name)
{
  return palette.at(_name);
}

void         EM::add_image(string _path,string _name)
{
  ofImage* _image = new ofImage();
  _image->load(_path);
  images.insert(std::pair<std::string,ofImage&>(_name,*_image));
}

void        EM::scan_images_for_global(string _where)
{
  ofDirectory dir;
  dir.allowExt("jpg");
  dir.allowExt("png");
  dir.allowExt("jpg");
  dir.open(ofToDataPath(_where));
  ofLogNotice() << "***** Scanning dir " << _where << endl;
  for(int i=0;i<dir.getFiles().size();i++)
  {
    string db_name = dir.getFiles().at(i).getFileName().substr(0, dir.getFiles().at(i).getFileName().find_last_of("."));
    
    EM::add_image(dir.getFiles().at(i).getAbsolutePath(), "global_"+db_name);
    
    
    
    ofLogNotice() << "Added to file " << dir.getFiles().at(i).getFileName() << " as " << db_name << endl;
  }
  ofLogNotice() << "***** ***** *****" << endl;
  
}

ofImage&     EM::image(string  _name,bool _global)
{
  if(_global)
    _name="global_"+_name;
  return images.at(_name);
}

float        EM::image_w(string  _name)
{
  return images.at(_name).getWidth();
}
float        EM::image_h(string  _name)
{
  return images.at(_name).getHeight();
}

void         EM::draw_image(string _name)
{
  ofImage img = images.at(_name);
  img.draw(-img.getWidth()/2, -img.getHeight()/2);
}

void         EM::add_shape(ofPath _path)
{
  shapes.push_back(_path);
}

ofPath      EM::shape(int  _index)
{
  return shapes.at(_index);
}

ofPath      EM::shape()
{
  int rnd = (int)ofRandom(0,shapes.size());
  return shapes.at(rnd);
}

int       EM::shape_count()
{
  return shapes.size();
}

void      EM::export_svg_to_png(string _file,string _output,int _width,int _height,float _scale)
{/*
  ofxSVG  svg;
  svg.load(_file);
  
  for(int i=0;i<svg.getNumPath();i++)
  {
    ofPath  path = svg.getPathAt(i);
    path.setPolyWindingMode(OF_POLY_WINDING_ODD);
    ofVec3f  position = path.getOutline().at(0).getCentroid2D();
    path.translate(ofPoint(-position.x,-position.y));
    
    float min_x,max_x,min_y,max_y = 0.0f;
    min_x = 9999.0f;
    min_y = 9999.0f;
    for(int j=0;j<path.getOutline().at(0).getVertices().size();j++)
    {
      min_x = min(min_x,path.getOutline().at(0).getVertices().at(j).x);
      max_x = max(max_x,path.getOutline().at(0).getVertices().at(j).x);
      min_y = min(min_y,path.getOutline().at(0).getVertices().at(j).y);
      max_y = max(max_y,path.getOutline().at(0).getVertices().at(j).y);
    }
    int width = (int)fabs(min_x-max_x);
    int height = (int)fabs(min_y-max_y);
    ofFbo fbo;
    fbo.allocate(width+width/4,height+width/4,GL_RGBA32F);
    fbo.begin();
    ofClear(0,0);
    ofPushMatrix();
    ofTranslate(fbo.getWidth()/2,fbo.getHeight()/2);
    ofScale(_scale,_scale);
    path.scale(1.0f,1.0f);
    path.setFillColor(ofColor(255));
    path.draw();
    ofPopMatrix();
    fbo.end();
    ofImage image_out;
    fbo.readToPixels(image_out.getPixels());
    image_out.save(_output+"/"+ofToString(i)+".png");
    
  }
  
  */
}

//  input

void  EM::set_input_pos(float _x,float  _y)
{
  
  P_INPUT_X = INPUT_X;
  P_INPUT_Y = INPUT_Y;
  INPUT_X = _x;
  INPUT_Y = _y;
  DELTA_INPUT.set(INPUT_X-P_INPUT_X,INPUT_Y-P_INPUT_Y);

}

void  EM::update()
{
  //DELTA_INPUT.set(INPUT_X-P_INPUT_X,INPUT_Y-P_INPUT_Y);
}

void  EM::set_hand_presence(bool  _val)
{
 
}
void  EM::calculate_delta()
{
}

