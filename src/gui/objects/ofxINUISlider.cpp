#include "ofxINUISlider.h"

ofxINUISlider::ofxINUISlider()
{
}


ofxINUISlider::~ofxINUISlider()
{
}

void  ofxINUISlider::setup(string _name, float _x, float _y, float _w, float _h, float _minVal, float _maxVal, float _val)
{
	ofxINUIObject::setup(_name);
	setPosition(_x, _y);
	setSize(_w, _h);
	horizontalAlign = getWidth() >= getHeight();

	float minBound = min(getWidth(), getHeight());

	button.setup("Button", ofImage(), 0.0, 0.0);

	button.setSize(minBound, minBound);
	button.setAsToggle(true);

	minVal = _minVal;
	maxVal = _maxVal;

	valNorm = 0.0;
	valScaled = minVal;
	step = .1;

	addChild(&button);
	
}

void	ofxINUISlider::setButtonFace(ofImage _img)
{
	button.setFace(_img);
}


void	ofxINUISlider::setBackImage(ofImage _img)
{
	backImage = _img;
	setSize(backImage.getWidth(), backImage.getHeight());
}

void	ofxINUISlider::setStep(float _scale)
{
	step = _scale;
}

void  ofxINUISlider::behavior()
{
	if (horizontalAlign)
	{
		horizontal();
	}
	else {
		vertical();
	}
}

void	ofxINUISlider::horizontal()
{
	if (button.onPressed() && button.isOn())
	{
		pressOffset = button.getX() - pointAsLocal(APP::hid.x, APP::hid.y).x;
	}
	else if (button.isOn() && APP::hid.pressed())
	{
		float posx = (pointAsLocal(APP::hid.x, APP::hid.y).x + pressOffset);
		posx = ofClamp(posx, 0, getWidth() - button.getWidth());


		button.setX(posx);

		valNorm = posx / (getWidth() - button.getWidth());
		valScaled = ofLerp(minVal, maxVal, valNorm);

	}
	else if (button.isOn() && !APP::hid.pressed())
	{
		button.off();
	}


}

void	ofxINUISlider::vertical()
{
	if (button.onPressed() && button.isOn())
	{
		pressOffset = button.getY() - pointAsLocal(APP::hid.x, APP::hid.y).y;
	}
	else if (button.isOn() && APP::hid.pressed())
	{
		float posy = (pointAsLocal(APP::hid.x, APP::hid.y).y + pressOffset);
		posy = ofClamp(posy, 0, getHeight() - button.getHeight());

		button.setY(posy);

		valNorm = posy / (getHeight() - button.getHeight());
		valScaled = ofLerp(minVal, maxVal, valNorm);

	}
	else if (button.isOn() && !APP::hid.pressed())
	{
		button.off();
	}


}

void  ofxINUISlider::onDraw()
{

	pushMatrix();

	if (backImage.isAllocated())
	{
		ofSetColor(255);
		backImage.draw(0, 0);
	}

	popMatrix();

	drawChilds();


}


float ofxINUISlider::val()
{
	return valScaled;
}

float ofxINUISlider::valN()
{
	return valNorm;
}