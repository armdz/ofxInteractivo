//
//  GUIObject.cpp
//  Cajas
//
//  Created by lolo on 11/22/16.
//
//

#include "ofxINUIObject.hpp"


ofxINUIObject::ofxINUIObject()
{
    pressed_is_delegated = false;
		hid_pointer_id = -1;
		parent = NULL;
		eventsLocked = false;
		stopClickPropagate = false;
}

ofxINUIObject::~ofxINUIObject()
{
  
}

void  ofxINUIObject::setup(string _name)
{
    name = _name;
  //  is_enable = true;
    visible = true;
    system_owned = false;
    mouse_press_state = false;
    id = -1;
    //
    layer = 0;
    status = INUIObject_Idle;
    draggable = false;
    is_deletable = true;
    parent = NULL;
    object_over = NULL;
    obj_type = "";
    prev_click_time = ofGetElapsedTimeMillis(); //for double click
    do_double_click = false;
    child_index_to_delete = -1;
		setEnable(true);
		//setPosition(_x, _y);
	//	setSize(_w, _h);
   
//		onSetup();
}


void  ofxINUIObject::destroy()
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

void  ofxINUIObject::set_name(string _name)
{
  name = _name;
}

void  ofxINUIObject::set_layer(int _layer)
{
  layer = _layer;
}

void  ofxINUIObject::set_id(int _id)
{
  id = _id;
}

void  ofxINUIObject::setParent(ofxINUIObject  *_parent)
{
  parent = _parent;
  draggable = false;

	calculateFinalMatrix();

	//updateMatrix();

  //set_layer(1);
 // initial_pos = ofPoint(x,y);
}

void  ofxINUIObject::set_draggable(bool  _val)
{
  if(parent == NULL){
    draggable = _val;
  }else{
    draggable = false;
    ofLogNotice() << "Object with parent can not be dragged";
  }
}

void    ofxINUIObject::delegate(bool _pressed)
{
    pressed_is_delegated = _pressed;
}

void  ofxINUIObject::update()
{
   

	stopClickPropagate = false;
	if (!isEnable())
		return;

	for (auto child : childs)
	{
		child->update();
		if (!child->isIdle())
			stopClickPropagate = true;
	}
  behavior();

	
 
}

void  ofxINUIObject::update_childs()
{
  if(isEnable()){
    for(int i=0;i<childs.size();i++)
    {
      childs.at(i)->update();
    }
  }
}

void  ofxINUIObject::childs_behavior()
{
  if(isEnable()){
    for(int i=0;i<childs.size();i++)
    {
      childs.at(i)->behavior();
    }
  }
}


void  ofxINUIObject::draw()
{
  
	if (!visible)
		return;

	onDraw();

	/*
	ofPushMatrix();

	ofMultMatrix(finalMatrix);
	ofNoFill();
	ofSetColor(255);
	ofDrawRectangle(rect);
	ofFill();

	ofDrawBitmapStringHighlight(getStatus(), 0, 0);
	
	ofPopMatrix();
	
	drawChilds();*/

}

void  ofxINUIObject::drawChilds()
{
   for(int i=0;i<childs.size();i++)
   {
     childs.at(i)->draw();
   }
}

void  ofxINUIObject::clear_childs()
{
  childs.clear();
}

void  ofxINUIObject::setVisible(bool _val)
{
  visible = _val;
}

void  ofxINUIObject::set_obj_type(string _type)
{
  obj_type = _type;
}

void  ofxINUIObject::add_child(ofxINUIObject* _child)
{
	/*
  _child->set_parent(this);
  _child->initial_pos.set(_child->getX(), _child->getY());
  _child->setX(x+_child->initial_pos.x);
  _child->setY(y+_child->initial_pos.y);
  _child->set_layer(childs.size()+1);
  childs.push_back(_child);*/
}

