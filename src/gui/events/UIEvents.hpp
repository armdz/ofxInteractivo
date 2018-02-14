//
//  UIEvents.hpp
//  Cajas
//
//  Created by lolo on 11/27/16.
//
//

#ifndef UIEvents_hpp
#define UIEvents_hpp

#include "UIConstants.h"
#include "ofxINUIObject.hpp"
#include "ofxJSON.h"


//  make custom event for every event type

class UIEvents : public ofEventArgs{
  
public:
  UIEvents();
  ~UIEvents();
  
  ofxINUIObject* ui_object;
  int         type;
  int         button; //  0 left,1 right
  
  string          source_name;
  ofxJSONElement  info;
  
  static ofEvent <UIEvents> events;

};
  


#endif /* UIEvents_hpp */
