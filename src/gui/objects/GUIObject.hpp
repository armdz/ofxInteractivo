//
//  GUIObject.hpp
//  Cajas
//
//  Created by lolo on 11/22/16.
//
//

#ifndef GUIObject_hpp
#define GUIObject_hpp

#include <stdio.h>
#include "ofMain.h"
#include "UIConstants.h"
#include "ofxJSON.h"
#include "APP.h"

namespace ofxInteractivo { namespace gui{

class GUIObject : public ofRectangle {

public:
    GUIObject();
    ~GUIObject();
    virtual void  setup(string _name);
    virtual void  set_name(string _name);
    virtual void  destroy();
    void  set_parent(GUIObject  *_parent);
    void  set_draggable(bool  _val);
    void  update();
    virtual void  enable(bool _val);
    void  enable_childs(bool  _val);
    void  set_layer(int _layer);
    void  set_obj_type(string _type);
    void  set_id(int _id);  //  unique object id inside de ui manager
    void  add_child(GUIObject* _child);
    void  remove_child(GUIObject* _child);
    void  clear_childs();
    void  update_childs();
    void  draw_childs();
    void  childs_behavior();
    void  set_interactive(bool _val);
    void  set_visible(bool  _val);
    void  set_info(ofxJSONElement _info);
    void  set_system_owned();
    void  set_deleteable(bool _val);
    void  set_selected(bool _val);
    virtual ofxJSONElement  get_json();
    virtual void  init(){};
    virtual void  behavior(){};
    virtual void  draw();
    virtual vector<GUIObject*> get_childs(){return childs;};
    string  get_name();
    bool    is_idle();
    bool    is_over();
    bool    is_pressed();
    bool    double_click();
    bool    is_draggable();
    bool    is_released();
    bool    is_enabled();
    bool    is_visible();
    bool    is_system_owned();
    bool    deletable();
    bool    is_selected();
    int     get_layer();
    int     get_id();
    string  print_status();
    string  get_obj_type();
    GUIObject* has_object_over();
    GUIObject* get_parent();
    GUIObject* get_child_by(string _name);
    ofxJSONElement  get_info();
private:
    GUIObject*    search_in_herarchy(GUIObject*  _parent);
    string  name;
    string  obj_type;
    int     status;
    int     layer;
    int     id;
    int     prev_click_time;
    int     child_index_to_delete;
    bool    draggable;
    bool    is_enable;
    bool    do_double_click;
    bool    visible;
    bool    system_owned; //  if true, not saved on project file
    bool    interactive;
    bool    mouse_press_state;
    bool    is_deletable;
    bool    selected;
    GUIObject *parent;
    GUIObject *object_over;
    ofPoint     initial_pos;  //  in case it has a parent, save the initial pos
    ofxJSONElement       info;  //  save raw json data
    vector<GUIObject*>  childs;

};

}}

#endif /* GUIObject_hpp */
