//
//  UIManager.hpp
//  Cajas
//
//  Created by lolo on 11/22/16.
//
//

#ifndef UIManager_hpp
#define UIManager_hpp

#include <stdio.h>
#include "UIConstants.h"
#include "GUIObject.hpp"
#include "UITextField.hpp"
#include "UIEvents.hpp"
#include "UIList.hpp"


namespace ofxInteractivo { namespace gui{
    
class GUIManager
{
public:
  GUIManager();
  ~GUIManager();
  void  setup();
  void  set_max_id(int _max_id);
  void  add(GUIObject *_object);
  void  update();
  void  draw();
  void  clear();
  
  GUIObject*  get_object_by(int _id);
  
  ofxJSONElement get_json();

private:
  void  on_mouse_pressed(ofMouseEventArgs &e);
  void  on_mouse_released(ofMouseEventArgs &e);
  void  on_mouse_dragged(ofMouseEventArgs &e);
  void  on_key_pressed(ofKeyEventArgs &e);
  void  clear_list_of_selection();
  int   get_object_index(GUIObject*  _object);
  
  int   focused_object_index;
  GUIObject  *focused_object;
  GUIObject  *selected_object;
  GUIObject  *to_delete_object;
  GUIObject  *dragging_object;

  vector<GUIObject*> objects;
  vector<GUIObject*> selected_objects;
  vector<int> selected_objects_indexs;

  float prev_click_time;
  
  ofPoint draggin_object_offset;
  int draggin_object_index;
  int selected_object_index;
  bool  can_select_objects;
  bool  delete_selected_object;
  ofPoint draggin_workspace_offset;
  ofPoint workspace_position;

  bool  draggin_worksspace_setted;

  
  void  add_in_order(GUIObject *_object);
  
  int   max_id;
  int   id_count;
  int   id_system_count;
    
};
    
}};

#endif /* UIManager_hpp */