void  ofxINUIObject::remove_child(ofxINUIObject* _child)
{
  int   i = 0;
  int   found = -1;
  while(i<childs.size() && found == -1)
  {
    if(childs.at(i)->getName() == _child->getName())
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


void  ofxINUIObject::enable_childs(bool  _val)
{
	/*
  for(int i=0;i<childs.size();i++)
    childs.at(i)->enable(_val);*/
}

void  ofxINUIObject::set_info(ofxJSONElement _info)
{
  info = _info;
}

void  ofxINUIObject::set_system_owned()
{
  system_owned = true;
}

void	ofxINUIObject::setEnable(bool _val)
{
	if (_val)
	{
		ofAddListener(ofxINHIDEvent().move, this, &ofxINUIObject::hid_move);
		ofAddListener(ofxINHIDEvent().pressed, this, &ofxINUIObject::hid_pressed);
		ofAddListener(ofxINHIDEvent().released, this, &ofxINUIObject::hid_released);
	}
	else {
		ofRemoveListener(ofxINHIDEvent().move, this, &ofxINUIObject::hid_move);
		ofRemoveListener(ofxINHIDEvent().pressed, this, &ofxINUIObject::hid_pressed);
		ofRemoveListener(ofxINHIDEvent().released, this, &ofxINUIObject::hid_released);
	}
	enable = _val;
}

void  ofxINUIObject::set_deleteable(bool _val)
{
  is_deletable = _val;
}


void  ofxINUIObject::set_selected(bool _val)
{
  selected = _val;
}


void  ofxINUIObject::setRightAlign(float _sep)
{
    alignSeparation = _sep;
    rightAlign = true;
}

//  Events

void    ofxINUIObject::hid_move(ofxINHIDEvent   &_e)
{

    if(inside(_e.pointer.x,_e.pointer.y))
    {
        status = status == INUIObject_Pressed ? INUIObject_Pressed : INUIObject_Over;
    }else{
        status = INUIObject_Idle;
    }
    
}

void    ofxINUIObject::hid_pressed(ofxINHIDEvent   &_e)
{

	if (inside(_e.pointer.x, _e.pointer.y) && status != INUIObject_Pressed)
	{
		hid_pointer_id = _e.pointer.id;
		if (pressed_is_delegated) {
			ofPoint	localPoint = pointAsLocal(_e.pointer.x, _e.pointer.y);

			onPressedDelegate(_e.pointer.id, localPoint.x, localPoint.y);
		}
		else {
			status = INUIObject_Pressed;
		}

	}

}

void    ofxINUIObject::hid_released(ofxINHIDEvent   &_e)
{

    if(_e.pointer.id == hid_pointer_id){
				hid_pointer_id = -1;
        status = INUIObject_Released;
    }
}

void	ofxINUIObject::lockEvents()
{
	eventsLocked = true;
}

void	ofxINUIObject::unlockEvents()
{
	eventsLocked = false;
}


//

void  ofxINUIObject::print_status()
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
  ofLogNotice() << getName() << " status " << _status << endl;
}

bool	ofxINUIObject::stopPropagate()
{
	return stopClickPropagate;
}

bool  ofxINUIObject::isVisible()
{
  return visible;
}

bool  ofxINUIObject::isEnable()
{
  return enable;
}

bool  ofxINUIObject::is_selected()
{
  return selected;
}

ofxINUIObject* ofxINUIObject::get_parent()
{
  return parent;
}

string  ofxINUIObject::get_obj_type()
{
  return obj_type;
}

string  ofxINUIObject::getName()
{
  return name;
}

bool    ofxINUIObject::isIdle()
{
  return status == INUIObject_Idle;
}

bool    ofxINUIObject::isOver()
{
  return status == INUIObject_Over;
}

bool    ofxINUIObject::double_click()
{
  return do_double_click;
}

ofxINUIObject*   ofxINUIObject::get_child_by(string _name)
{
  ofxINUIObject* ret = NULL;
  int   i = 0;
  while(i<childs.size() && ret == NULL)
  {
    if(childs.at(i)->getName() == _name)
    {
      ret = childs.at(i);
    }
    i++;
  }
  return ret;
}

ofxINUIObject*    ofxINUIObject::search_in_herarchy(ofxINUIObject*  _parent)
{
  ofxINUIObject* ret = NULL;
  
  if(_parent->get_childs().size() == 0)
  {
    if(_parent->isOver() && _parent->isVisible())
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
      if(_parent->isOver())
      {
        ret = _parent;
      }
    }
  }
  return ret;
}

ofxINUIObject* ofxINUIObject::has_object_over()
{
  return search_in_herarchy(this);
}

bool    ofxINUIObject::isReleased()
{
  return status == INUIObject_Released;
}

bool    ofxINUIObject::is_draggable()
{
  return draggable;
}

bool    ofxINUIObject::is_system_owned()
{
  return system_owned;
}

