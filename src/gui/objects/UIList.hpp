//
//  UIList.hpp
//  Cajas
//
//  Created by lolo on 12/4/16.
//
//

#ifndef UIList_hpp
#define UIList_hpp

#include <stdio.h>
#include "ofxINUIObject.hpp"
#include "ofxJSON.h"
#include "GUIButton.hpp"
#include "UIEvents.hpp"


class UIList : public ofxINUIObject {
  
public:
  UIList();
  ~UIList();
  void  init();
  void  behavior();
  void  draw();
  void  parse(ofxJSONElement  _data);
  void  clear();
  vector<GUIButton*> get_items();
  ofxJSONElement  get_data();
private:
  ofxJSONElement  data;
  vector<GUIButton*> button_items;
  int selected_item;
  float min_width;
  
};


  
#endif /* UIList_hpp */
