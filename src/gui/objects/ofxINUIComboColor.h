#pragma once
#include "ofxINUICombo.h"

class ofxINUIComboColor : public ofxINUICombo
{
public:
	ofxINUIComboColor();
	~ofxINUIComboColor();
	void	setup(string _name, ofImage _face,float _x, float _y, float _width = 0, float _height = 0);
	void	setItemHeight(float _h);
	void	addColor(ofFloatColor	_color, string _name = "");
	void  attach(ofFloatColor	&_color);
	void	onSelectedItem(int _itemIndex, ofxINUIButton*	_itemPtr);
	ofFloatColor	getCurrent();
private:
	float		itemHeight;
	ofFloatColor	*attachedColor;
	vector<ofFloatColor>	colors;
};

