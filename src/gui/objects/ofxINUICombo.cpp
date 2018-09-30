#include "ofxINUICombo.h"



ofxINUICombo::ofxINUICombo()
{
	lItemOffset = 0;
	resizeItems = false;
	opened = false;
	closeOnSel = false;
	clickOver = false;
	doClose = false;
	curItemIndex = 0;
	selAsFace = false;
}


ofxINUICombo::~ofxINUICombo()
{
}

void	ofxINUICombo::setup(string _name, ofImage _face, float _x, float _y, float _width, float _height)
{
	ofxINUIObject::setup(_name);
	setPosition(_x, _y);
	button.setup(_name + "_Button", _face,0,0);
	button.resizeFace(_width, _height);
	addChild(&button);
	lItemOffset += button.getHeight();
	if (_width > 0 && _height > 0)
	{
		resizeItems = true;
		setSize(_width, _height);
	}
}

void	ofxINUICombo::addItem(ofImage	_face,string _name)
{
	string nButtonName = "";
	if (_name == "")
	{
		nButtonName = _name + "_" + ofToString(childs.size());
	}
	else {
		nButtonName = _name;
	}
	ofxINUIImageButton	*newButton = new ofxINUIImageButton();
	newButton->setup(nButtonName, _face, 0.0, lItemOffset);
	if (resizeItems)
	{
		newButton->resizeFace(getWidth(), getWidth());
	}
	items.push_back(newButton);
	newButton->setVisible(false);
	newButton->setEnable(false);
	addChild(newButton);
	lItemOffset += newButton->getHeight();
}

void	ofxINUICombo::closeOnSelection(bool _val)
{
	closeOnSel = _val;
}

void	ofxINUICombo::selectedAsFace(bool _val)
{
	selAsFace = _val;
}

void  ofxINUICombo::open()
{
	float height = button.getHeight();
	for (auto item : items) {
		item->reset();
		item->setVisible(true);
		item->setEnable(true);
		height += item->getHeight();
	}
	setHeight(height);
	opened = true;
	lockEvents();
}

void  ofxINUICombo::close()
{
	for (auto item : items) {
		item->setVisible(false);
		item->setEnable(false);
	}
	setHeight(button.getHeight());
	opened = false;
	unlockEvents();
}

void  ofxINUICombo::behavior()
{

	if (doClose)
	{
		doClose = false;
		close();
	}

	if (button.onPressed())
	{
		if (!opened)
			open();
		else
			close();
	}
	if (opened){
		if (!inside(APP::hid.x, APP::hid.y) && APP::hid.pressed())
		{
			close();
		}
		else if(APP::hid.pressed() && !clickOver){
			clickOver = true; 
			int	somePressed = -1;
			int cIndex = 0;
			while (cIndex < items.size() && somePressed == -1) {
				if (items.at(cIndex)->onPressed()) {
					somePressed = cIndex;
				}
				cIndex++;
			}
			if (somePressed != -1) {
				curItemIndex = somePressed;
				onSelectedItem(curItemIndex, items.at(curItemIndex));
				if(closeOnSel)
					doClose = true;
			}
		}
 	}
	if (!APP::hid.pressed())
	{
		clickOver = false;
	}
	
}

void	ofxINUICombo::onDraw()
{
	drawChilds();

	if (selAsFace && !opened) {
		pushMatrix();
		ofMultMatrix(items.at(curItemIndex)->get_parent()->getMatrix().getInverse());
		ofMultMatrix(items.at(curItemIndex)->getMatrix().getInverse());
		items.at(curItemIndex)->setVisible(true);
		items.at(curItemIndex)->draw();
		items.at(curItemIndex)->setVisible(false);
		popMatrix();
	}
	//pushMatrix();
	//ofNoFill();
	//ofSetColor(255, 0, 0);
	//ofDrawRectangle(rect);
	//ofFill();
	//popMatrix();
}

int		ofxINUICombo::currentItemindex()
{
	return curItemIndex;
}

ofxINUIImageButton*	ofxINUICombo::getCurrentItem()
{
	return (curItemIndex == -1 ? NULL : (ofxINUIImageButton*)items.at(curItemIndex));
}