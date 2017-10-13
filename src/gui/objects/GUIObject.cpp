//
//  GUIObject.cpp
//  Cajas
//
//  Created by lolo on 11/22/16.
//
//

#include "GUIObject.hpp"

namespace ofxInteractivo { namespace gui{

    GUIObject::GUIObject()
    {
      
    }

    GUIObject::~GUIObject()
    {
      
    }

    void  GUIObject::setup(string _name)
    {
      name = _name;
      is_enable = true;
      visible = true;
      system_owned = false;
      mouse_press_state = false;
      id = -1;
      //
      layer = 0;
      status = GUIOBJECT_IDLE;
      draggable = false;
      is_deletable = true;
      parent = NULL;
      object_over = NULL;
      obj_type = "";
      set_interactive(false);
      prev_click_time = ofGetElapsedTimeMillis(); //for double click
      do_double_click = false;
      child_index_to_delete = -1;
      init();
    }
    
    void  GUIObject::destroy()
    {
      name = "";
      obj_type = "";
      parent = NULL;
      object_over = NULL;
      for(int i=0;i<get_childs().size();i++)
      {
        get_childs().at(i)->destroy();
        //delete get_childs().at(i);
      }
      clear_childs();
    }

    void  GUIObject::set_name(string _name)
    {
      name = _name;
    }

    void  GUIObject::set_layer(int _layer)
    {
      layer = _layer;
    }

    void  GUIObject::set_id(int _id)
    {
      id = _id;
    }

    void  GUIObject::set_parent(GUIObject  *_parent)
    {
      parent = _parent;
      draggable = false;
      //set_layer(1);
      initial_pos = ofPoint(x,y);
    }

    void  GUIObject::set_draggable(bool  _val)
    {
      if(parent == NULL){
        draggable = _val;
      }else{
        draggable = false;
        ofLogNotice() << "Object with parent can not be dragged";
      }
    }

    void  GUIObject::update()
    {
        
      behavior(); //  correct this order
      
      if(is_enable){
        
        if(interactive){
          
          if(do_double_click)
            do_double_click = false;
          
          if(status == GUIOBJECT_RELEASED)
          {
            status = GUIOBJECT_IDLE;
          }
          
          if(status == GUIOBJECT_PRESS)
          {
              if(!APP::hid.pressed())
            {
              status = GUIOBJECT_RELEASED;
            }
          }
       
          if(status != GUIOBJECT_PRESS){
              if(inside(ofPoint(APP::hid.x,APP::hid.y)))
            {
              status = GUIOBJECT_OVER;
            }else{
              status = GUIOBJECT_IDLE;
            }
          }
          
          if(status == GUIOBJECT_OVER)
          {
              if(APP::hid.pressed() /*&& !mouse_press_state*/)
            {
              status = GUIOBJECT_PRESS;
              if(ofGetElapsedTimeMillis()-prev_click_time<300){
                do_double_click = true;
              }
              prev_click_time = ofGetElapsedTimeMillis();
            }
          }
        }else{
          status = GUIOBJECT_IDLE;

        }
      
        update_childs();
        if(parent != NULL){
          setX(parent->x+initial_pos.x);
          setY(parent->y+initial_pos.y);
        }
      }else{
        status = GUIOBJECT_IDLE;
      }
        mouse_press_state = APP::hid.pressed();
    }

    void  GUIObject::update_childs()
    {
      if(is_enable){
        for(int i=0;i<childs.size();i++)
        {
          childs.at(i)->update();
        }
      }
    }

    void  GUIObject::childs_behavior()
    {
      if(is_enable){
        for(int i=0;i<childs.size();i++)
        {
          childs.at(i)->behavior();
        }
      }
    }


    void  GUIObject::draw()
    {
      
      if(visible){
        ofSetColor(VSUI_COLOR_IDLE);
        ofDrawRectangle(*this);
        draw_childs();
      }

    }

    void  GUIObject::draw_childs()
    {
      if(visible){
        for(int i=0;i<childs.size();i++)
        {
          childs.at(i)->draw();
        }
      }
    }

    void  GUIObject::clear_childs()
    {
      childs.clear();
    }

    void  GUIObject::set_visible(bool _val)
    {
      visible = _val;
    }

    void  GUIObject::set_obj_type(string _type)
    {
      obj_type = _type;
    }

    void  GUIObject::add_child(GUIObject* _child)
    {
      _child->set_parent(this);
      _child->initial_pos.set(_child->getX(), _child->getY());
      _child->setX(x+_child->initial_pos.x);
      _child->setY(y+_child->initial_pos.y);
      _child->set_layer(childs.size()+1);
      childs.push_back(_child);
    }

