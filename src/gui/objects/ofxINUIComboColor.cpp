#include "ofxINUIComboColor.h"



ofxINUIComboColor::ofxINUIComboColor()
{
	attachedColor = NULL;
}


ofxINUIComboColor::~ofxINUIComboColor()
{
}

void	ofxINUIComboColor::setup(string _name, ofImage _face,float _x, float _y, float _width, float _height)
{
	ofxINUICombo::setup(_name, _face, _x, _y, _width, _height);
	itemHeight = getHeight();
}

void	ofxINUIComboColor::addColor(ofFloatColor	_color, string _name)
{
	string colorName;
	if (_name == "")
	{
		colorName = getName() + "_" + ofToString(colors.size());
	}
	else {
		colorName = _name;
	}
	colors.push_back(_color);

	ofxINUIButton*	button = new ofxINUIButton();
	button->setup(colorName, "", 0.0, lItemOffset, getWidth(), itemHeight);
	button->setColor(_color);
	button->setVisible(false);
	button->setEnable(false);
	items.push_back(button);
	addChild(button);
	lItemOffset += button->getHeight();
}

void  ofxINUIComboColor::attach(ofFloatColor	&_color)
{
	attachedColor = &_color;
}

void	ofxINUIComboColor::onSelectedItem(int _itemIndex, ofxINUIButton*	_itemPtr)
{
	if(attachedColor != NULL)
		*attachedColor = colors.at(_itemIndex);
}

void	ofxINUIComboColor::setItemHeight(float _h)
{
	itemHeight = _h;
}

ofFloatColor	ofxINUIComboColor::getCurrent()
{
	return colors.at(curItemIndex);
}