bool    ofxINUIObject::deletable()
{
  return is_deletable;
}

int     ofxINUIObject::get_layer()
{
  return layer;
}

int     ofxINUIObject::get_id()
{
  return id;
}


ofxJSONElement  ofxINUIObject::get_info()
{
  return info;
}

ofxJSONElement  ofxINUIObject::get_json()
{
  ofxJSONElement  json_ret;
 /* json_ret["name"] = name;
  json_ret["type"] = obj_type;
  json_ret["id"] = id;
  json_ret["layer"] = layer;
  json_ret["view"]["x"] = x;
  json_ret["view"]["y"] = y;
  json_ret["view"]["width"] = width;
  json_ret["view"]["height"] = height;*/
  return json_ret;
}



void	ofxINUIObject::addChild(ofxINUIObject*	_child)
{
	_child->setParent(this);
    
    if(rightAlign && childs.size() > 0)
    {
        ofxINUIObject*  prev = childs.at(childs.size()-1);
        
        _child->setX(prev->getX()+prev->getWidth()+alignSeparation);
        _child->setY(prev->getY());
        prev= NULL;
    }
    
	childs.push_back(_child);
}


void	ofxINUIObject::setPosition(float	_x, float _y, float _z)
{
	matrix.setTranslation(_x, _y, _z);
	calculateFinalMatrix();
}

void	ofxINUIObject::setX(float _x)
{
	matrix.setTranslation(ofVec3f(_x, matrix.getTranslation().y));
	calculateFinalMatrix();
}

void	ofxINUIObject::setY(float _y)
{
	matrix.setTranslation(ofVec3f(matrix.getTranslation().x, _y));
	calculateFinalMatrix();
}

void	ofxINUIObject::setSize(float _w, float _h)
{
	rect.setWidth(_w);
	rect.setHeight(_h);
}

void	ofxINUIObject::rotate(float _deg)
{
	//	not implemented :D
	//	matrix.makeRotationMatrix(_deg, 0.0, 0.0, 1.0);
}

void	ofxINUIObject::setWidth(float _w)
{
	rect.setWidth(_w);
}

void	ofxINUIObject::setHeight(float _h)
{
	rect.setHeight(_h);
}


void	ofxINUIObject::scale(float _x, float	_y)
{
	matrix.scale(ofVec3f(_x, _y));
}


void	ofxINUIObject::pushMatrix()
{
	ofPushMatrix();
	ofMultMatrix(finalMatrix);
}

void	ofxINUIObject::popMatrix()
{
	ofPopMatrix();
}

ofMatrix4x4	ofxINUIObject::getMatrix()
{
	return matrix;
}

void			ofxINUIObject::calculateFinalMatrix()
{
	ofMatrix4x4	tempMatrix;
	if (parent != NULL) {
		tempMatrix = parent->getMatrix();
		tempMatrix *= matrix;
	}
	else {
		tempMatrix = matrix;
	}
	finalMatrix = tempMatrix;
	for (auto child : childs)
		child->calculateFinalMatrix();
}

bool	ofxINUIObject::inside(float _x, float _y)
{
	ofVec3f	localPoint = pointAsLocal(_x, _y);
	return rect.inside(localPoint.x, localPoint.y);
}

ofPoint ofxINUIObject::pointAsLocal(float _x, float _y)
{
	ofVec3f	localPoint(_x, _y);
	localPoint = localPoint*finalMatrix.getInverse();
	return localPoint;
}


string	ofxINUIObject::getStatus()
{
	string ret = "Idle";
	switch (status)
	{
	case INUIObject_Idle:
		break;
	case INUIObject_Over:
		ret = "Over";
		break;
	case INUIObject_Pressed:
		ret = "Pressed";
		break;
	case INUIObject_Released:
		ret = "Released";
		break;
	default:
		break;
	}
	return ret;
}

float ofxINUIObject::getX()
{
	return matrix.getTranslation().x;
}

float ofxINUIObject::getY()
{
	return matrix.getTranslation().y;
}
    
float	ofxINUIObject::getWidth()
{
	return rect.getWidth();
}

float ofxINUIObject::getHeight() 
{
	return rect.getHeight();
}
  
ofPoint ofxINUIObject::getCenter()
{
	return ofPoint(getWidth()*.5, getHeight()*.5);
}
