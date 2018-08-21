//
//  APP.cpp
//  development_interactivo
//
//  Created by Lolo on 7/26/17.
//
//

#include "APP.h"
#include "ofxInteractivoConstants.h"
// APP CONFIGS

ofxJSONElement  APP::json_config;
int APP::width;
int APP::height;
string APP::name;
map<string,float>   APP::floatProperties;

//  MODULES

ofxINHIDManager   APP::hid;
ofxInteractivoFont  APP::font;
ofxInteractivoColorPalette   APP::color;
ofxInteractivoImages    APP::image;


//  VideoInputManager       APP::video_input;

//  PUBLIC

void    APP::init(string _name,int _output_width,int _output_height,bool _touch)
{
		
    if(json_config.open("config.json")){
			app_log("Config loaded");
    }else{
        app_log("config.json doesnt exists");
				ofxJSONElement	configJson;
				configJson.save("config.json",true);
				loadConfig();

    }
    //  app name
    name = _name;
    if(_output_width != 0 && _output_height != 0)
    {
        //  can get the resolution from config.json
        //  if not we can take from here
        width = _output_width;
        height = _output_height;
    }
    if(width == 0 || height == 0)
    {
        width = ofGetWidth();
        height = ofGetHeight();
    }
    //
    hid.init(_touch ? INHID_Touch : INHID_Mouse);
    image.init();
}

//

void		APP::saveConfig()
{
	json_config.save("config.json", true);
}

void		APP::loadConfig()
{
	if (json_config.open("config.json")) {
		app_log("Config loaded");
	}
}

ofxJSONElement  APP::config()
{
    return json_config;
}

int     APP::getInt(string _key_name)
{
    return json_config[_key_name].asInt();
}

float   APP::getFloat(string _key_name)
{
    return json_config[_key_name].asFloat();
}

string  APP::getString(string _key_name)
{
    return json_config[_key_name].asString();
}

void    APP::setInt(string _name,int _val)
{
    json_config[_name] = _val;
}

void    APP::setFloat(string _name,float _val)
{
    json_config[_name] = _val;
}

void    APP::setString(string _name,string _val)
{
    json_config[_name] = _val;
}

//

void    APP::background(ofColor _color)
{
    ofBackground(_color);
}

void    APP::background(string   _color_name)
{
    ofBackground(color.get(_color_name));
}

void    APP::pushCenter()
{
    ofPushMatrix();
    ofTranslate(width*.5f, height*.5f);
}

void    APP::popCenter()
{
    ofPopMatrix();
}

void    APP::showFps()
{
    ofSetColor(255);
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate(),2), 20, 20);
}

//

void    APP::setPropertie(string _id,float _val)
{
    floatProperties.insert(std::pair<string,float>(_id,_val));
}

float   APP::getPropertie(string _id)
{
    return  floatProperties.at(_id);
}

//  PRIVATES



