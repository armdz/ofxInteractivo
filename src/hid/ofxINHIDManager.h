//
//  HIDManager.hpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#ifndef HIDManager_h
#define HIDManager_h

#include "ofMain.h"
#include "ofxINHIDPointer.h"
<<<<<<< HEAD
#include "ofxWin8Touch.h"
=======
#include "ofxINUI.h"
>>>>>>> 72018f2dc077993af0e74c756862bd9771698f19

enum ofxINHIDType
{
	INHID_Mouse,
	INHID_Touch
};

class ofxINHIDManager : public ofPoint{
    
public:
    ofxINHIDManager();
    ~ofxINHIDManager();
    void    init(ofxINHIDType	_type = INHID_Mouse);
		void		setup_touch();
    void    update(ofEventArgs  &_args);
		void		draw();
		//	Mouse
    void    mouseMoved(ofMouseEventArgs &arg);
    void    mouseDragged(ofMouseEventArgs &arg);
    void    mousePressed(ofMouseEventArgs &arg);
    void    mouseReleased(ofMouseEventArgs &arg);
    void    mouseEntered(ofMouseEventArgs &arg);
    void    mouseExited(ofMouseEventArgs &arg);
    void    mouseScrolled(ofMouseEventArgs &arg);
		//	Touch
		//#ifdef TARGET_WIN32 || TARGET_WIN64
		void		touchDown(ofTouchEventArgs & touch);
		void		touchMoved(ofTouchEventArgs & touch);
		void		touchUp(ofTouchEventArgs & touch);
		void		touchDoubleTap(ofTouchEventArgs & touch);
		void		touchCancelled(ofTouchEventArgs & touch);
		//#endif
		//
    int     pressed();
    bool    bang_pressed();
    bool    bang_released();
    ofPoint prev;
    float   angle;
    ofxINHIDPointer         get_with_id(int _id);
    vector<ofxINHIDPointer> *get_pointers();
private:
    void    setPosition(float _x,float _y);
    vector<ofxINHIDPointer>				vec_pointers;
		std::map<int, ofxINHIDPointer> pointers;

		ofxINHIDType	type;
    int     is_pressed;
    bool    is_pressed_banged;
    bool    is_released;
    bool    is_releassed_banged;

};

#endif /* HIDManager_h */
