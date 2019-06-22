//
//  UITextField.cpp
//  Cajas
//
//  Created by lolo on 11/26/16.
//
//

#include "UITextField.hpp"


UITextField::UITextField()
{
  
}

UITextField::~UITextField()
{
}

void  UITextField::init()
{
  
  set_obj_type(OBJ_UI_TYPE_TEXTFIELD);  
  text = "";
  text_change = false; // use this to "end edit text" bang
  end_edit_bang = false;
  selected = false;
  text_selected = false;
  setWidth(100+UI_FONT_SIZE);
  setHeight(25);
  set_draggable(true);
  set_interactive(true);
  text_bbox.set(0,0,0,0);
  cursor_pos = 0;
  cursor_pos_by_key = false;
  cursor_blink_time = ofGetElapsedTimeMillis();
  has_min_bounds = false;
  text_field_type = CJS_TEXTFIELD_ALPHA;
  
}

void  UITextField::set_text(string _text)
{
  text = _text;
  text_selected = false;
  cursor_pos = text.size();
  text_bbox = VSUI::calculate_bbox(text);
}
  
void  UITextField::set_min_bounds(float _w,float _h)
{
  setWidth(_w);
  setHeight(_h);
  has_min_bounds=true;
}
  
void  UITextField::set_type_numbers()
{
  text_field_type = CJS_TEXTFIELD_NUMBERS;
}

void  UITextField::set_type_alpha()
{
  text_field_type = CJS_TEXTFIELD_ALPHA;
}
  
void  UITextField::enable(bool _val)
{
  ofxINUIObject::enable(_val);
  if(_val){
    cursor_show = true;
    cursor_blink_time = ofGetElapsedTimeMillis();
    ofAddListener(ofEvents().keyPressed, this, &UITextField::on_key_pressed);
  }else{
    ofRemoveListener(ofEvents().keyPressed, this, &UITextField::on_key_pressed);
  }
}

void  UITextField::behavior()
{
  if(selected)
  {
    if(fabs(cursor_blink_time-ofGetElapsedTimeMillis()) >= 500.0f)
    {
      cursor_blink_time = ofGetElapsedTimeMillis();
      cursor_show=!cursor_show;
    }
    
    if(ofGetMousePressed())
    {
      if(!inside(ofGetMouseX(), ofGetMouseY()))
      {
        selected = false;
      }else{
        text_selected = false;
      }
    }
  }
  
  if(is_pressed())
  {
    selected = true;
    cursor_pos_by_key = false;
    if(text_selected)
      text_selected = false;
  }

  if(end_edit_bang)
  {
    end_edit_bang = false;
  }
  if(text_change)
  {
    text_change = false;
  }
  
}

void  UITextField::draw()
{
  
  ofSetColor(VSUI_COLOR_IDLE);
  float view_width = has_min_bounds ? max(getWidth(),text_bbox.getWidth()+UI_FONT_SIZE*2) : text_bbox.getWidth()+UI_FONT_SIZE*2;
  ofDrawRectangle(x,y,view_width,getHeight());
  
  if(text_selected){
    ofPushStyle();
    ofSetColor(ofFloatColor(VSUI_COLOR_OVER.r,VSUI_COLOR_OVER.g,VSUI_COLOR_OVER.b,.5f));
    ofDrawRectangle(x,y,view_width,getHeight());
    ofPopStyle();
  }
  
  ofPushMatrix();
  ofTranslate(x+UI_FONT_SIZE/2, y+getHeight()-VSUI::font.getLineHeight()/2.0);
  ofSetColor(VSUI_COLOR_TEXT);
  VSUI::font.drawString(text, 0, 0);
  
  if(selected && cursor_show){
    ofSetColor(0);
    
    VSUI::font.drawString("|",text.size() == 0 ? 0 : (cursor_pos*(text_bbox.getWidth()/text.size()))-VSUI::font.getLetterSpacing()/2,0);
  }
  
  ofPopMatrix();

  if(selected)
  {
    ofPushStyle();
    ofNoFill();
    ofSetColor(0);
    ofDrawRectangle(x,y,view_width,getHeight());
    ofPopStyle();
  }
  
}

