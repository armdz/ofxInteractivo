//
//  UIList.cpp
//  Cajas
//
//  Created by lolo on 12/4/16.
//
//

#include "UIList.hpp"

UIList::UIList()
{
  selected_item = -1;
}

UIList::~UIList()
{
  
}

void  UIList::init()
{
  set_obj_type(OBJ_UI_TYPE_LIST);
  min_width = 100.0;
  setWidth(min_width);
  setHeight(UI_MIN_NODE_HEIGHT);
 // set_draggable(true);
}

void  UIList::behavior()
{
  
  if(selected_item == -1){
    
    int i=0;
    while(i<button_items.size() && selected_item == -1)
    {
      if(button_items.at(i)->on_pressed())
      {
        selected_item = i;
      }
      i++;
    }
    
    if(selected_item != -1)
    {
      enable_childs(false); //  disable all childs for avoid "multiselection"
      
      UIEvents  item_evt = UIEvents();
      item_evt.type = UI_EVENT_LIST_SELECTED_ITEM;
      item_evt.source_name = button_items.at(selected_item)->get_name();
      item_evt.ui_object = button_items.at(selected_item);
      item_evt.info = button_items.at(selected_item)->get_info();
      ofNotifyEvent(UIEvents::events,item_evt);
    }
  }else{
    if(!ofGetMousePressed())
    {
      enable_childs(true);
      selected_item = -1;
    }
  }
  
}

void  UIList::draw()
{
  draw_childs();
}

void  UIList::parse(ofxJSONElement  _data)
{

  data = _data;
  //  first get the longer label to show, to get the width of the list
  float max_width = min_width;
  for(int i=0;i<data.size();i++)
  {
    max_width = max(max_width,VSUI::calculate_bbox(_data[i]["label"].asString()).getWidth());
  }
  setWidth(max_width+UI_FONT_SIZE*2.0);
  //
  for(int i=0;i<data.size();i++)
  {
    //  label,id
    ofxINUIButton  *button = new ofxINUIButton();
    button->setup(_data[i]["id"].asString(), _data[i]["label"].asString());
    button->set(0,0,getWidth(),getHeight());
    button->setY(getHeight()+(i*getHeight()));
    button->set_info(data[i]);
    add_child(button);
    button_items.push_back(button);
  }
  update();
  
}

void  UIList::clear()
{
  data.clear();
  clear_childs();
  button_items.clear();
}

ofxJSONElement  UIList::get_data()
{
  return data;
}

vector<ofxINUIButton*> UIList::get_items()
{
  return button_items;
}
  

