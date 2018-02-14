//
//  UITextField.hpp
//  Cajas
//
//  Created by lolo on 11/26/16.
//
//

#ifndef UITextField_hpp
#define UITextField_hpp

#include "ofxINUIObject.hpp"


enum
{
  CJS_TEXTFIELD_ALPHA,
  CJS_TEXTFIELD_NUMBERS
};

class UITextField : public ofxINUIObject {
  
public:
  UITextField();
  ~UITextField();
  void  init();
  void  behavior();
  void  draw();
  void  clear();
  void  set_min_bounds(float _w,float _h);
  void  set_selected(bool _val);
  void  select_text();
  void  set_text(string _text);
  void  enable(bool _val);
  void  set_type_numbers();
  void  set_type_alpha();
  bool  bang(); // end edit bang
  bool  change();
  ofRectangle text_bounding_box();
  string get_text();
private:
  void  on_key_pressed(ofKeyEventArgs &e);
  string  text;
  bool  text_change;
  bool  end_edit_bang;
  bool  has_change;
  bool  selected;
  bool  text_selected;
  bool  has_min_bounds;
  float cursor_blink_time;
  int   cursor_pos;
  bool  cursor_show;
  bool  cursor_pos_by_key;
  int   text_field_type;
  ofRectangle text_bbox;
  string  range;
};



#endif /* UITextField_hpp */
