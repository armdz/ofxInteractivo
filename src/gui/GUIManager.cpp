//
//  GUIManager.cpp
//  Cajas
//
//  Created by lolo on 11/22/16.
//
//

#include "GUIManager.hpp"


GUIManager::GUIManager()
{
  
}

GUIManager::~GUIManager()
{
  
}

void  GUIManager::setup()
{
  
  VSUI::init();
  
  ofAddListener(ofEvents().mousePressed, this, &GUIManager::on_mouse_pressed);
  ofAddListener(ofEvents().mouseReleased, this, &GUIManager::on_mouse_released);
  ofAddListener(ofEvents().mouseDragged, this, &GUIManager::on_mouse_dragged);
  ofAddListener(ofEvents().keyPressed,this, &GUIManager::on_key_pressed);
  
  prev_click_time = ofGetElapsedTimeMillis();
  
  focused_object_index = -1;
  draggin_object_index = -1;
  selected_object_index = -1;
  draggin_object_offset = ofPoint(0.0,0.0);
  focused_object = NULL;
  dragging_object = NULL;
  selected_object = NULL;
  delete_selected_object = false;
  can_select_objects = false;
  draggin_worksspace_setted = false;
  
  max_id = 0; //this is util when load and save files, to preserve id, REVIEW
  id_system_count = 0;  //  for the system runs in negative
  
  workspace_position.set(0,0);
  draggin_workspace_offset.set(0,0);
  
}

void  GUIManager::set_max_id(int _max_id)
{
  max_id = _max_id;
  id_count = max_id;
}

void  GUIManager::add(ofxINUIObject *_object)
{
  add_in_order(_object);
}

void  GUIManager::add_in_order(ofxINUIObject *_object)
{
  if(_object->is_system_owned())
  {
    id_system_count--;
    _object->set_id(id_system_count);
  }else{
    if(_object->get_id() == -1)
    {
      id_count++;
      _object->set_id(id_count);
    }
  }
  //  objects.push_back(_object); // temporal fix to draw the library always on top
  objects.insert(objects.begin(), _object);
 
  if(selected_object != NULL){
    selected_object->set_selected(false);
    selected_object = NULL;
    selected_object_index = -1;
  }
  
}

void  GUIManager::update()
{

  
  //  delete objects
    /*
  if(delete_selected_object)
  {
    if(selected_objects.size() > 0)
    {
        
      while(selected_objects.size())
      {
        connection_manager.delete_connections_with_this_id(selected_objects.at(0)->get_id());
        int object_index = get_object_index(selected_objects.at(0));
        selected_objects.at(0)->set_selected(false);
        selected_objects.at(0)->destroy();
        objects.erase(objects.begin()+object_index);
        selected_objects.erase(selected_objects.begin());
      }
    }
    if(selected_object != NULL && selected_object_index != -1){
      selected_object->set_selected(false);
      int sel_index = get_object_index(selected_object);
      if(sel_index != -1){
        connection_manager.delete_connections_with_this_id(objects.at(sel_index)->get_id());
        objects.at(sel_index)->destroy();
        objects.erase(objects.begin()+sel_index);
      }
    }
    selected_object_index = -1;
    focused_object_index = -1;
    delete_selected_object = false;
    focused_object = NULL;
    selected_object = NULL;
    delete_selected_object = false;
  }*/
  
  if(dragging_object != NULL)
  {
    if(dragging_object->is_pressed()){
      dragging_object->setX(ofGetMouseX()-draggin_object_offset.x);
      dragging_object->setY(ofGetMouseY()-draggin_object_offset.y);
    }else{
      dragging_object = NULL;
    }
  }
  
  int object_index = 0;
  ofxINUIObject  *temp_focus_object = NULL;
  bool        some_on_focus = false;
  while(object_index < objects.size())
  {
    objects.at(object_index)->update();
      temp_focus_object = objects.at(object_index)->has_object_over();
      if(temp_focus_object != NULL)
      {
        some_on_focus = true;
        focused_object = temp_focus_object;
        focused_object_index = object_index;
      }
    
    object_index++;
  }
  if(!some_on_focus && focused_object != NULL){
    if(focused_object->is_idle() || (!focused_object->inside(ofGetMouseX(), ofGetMouseY()) && ofGetMousePressed())){
      focused_object = NULL;
      focused_object_index = -1;
    }
  }
  if(focused_object != NULL && dragging_object == NULL)
  {
    if(focused_object->is_draggable() && focused_object->is_pressed())
    {
      if(selected_objects.size() > 0)
      {
        if(!focused_object->is_selected())
        {
          clear_list_of_selection();
        }
      }
      selected_object = focused_object;
      selected_object->set_selected(true);
      selected_object_index = focused_object_index;
      dragging_object = focused_object;
      draggin_object_offset.x = fabs(dragging_object->x-ofGetMouseX());
      draggin_object_offset.y = fabs(dragging_object->y-ofGetMouseY());
    }
  }
 
}

