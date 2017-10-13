//
//  VSUIEvents.cpp
//  Cajas
//
//  Created by lolo on 11/27/16.
//
//

#include "UIEvents.hpp"

namespace ofxInteractivo { namespace gui{

ofEvent <UIEvents> UIEvents::events;

UIEvents::UIEvents()
{
  ui_object = NULL;
}

UIEvents::~UIEvents()
{
  
}

}}
