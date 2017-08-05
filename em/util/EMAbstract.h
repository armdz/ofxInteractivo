//
//  EMAbstract.h
//  dataViz
//
//  Created by Lolo on 8/27/15.
//
//

#ifndef dataViz_EMAbstract_h
#define dataViz_EMAbstract_h

#include "ofMain.h"
#include "EM.h"

class EMAbstract {
  
public:
  EMAbstract(){};
  ~EMAbstract(){};
  string  name;
  bool    runing;
  int     type;
  void    set_name(string _name){
    name = _name;
  };
  string  get_name()
  {
    return name;
  };
  
};

#endif
