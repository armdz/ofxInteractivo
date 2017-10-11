//
//  EMTimer.h
//  dataViz
//
//  Created by Lolo on 8/27/15.
//
//

#ifndef __dataViz__EMTimer__
#define __dataViz__EMTimer__

#include <stdio.h>
#include "ofMain.h"
#include "EMAbstract.h"

class EMTimer : public EMAbstract
{
public:
  EMTimer();
  ~EMTimer();
  void  setup(string _name,float  _duration,int  _times);
  void  start();
  void  stop();
  void  update();
  void  set_duration(float _duration);
  bool  bang();
  bool  runing();
  int   times();
  float val();
    float duration;

private:
  bool  do_bang;
  bool  is_runing;
  float ellapsed;
  float norm_val;
  int   times_limit;
  int   times_counter;

};

#endif /* defined(__dataViz__EMTimer__) */
