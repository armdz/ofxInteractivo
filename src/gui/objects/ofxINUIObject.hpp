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
#include "ofxINUI.h"
#include "ofxJSON.h"
#include "ofxINHIDEvent.h"
#include "ofxInteractivo.h"

enum ofxINUIObjectStates
{
    INUIObject_Idle,
    INUIObject_Over,
    INUIObject_Pressed,
    INUIObject_Released,
};


class ofxINUIObject{

public:
    ofxINUIObject();
    ~ofxINUIObject();
    
    virtual void  set_name(string _name);
    virtual void  destroy();

    void  setParent(ofxINUIObject  *_parent);
    void  delegate(bool _pressed);
    void  set_draggable(bool  _val);
    void  update();
   // virtual void  enable(bool _val);
    void  enable_childs(bool  _val);
    void  set_layer(int _layer);
    void  set_obj_type(string _type);
    void  set_id(int _id);  //  unique object id inside de ui manager
    void  add_child(ofxINUIObject* _child);
    void  remove_child(ofxINUIObject* _child);
    void  clear_childs();
    void  update_childs();
    void  drawChilds();
    void  childs_behavior();
		void	setEnable(bool _val);
    void  setVisible(bool  _val);
    void  set_info(ofxJSONElement _info);
    void  set_system_owned();
    void  set_deleteable(bool _val);
    void  set_selected(bool _val);
		void	lockEvents();
		void  unlockEvents();
   
    //
    virtual ofxJSONElement  get_json();
    virtual void  init(){};
    virtual void  behavior(){};
    virtual void  draw();
    virtual void  onPressedDelegate(ofxINHIDEvent   &_e){};   //  for override the action of press
		virtual void  onPressedDelegate(int _id,float _x,float _y) {};   //  for override the action of press

    virtual vector<ofxINUIObject*> get_childs(){return childs;};
    string  getName();
    bool    isIdle();
    bool    isOver();
    bool    double_click();
    bool    is_draggable();
    bool    isReleased();
    bool    isEnable();
    bool    isVisible();
    bool    is_system_owned();
    bool    deletable();
    bool    is_selected();
		bool		stopPropagate();
    int     get_layer();
    int     get_id();
    void	  print_status();
    string  get_obj_type();
    ofxINUIObject* has_object_over();
    ofxINUIObject* get_parent();
    ofxINUIObject* get_child_by(string _name);
    ofxJSONElement  get_info();

		//	
		void  setup(string _name);
		virtual	void	onSetup() {};
		virtual void  onDraw() {};
		void	addChild(ofxINUIObject*	_child);
		void	scale(float _x, float	_y);
		void	setPosition(float	_x, float _y, float _z = 0.0f);
		void	setSize(float _w, float _h);
		void	rotate(float _deg);
		void	setWidth(float _w);
		void	setHeight(float _h);
		void	setX(float _x);
		void	setY(float _y);
		void	pushMatrix();	//	draw matrix
		void	popMatrix();
		bool	inside(float _x, float _y);
		ofMatrix4x4	getMatrix();
		ofPoint pointAsLocal(float _x, float _y);
		string	getStatus();
		float getX();
		float getY();
		float	getWidth();
		float getHeight();
		ofPoint getCenter();
		float	x;
		float	y;
		
protected:
		//	new
		ofRectangle			rect;
		void						calculateFinalMatrix();	//	for collide
		ofMatrix4x4			finalMatrix;

    //  events
    void    hid_move(ofxINHIDEvent   &_e);
    void    hid_pressed(ofxINHIDEvent   &_e);
    void    hid_released(ofxINHIDEvent   &_e);

    //
    ofxINUIObject*    search_in_herarchy(ofxINUIObject*  _parent);
    string  name;
    string  obj_type;
    ofxINUIObjectStates     status;
    int     layer;
    int     id;
    int     prev_click_time;
    int     child_index_to_delete;
		int			hid_pointer_id;
    bool    draggable;
    bool    enable;
    bool    do_double_click;
    bool    visible;
    bool    system_owned; //  if true, not saved on project file
    bool    mouse_press_state;
    bool    is_deletable;
    bool    selected;
    bool    pressed_is_delegated;
		bool		eventsLocked;
		bool		stopClickPropagate;
    ofxINUIObject *parent;
    ofxINUIObject *object_over;
    ofPoint     initial_pos;  //  in case it has a parent, save the initial pos
    ofxJSONElement       info;  //  save raw json data
    vector<ofxINUIObject*>  childs;

		//	new
		
		ofMatrix4x4	matrix;


};

#endif /* GUIObject_hpp */
