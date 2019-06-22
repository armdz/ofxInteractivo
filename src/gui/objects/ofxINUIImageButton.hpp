//
//  ofxINUIImageButton.hpp
//  mapaCabildo
//
//  Created by Lolo on 20/03/2018.
//

#ifndef ofxINUIImageButton_hpp
#define ofxINUIImageButton_hpp

#include "ofxINUIObject.hpp"

class ofxINUIImageButton : public ofxINUIObject {
public:
    ofxINUIImageButton();
    ~ofxINUIImageButton();
    void    setup(string _name,ofImage _img);
    void  setup(string _name,string _label);
    void  init();
    void  behavior();
    void  on_pressed_delegate(ofxINHIDEvent   &_e);
    void  draw();
    
    bool  on_pressed();
private:
    string  label;
    bool  bang_pressed;
    bool  dispatch_bang;
    ofImage face;
    ofRectangle label_bbox;
};


#endif /* ofxINUIImageButton_hpp */
