#include "ofxINUISlider.h"

ofxINUISlider::ofxINUISlider()
{
	localPress = false;
	opened = false;
}


ofxINUISlider::~ofxINUISlider()
{
}

void  ofxINUISlider::setup(string _name, float _x, float _y,float _w,float _h,ofImage _backImage, ofImage _buttonImage,float _minVal, float _maxVal, float _val)
{
	ofxINUIObject::setup(_name);
	setPosition(_x, _y);
    
    _buttonImage.resize(_w, _h);
    
    
    
	setSize(_buttonImage.getWidth(), _buttonImage.getHeight());
    float backScale = (_buttonImage.getWidth()*_backImage.getHeight())/_backImage.getWidth();
    
    _backImage.resize(_buttonImage.getWidth(), backScale);
    setBackImage(_backImage);


	horizontalAlign = _backImage.getWidth() >= _backImage.getHeight();

	minBound = min(getWidth(), getHeight());

	button.setup("Button", ofImage(), 0.0, 0.0);
    
    
    
	button.setSize(minBound, minBound);
    
    
    
	if(horizontalAlign)
		button.setX(_buttonImage.getWidth());
	else
		button.setY(_buttonImage.getHeight());
    
    

	button.setAsToggle(true);

	buttonFace.setup("Face", _buttonImage, 0.0, 0.0);
	buttonFace.setSize(minBound, minBound);
	buttonFace.setAsToggle(true);

	minVal = _minVal;
	maxVal = _maxVal;

	valNorm = 0.0;
	valScaled = minVal;
	step = .1;

	addChild(&button);
	addChild(&buttonFace);

	close();

}

void	ofxINUISlider::setFace(ofImage _img)
{
	buttonFace.setFace(_img);

//	buttonFace.resizeFace(minBound, minBound);

}

void	ofxINUISlider::setButtonFace(ofImage _img)
{
    float backScale =     (buttonFace.getWidth()*_img.getHeight())/buttonFace.getWidth();

    
    
    _img.resize(getWidth(),getHeight());
    
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

	if (!APP::hid.pressed())
		localPress = false;

	if (buttonFace.isOn())
	{
		if (!opened)
			open();
	}
	else {
		if (opened)
			close();

	}


	if(inside(APP::hid.x, APP::hid.y))
	{
		if (APP::hid.pressed())
			localPress = true;
		if (horizontalAlign)
		{
			horizontal();
		}
		else {
			vertical();
		}
	}
	else {
	

	}


	if (opened)
	{
		if (!inside(APP::hid.x, APP::hid.y) && APP::hid.pressed() && !localPress)
		{
			close();
			buttonFace.off();
		}
	}


}

void	ofxINUISlider::open()
{
	button.setVisible(true);
	button.setEnable(true);
	opened = true;
	if(horizontalAlign)	
		setSize(buttonFace.getWidth() + backImage.getWidth(),buttonFace.getHeight());
	else
		setSize(buttonFace.getWidth(), buttonFace.getHeight() + backImage.getHeight());

}

void	ofxINUISlider::close()
{
	button.setVisible(false);
	button.setEnable(false);
	opened = false;
	setSize(buttonFace.getWidth(), buttonFace.getHeight());

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
		posx = ofClamp(posx, buttonFace.getWidth(), getWidth() - button.getWidth());


		button.setX(posx);

		//valNorm = posx / (getWidth() - button.getWidth());
		valNorm = ofMap(posx, buttonFace.getWidth(), getWidth() - button.getWidth(), 0, 1, true);
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
		posy = ofClamp(posy, buttonFace.getHeight(), getHeight() - button.getHeight());

		button.setY(posy);
        valNorm = ofMap(posy, buttonFace.getHeight(), getHeight() - button.getHeight(), 0, 1, true);

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

	if (backImage.isAllocated() && opened)
	{
		ofSetColor(255);
		if (horizontalAlign)
			backImage.draw(buttonFace.getWidth(), 0);
		else
			backImage.draw(0, buttonFace.getHeight());
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
