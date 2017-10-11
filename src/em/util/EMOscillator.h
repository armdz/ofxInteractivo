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

enum EMOSCType
{
    EM_OSC_SIN,
    EM_OSC_COS
};

class EMOscillator : public EMAbstract {
  
public:
    EMOscillator();
    ~EMOscillator();
    void  setup(string _name,float  _vel,EMOSCType  _type = EM_OSC_SIN,float _offset = 0.0);
    void  start();
    void  stop();
    void  update();
    float val();
private:
    float acum;
    float value;
    float vel;
    float offset;
    EMOSCType   type;
};

#endif /* defined(__dataViz__EMOscillator__) */