    void  GUIObject::remove_child(GUIObject* _child)
    {
      int   i = 0;
      int   found = -1;
      while(i<childs.size() && found == -1)
      {
        if(childs.at(i)->get_name() == _child->get_name())
        {
          found = i;
        }
        i++;
      }
      
      if(found != -1)
      {
        childs.erase(childs.begin()+found);
        child_index_to_delete = -1;
      }
    }

    void  GUIObject::enable(bool _val)
    {
      is_enable = _val;
    }
    
    void  GUIObject::enable_childs(bool  _val)
    {
      for(int i=0;i<childs.size();i++)
        childs.at(i)->enable(_val);
    }

    void  GUIObject::set_info(ofxJSONElement _info)
    {
      info = _info;
    }

    void  GUIObject::set_system_owned()
    {
      system_owned = true;
    }

    void  GUIObject::set_interactive(bool _val)
    {
      interactive = _val;
    }
    
    void  GUIObject::set_deleteable(bool _val)
    {
      is_deletable = _val;
    }
    
    
    void  GUIObject::set_selected(bool _val)
    {
      selected = _val;
    }

    
    string  GUIObject::print_status()
    {
      string _status = "";
      switch(status)
      {
        case 0:
          _status = "IDLE";
          break;
        case 1:
          _status = "OVER";
          break;
        case 2:
          _status = "PRESS";
          break;
        case 3:
          _status = "RELEASED";
          break;
      }
      ofLogNotice() << get_name() << " status " << _status << endl;
    }
    

    bool  GUIObject::is_visible()
    {
      return visible;
    }

    bool  GUIObject::is_enabled()
    {
      return is_enable;
    }
    
    bool  GUIObject::is_selected()
    {
      return selected;
    }

    GUIObject* GUIObject::get_parent()
    {
      return parent;
    }

    string  GUIObject::get_obj_type()
    {
      return obj_type;
    }

    string  GUIObject::get_name()
    {
      return name;
    }

    bool    GUIObject::is_idle()
    {
      return status == GUIOBJECT_IDLE;
    }

    bool    GUIObject::is_over()
    {
      return status == GUIOBJECT_OVER;
    }

    bool    GUIObject::double_click()
    {
      return do_double_click;
    }

    GUIObject*   GUIObject::get_child_by(string _name)
    {
      GUIObject* ret = NULL;
      int   i = 0;
      while(i<childs.size() && ret == NULL)
      {
        if(childs.at(i)->get_name() == _name)
        {
          ret = childs.at(i);
        }
        i++;
      }
      return ret;
    }

    GUIObject*    GUIObject::search_in_herarchy(GUIObject*  _parent)
    {
      GUIObject* ret = NULL;
      
      if(_parent->get_childs().size() == 0)
      {
        if(_parent->is_over() && _parent->is_visible())
        {
          ret = _parent;
        }
      }else{

        int i = 0;
        
        while(i<_parent->get_childs().size() && ret == NULL)
        {
          ret = search_in_herarchy(_parent->get_childs().at(i));
          i++;
        }
        
        if(ret == NULL)
        {
          if(_parent->is_over())
          {
            ret = _parent;
          }
        }
      }
      return ret;
    }

    GUIObject* GUIObject::has_object_over()
    {
      /*
      if(childs.size() > 0)
      {
        object_over = NULL;
        int top_object_layer = -1;
        for(int i=0;i<childs.size();i++)
        {
          if(childs.at(i)->is_over() && childs.at(i)->get_layer() > top_object_layer)
          {
            top_object_layer = childs.at(i)->get_layer();
            object_over = childs.at(i);
          }
        }
      }else{
        if(is_over())
        {
          object_over = this;
        }
      }*/
      
      object_over = search_in_herarchy(this);
    /*  if(object_over != NULL)
      {
        cout << object_over->get_name() << endl;
      }
    */
      return object_over;
    }

    bool    GUIObject::is_pressed()
    {
      return status == GUIOBJECT_PRESS;
    }

    bool    GUIObject::is_released()
    {
      return status == GUIOBJECT_RELEASED;
    }

    bool    GUIObject::is_draggable()
    {
      return draggable;
    }

    bool    GUIObject::is_system_owned()
    {
      return system_owned;
    }
    
    bool    GUIObject::deletable()
    {
      return is_deletable;
    }

    int     GUIObject::get_layer()
    {
      return layer;
    }

    int     GUIObject::get_id()
    {
      return id;
    }

    ofxJSONElement  GUIObject::get_info()
    {
      return info;
    }

    ofxJSONElement  GUIObject::get_json()
    {
      ofxJSONElement  json_ret;
      json_ret["name"] = name;
      json_ret["type"] = obj_type;
      json_ret["id"] = id;
      json_ret["layer"] = layer;
      json_ret["view"]["x"] = x;
      json_ret["view"]["y"] = y;
      json_ret["view"]["width"] = width;
      json_ret["view"]["height"] = height;
      return json_ret;
    }
    
  }
  
}
