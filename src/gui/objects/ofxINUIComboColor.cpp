#include "ofxINUIComboColor.h"



ofxINUIComboColor::ofxINUIComboColor()
{
	attachedColor = NULL;
    frontFace.clear();
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

void	ofxINUIComboColor::onDraw()
{
    bool first = true;
    for(auto child : childs)
    {
        if(!first)
            child->setVisible(false);
        first = false;
    }
    
    drawChilds();
    
  
    ofPushStyle();
    ofEnableAlphaBlending();
    
    if(frontFace.isAllocated() && backFace.isAllocated()){
        bool first = true;
        for(auto child : childs)
        {
            if(opened && !first){
                child->pushMatrix();
                
                ofSetColor(255);
                backFace.draw(0,0);
                
                float a = ((ofxINUIButton*)child)->onPressed() ? 200 : 255;
                
                ofSetColor(((ofxINUIButton*)child)->getColor(),a);
                frontFace.draw(0,0);
                
                child->popMatrix();
            }
            first = false;
        }
    }
    
    if (selAsFace && !opened) {
        pushMatrix();
        ofMultMatrix(items.at(curItemIndex)->get_parent()->getMatrix().getInverse());
        ofMultMatrix(items.at(curItemIndex)->getMatrix().getInverse());
        items.at(curItemIndex)->setVisible(true);
        items.at(curItemIndex)->draw();
        items.at(curItemIndex)->setVisible(false);
        popMatrix();
    }
    
    ofDisableAlphaBlending();
    ofPopStyle();
    
    
    
    //pushMatrix();
    //ofNoFill();
    //ofSetColor(255, 0, 0);
    //ofDrawRectangle(rect);
    //ofFill();
    //popMatrix();
}


void    ofxINUIComboColor::setFrontFace(ofImage _frontFace)
{
    frontFace = _frontFace;
    frontFace.resize(button.getWidth(), button.getHeight());
}

void    ofxINUIComboColor::setBackFace(ofImage _backFace)
{
    backFace = _backFace;
    backFace.resize(button.getWidth(), button.getHeight());

}

void  ofxINUIComboColor::attach(ofFloatColor	&_color)
{
	attachedColor = &_color;
    onSelectedItem(0,NULL);
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
