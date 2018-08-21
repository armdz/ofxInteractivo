#pragma once
#include "ofMain.h"
#include "ofxINUIObject.hpp"
#include "ofxINUIImageButton.hpp"

class ofxINUISlider : public ofxINUIObject
{
public:
	ofxINUISlider();
	~ofxINUISlider();
	void  setup(string _name, float _x, float _y, float _w, float _h,float _minVal,float _maxVal, float _val = 0.0);
	void	setButtonFace(ofImage _img);
	void	setBackImage(ofImage _img);
	void	setStep(float _scale);
	void  behavior();
	void  onDraw();
	float val();
	float valN();
private:
	void	horizontal();
	void	vertical();

	ofxINUIImageButton	button;
	ofImage	backImage;
	bool	horizontalAlign;
	float	pressOffset;
	float valNorm;
	float valScaled;
	float step;
	float minVal;
	float maxVal;
};

