//
//  ofxInteractivoText.cpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#include "ofxInteractivoFont.h"
#include "ofxInteractivoConstants.h"



ofxInteractivoFont::ofxInteractivoFont()
{
}

ofxInteractivoFont::~ofxInteractivoFont()
{
    
}

void ofxInteractivoFont::add(string _font_name,string _file_path,float _size)
{
    if(fonts.count(_font_name) == 0){
        ofTrueTypeFont*  _font = new ofTrueTypeFont();
        _font->load(_file_path, _size,true,true,true,false,96);
        fonts.insert(std::pair<string, ofTrueTypeFont& >(_font_name,*_font));
    }
}

void ofxInteractivoFont::draw(string _font_name,string _text)
{
    fonts.at(_font_name).drawString(_text,0.0,fonts.at(_font_name).getLineHeight());
}

void ofxInteractivoFont::draw_centered(string _font_name,string _text)
{
    ofRectangle box = get_box(_font_name,_text);
    fonts.at(_font_name).drawString(_text,-box.getWidth()/2, box.getHeight()/2);
}

ofTrueTypeFont& ofxInteractivoFont::get(string _font_name)
{
    return fonts.at(_font_name);
}

ofRectangle ofxInteractivoFont::get_box(string _font_name,string _text)
{
    return fonts.at(_font_name).getStringBoundingBox(_text, 0, 0);
}

string      ofxInteractivoFont::text_for_width(string _font_name,string _text,float _width)
{
    string f_text = "";
    string line = "";
    vector<string> parts = ofSplitString(_text, " ");
    ofTrueTypeFont  font = fonts.at(_font_name);
    for (int i = 0; i < parts.size(); i++) {
        string part = parts.at(i);
        if(i != 0) line = line + " ";
        line = line + part;
        float w = font.stringWidth(line);
        if (w < _width) {
            f_text += part + " ";
        }
        else {
            f_text += "\r\n" + part + " ";
            line = part + " ";
        }
    }
    return f_text;
}





