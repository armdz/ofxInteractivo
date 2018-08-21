#pragma once
#include "ofxINUIImageButton.hpp"

class ofxINUICombo : public ofxINUIObject
{
public:
	ofxINUICombo();
	~ofxINUICombo();

	void	setup(string _name, ofImage _face,float _x, float _y,float _width = 0,float _height = 0);
	void	closeOnSelection(bool _val);
	void	addItem(ofImage	_face, string _name = "");
	void	open();
	void	close();
	void  behavior();
	void	onDraw();
	void	selectedAsFace(bool _val);
	int		currentItemindex();
	virtual void onSelectedItem(int _itemIndex, ofxINUIButton*	_itemPtr) {};
	ofxINUIImageButton*	getCurrentItem();
protected:
	ofxINUIImageButton			button;
	vector<ofxINUIButton*>	items;
	int		curItemIndex;
	float	lItemOffset;
	bool	resizeItems;
	bool	closeOnSel;
	bool	opened;
	bool	clickOver;
	bool	doClose;
	bool	selAsFace;
};