void  GUIManager::draw()
{
  for(int i=0;i<objects.size();i++)
  {
    if(selected_object == NULL || (objects.at(i)->get_id() != selected_object->get_id()))
      objects.at(i)->draw();
  }
  if(selected_object != NULL)
    selected_object->draw();
  
  
  /*
  ofDrawBitmapStringHighlight(ofToString(objects.size()), 20,20);
  ofDrawBitmapStringHighlight("FOCUS :" + (focused_object == NULL ? "NULL" : focused_object->get_name()), 20,40);
  ofDrawBitmapStringHighlight("SELECTED :" + (selected_object == NULL ? "NULL" : selected_object->get_name()), 20,60);
    ofDrawBitmapStringHighlight("WPOS :" + (ofToString(workspace_position.x)+","+ofToString(workspace_position.y)), 20,80);*/
  
}

void  GUIManager::clear()
{
  

  vector<ofxINUIObject*> to_save;
  for(int i=0;i<objects.size();i++)
  {
    if(objects.at(i)->is_system_owned())
    {
      to_save.push_back(objects.at(i));
    }
  }
  objects.clear();
  for(int i=0;i<to_save.size();i++)
  {
    objects.push_back(to_save.at(i));
  }
  max_id = 0;
  id_count = 0;
  
}

ofxINUIObject*   GUIManager::get_object_by(int _id)
{
  ofxINUIObject* ret = NULL;
  int   i = 0;
  while(i<objects.size() && ret == NULL)
  {
    if(objects.at(i)->get_id() == _id)
    {
      ret = objects.at(i);
    }
    i++;
  }
  return ret;
}
  
int   GUIManager::get_object_index(ofxINUIObject*  _object)
{
  int   ret = -1;
  int   i = 0;
  while(i<objects.size() && ret == -1)
  {
    if(objects.at(i)->get_id() == _object->get_id())
    {
      ret = i;
    }
    i++;
  }
  return ret;
}

void  GUIManager::clear_list_of_selection()
{
  for(int i=0;i<selected_objects.size();i++){
    selected_objects.at(i)->set_selected(false);
    selected_objects.at(i) = NULL;
  }
  selected_objects.clear();
}

//  Generate JSON of the nodes to save files

ofxJSONElement  GUIManager::get_json()
{
  ofxJSONElement  ret_json;
  for(int i=0;i<objects.size();i++)
  {
    if(!objects.at(i)->is_system_owned()){
      if(objects.at(i)->get_parent() == NULL){
        ret_json.append(objects.at(i)->get_json());
      }
    }
  }
  return ret_json;
}

//

void  GUIManager::on_mouse_pressed(ofMouseEventArgs &e)
{
  
  if(e.button == 0)
  {
    UIEvents  ui_event;
    if(focused_object_index != -1)
    {
      ui_event.ui_object = objects.at(focused_object_index);
    }
    if(selected_object != NULL){
      selected_object->set_selected(false);
      selected_object = NULL;
    }
    
    if(ofGetElapsedTimeMillis()-prev_click_time<300 && focused_object == NULL){
      ui_event.button = e.button;
      ui_event.type = UI_EVENT_DOUBLE_CLICK;
      ofNotifyEvent(UIEvents::events, ui_event);
    }else{
      ui_event.button = e.button;
      ui_event.type = UI_EVENT_CLICK;
      ofNotifyEvent(UIEvents::events, ui_event);
      
      if(focused_object != NULL)
      {
        can_select_objects = false;
      }else{
        can_select_objects = true;
      }
     
      if(selected_objects.size() > 0)
      {
        if(focused_object == NULL)
        {
          clear_list_of_selection();
        }
      }
      
    }
    
    prev_click_time = ofGetElapsedTimeMillis();
  }
}
  
void  GUIManager::on_mouse_released(ofMouseEventArgs &e)
{
  draggin_worksspace_setted = false;

}
  
void  GUIManager::on_mouse_dragged(ofMouseEventArgs &e)
{
 /*
  if(e.button == 0){
    
    if(focused_object == NULL && can_select_objects){
      if(!selecting)
      {
        selecting = true;
        selection_area.set(e.x,e.y,0,0);
        selected_objects.clear();
      }else{
        selection_area.setWidth((e.x-selection_area.x));
        selection_area.setHeight((e.y-selection_area.y));
      }
    }else{
      if(selected_objects.size() > 0)
      {
        if(!set_drag_prev_pos){
          drag_prev_position.set(e.x,e.y);
          set_drag_prev_pos = true;
        }else{
          ofPoint move_amount(e-drag_prev_position);
          for(int i=0;i<selected_objects.size();i++)
          {
            selected_objects.at(i)->x+=move_amount.x;
            selected_objects.at(i)->y+=move_amount.y;
          }
        }
        
      }
      drag_prev_position.set(e.x,e.y);
    }
  }else if(e.button == 2)
  {
    if(!draggin_worksspace_setted)
    {
      draggin_workspace_offset.set(e.x,e.y);
      draggin_worksspace_setted = true;
    }else{
      ofPoint workspace_move_amount(e-draggin_workspace_offset);
      workspace_position+=workspace_move_amount;
      for(int i=0;i<objects.size();i++)
      {
        if(!objects.at(i)->is_system_owned())
        {
          objects.at(i)->x+=workspace_move_amount.x;
          objects.at(i)->y+=workspace_move_amount.y;
        }
      }
      
      
      draggin_workspace_offset.set(e.x,e.y);
    }
  }*/
  
}
  
void  GUIManager::on_key_pressed(ofKeyEventArgs &e)
{
  if(e.keycode == 259)
  {
    if((selected_object != NULL && selected_object->deletable()) || selected_objects.size() > 0)
    {
      delete_selected_object = true;
    }
  }
}
