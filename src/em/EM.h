//
//  EM.h
//  EASY MOTION, prototype
//
//
//  Created by Lolo on 8/27/15.
//
//

#ifndef dataViz_EM_h
#define dataViz_EM_h

#include "EMConstants.h"
#include "ofMain.h"
#include "ofxJSON.h"

class EM
{
public:
  static int sin;
  static int cos;
  static int OUTPUT_WIDTH;
  static int OUTPUT_HEIGHT;
  static ofFbo  fbo;
  static ofFbo  fbo_final;
  
  static string bienalista;
    
  static  ofTrueTypeFont  font;
//  static  std::map<std::string, ofxFontStash> fonts;

  static void init_font();
  static void add_color(string _name,ofColor _color);
  static void add_color(string _name,int _color);
  static void add_model(string _name,string _path);

  static void add_font(string _name,string _path,float _size = 1.0f);
  static ofTrueTypeFont*  get_font(string _name);
  static ofRectangle      string_box(string _font_name,string _text);
  static void             string_centered(string _font_name,string _text);
  
  static ofColor      get_color(string _name);
  static ofColor      get_color(int _index);
  static ofColor      random_color();
  static int          color_count();
  
  static void         scan_images_for_global(string _where);
  static void         add_image(string _path,string _name);
  static ofImage&     image(string  _name,bool _global = false);
  static float        image_w(string  _name);
  static float        image_h(string  _name);
  static void         draw_image(string _name);
  
  static int          shape_count();
  static void         add_shape(ofPath _path);
  static ofPath       shape(int  _index);
  static ofPath       shape();
  
  static  ofxJSONElement      config;
  static  void        load();
  static  void        update();
  
  static  void        export_svg_to_png(string _file,string _output,int _width,int _height,float  _scale = 1.0f);
  
  static  float INPUT_X;
  static  float INPUT_Y;
  static  float P_INPUT_X;
  static  float P_INPUT_Y;
  static  ofVec2f DELTA_INPUT;
  static  bool  PRESSED;

  static  void  set_input_pos(float _x,float  _y);
  static  void  set_hand_presence(bool  _val);
  static  void  calculate_delta();

private:
  //static vector<ofColor> palette;
  
  
  
};

#endif
