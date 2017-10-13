//
//  UIConstants.h
//  Cajas
//
//  Created by lolo on 11/22/16.
//
//

#ifndef UIConstants_h
#define UIConstants_h
#include "ofMain.h"

namespace ofxInteractivo { namespace gui{

enum{
  GUIOBJECT_IDLE,
  GUIOBJECT_OVER,
  GUIOBJECT_PRESS,
  GUIOBJECT_RELEASED
};

enum{
  DOT_TYPE_INPUT,
  DOT_TYPE_OUTPUT
};

enum{
  UI_EVENT_CLICK,
  UI_EVENT_DOUBLE_CLICK,
  UI_EVENT_LIST_SELECTED_ITEM
};


static int UI_FONT_SIZE = 10;

static ofFloatColor VSUI_COLOR_IDLE = ofFloatColor(.3,1.0);
static ofFloatColor VSUI_COLOR_TEXT = ofFloatColor(1.0,1.0);
static ofFloatColor VSUI_COLOR_OVER = ofFloatColor(1.0,0.0,.5,1.0);

static string OBJ_UI_TYPE_DOT = "UI_DOT";
static string OBJ_UI_TYPE_NODE = "UI_NODE";
static string OBJ_UI_TYPE_BUTTON = "UI_BUTTON";
static string OBJ_UI_TYPE_LIST = "UI_LIST";
static string OBJ_UI_TYPE_TEXTFIELD = "UI_TEXTFIELD";
static string OBJ_UI_VALUE = "UI_VALUE";
static string OBJ_UI_FUNCTION = "UI_FUNCTION";

static ofFloatColor UI_COLOR_DOT_IDLE = ofFloatColor(0.0,1.0);
static float  UI_DOT_SIZE = 8;

static float UI_MIN_NODE_HEIGHT = 25;

static ofFloatColor CONNECTION_COLOR = ofFloatColor(.8,1.0);
static ofFloatColor CONNECTION_HIGHLIGHT = ofFloatColor(0.0,1.0);
  
//  this dont be here ?
static string  CJS_VALUE_BUNDLE = "cajas.generic.value_node";

  
class VSUI
{
public:
  VSUI();
  ~VSUI();
  static void  init();
  static ofRectangle  calculate_bbox(string _text);
  static bool         is_number(const std::string& s);
  static ofTrueTypeFont  font;
};

}}

#endif /* UIConstants_h */
