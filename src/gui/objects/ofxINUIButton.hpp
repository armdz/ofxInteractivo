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

class ofxINUIButton : public ofxINUIObject {
public:
  ofxINUIButton();
  ~ofxINUIButton();
  void  setup(string _name,string _label,float _x,float _y,float _w,float _h);
	void  onPressedDelegate(int _id, float _x, float _y);
	void	setAsToggle(bool _val);
	void	off();
	void	setColor(ofFloatColor	_idle);
	//void	onSetup();
  void  behavior();
	void  onDraw();
	void	reset();
	bool    onPressed();
	bool	isOn();	//	toggle case
    
    ofFloatColor getColor(){ return skin.idle;};
protected:
	bool	val;
	bool	isToggle;
	bool  dispatchBang;
	int		dispatchFrame;

private:
	ofxINUISkin	skin;

  string  label;
  bool  bangPressed;

  ofRectangle labelBox;
};



#endif /* GUIButton_hpp */
