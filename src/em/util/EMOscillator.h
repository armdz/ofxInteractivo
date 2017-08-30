//
//  EMOscillator.h
//  dataViz
//
//  Created by Lolo on 8/27/15.
//
//

#ifndef __dataViz__EMOscillator__
#define __dataViz__EMOscillator__

#include <stdio.h>
#include "EMAbstract.h"

class EMOscillator : public EMAbstract {
  
public:
  EMOscillator();
  ~EMOscillator();
  void  setup(string _name,float  _vel,int  _type = EM::sin,float _offset = 0.0);
  void  start();
  void  stop();
  void  update();
  float val();
private:
  float acum;
  float value;
  float vel;
  float offset;
  
};

#endif /* defined(__dataViz__EMOscillator__) */
