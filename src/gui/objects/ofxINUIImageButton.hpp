//
//  ofxINUIImageButton.hpp
//  mapaCabildo
//
//  Created by Lolo on 20/03/2018.
//

#ifndef ofxINUIImageButton_hpp
#define ofxINUIImageButton_hpp

#include "ofxINUIButton.hpp"

class ofxINUIImageButton : public ofxINUIButton {
public:
    ofxINUIImageButton();
    ~ofxINUIImageButton();
    void  setup(string _name,ofImage _face,float _x,float _y,float _resize = 1.0);
		void	setFace(ofImage _img, float _resize = 1.0);
		void	resizeFace(float _w, float _h);
    void  onPressedDelegate(int _id, float _x, float _y);
    void  onDraw();
    bool  on_pressed();
private:
    string  label;
		bool	hasFace;
		bool  bangPressed;
		bool  dispatchBang;
    ofImage face;
    ofRectangle label_bbox;
};


#endif /* ofxINUIImageButton_hpp */
