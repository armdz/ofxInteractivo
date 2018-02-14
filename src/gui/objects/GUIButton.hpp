//
//  GUIButton.hpp
//  Cajas
//
//  Created by lolo on 11/22/16.
//
//

#ifndef GUIButton_hpp
#define GUIButton_hpp

#include <stdio.h>
#include "ofxINUIObject.hpp"

class GUIButton : public ofxINUIObject {
public:
  GUIButton();
  ~GUIButton();
  void  setup(string _name,string _label);
  void  init();
  void  behavior();
  void  draw();
  
  bool  on_pressed();
private:
  string  label;
  bool  bang_pressed;
  bool  dispatch_bang;
  ofRectangle label_bbox;
};



#endif /* GUIButton_hpp */