void  UITextField::clear()
{
  text = "";
  text_bbox = VSUI::calculate_bbox(text);
  end_edit_bang = false;
  text_change = false;
  cursor_pos_by_key = false;
  cursor_pos = 0;
  text_selected = false;
}

void  UITextField::on_key_pressed(ofKeyEventArgs &e)
{
  
  if(selected)
  {
    if(e.key == OF_KEY_BACKSPACE){
      if(text_selected)
      {
        text.clear();
        text_selected = false;
        text_change = true;
        cursor_pos = 0;
      }else{
        if(text.size() > 0){
          cursor_pos--;
          if(cursor_pos < 0)
            cursor_pos = 0;
          text.erase(text.begin()+(cursor_pos));
        }
        text_change = true;
      }
    }else if(e.key == OF_KEY_RETURN)
    {
      end_edit_bang = true;
    }else if(e.key == OF_KEY_RIGHT)
    {
      text_selected = false;
      cursor_pos_by_key = true;
      cursor_pos++;
      if(cursor_pos > (text.size()))
        cursor_pos = (text.size());
    }else if(e.key == OF_KEY_LEFT){
      text_selected = false;
      cursor_pos_by_key = true;
      cursor_pos--;
      if(cursor_pos < 0)
        cursor_pos = 0;
      
    }else{
      //  taked from https://github.com/rezaali/ofxUI/blob/master/src/ofxUITextInput.cpp
      //  :)
      switch (e.key) {
#if (OF_VERSION_MINOR > 7)
        case OF_KEY_TAB:
        case OF_KEY_COMMAND:
        case OF_KEY_CONTROL:
        case OF_KEY_LEFT_SHIFT:
        case OF_KEY_RIGHT_SHIFT:
        case OF_KEY_LEFT_CONTROL:
        case OF_KEY_RIGHT_CONTROL:
        case OF_KEY_LEFT_ALT:
        case OF_KEY_RIGHT_ALT:
        case OF_KEY_LEFT_SUPER:
        case OF_KEY_RIGHT_SUPER:
#endif
        case OF_KEY_F1:
        case OF_KEY_F2:
        case OF_KEY_F3:
        case OF_KEY_F4:
        case OF_KEY_F5:
        case OF_KEY_F6:
        case OF_KEY_F7:
        case OF_KEY_F8:
        case OF_KEY_F9:
        case OF_KEY_F10:
        case OF_KEY_F11:
        case OF_KEY_F12:
        case OF_KEY_PAGE_UP:
        case OF_KEY_PAGE_DOWN:
        case OF_KEY_HOME:
        case OF_KEY_END:
        case OF_KEY_INSERT:
        case OF_KEY_ALT:
        case OF_KEY_SHIFT:
          break;
        default:
          if(text_selected)
            clear();
          
          if(text_field_type == CJS_TEXTFIELD_ALPHA || (text_field_type == CJS_TEXTFIELD_NUMBERS && e.keycode >= 46 && e.keycode < 58)){
            string str_key = "";
            str_key+=(char)e.key;
            text.insert(text.begin()+cursor_pos, *str_key.c_str());
            text_change = true;
            cursor_pos++;
          }
          break;
      }
    }
    
    text_bbox = VSUI::calculate_bbox(text);
   
  }
  
  
}

void  UITextField::set_selected(bool _val)
{
  selected = _val;
}

void  UITextField::select_text()
{
  text_selected = true;
}
  
ofRectangle UITextField::text_bounding_box()
{
  return  text_bbox;
}

string UITextField::get_text()
{
  return text;
}

bool  UITextField::bang()
{
  return end_edit_bang;
}

bool  UITextField::change()
{
  return text_change;
}


