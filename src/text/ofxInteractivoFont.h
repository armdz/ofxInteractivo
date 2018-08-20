//
//  ofxInteractivoText.hpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#ifndef ofxInteractivoFont_h
#define ofxInteractivoFont_h

#include "ofMain.h"
#include "ofxInteractivoConstants.h"

class ofxInteractivoFont {
    
public:
    ofxInteractivoFont();
    ~ofxInteractivoFont();
    void add(string _font_name,string _file_path,float _size = 12.0f);
    void draw(string _font_name,string _text);
    void draw_centered(string _font_name,string _text);
    void clear();
    ofTrueTypeFont& get(string _font_name);
    ofRectangle get_box(string _font_name,string _text);
    string      text_for_width(string _font_name,string _text,float _width);
private:
    std::map<std::string, ofTrueTypeFont& > fonts;

    
};

#endif /* ofxInteractivoFont_h */
