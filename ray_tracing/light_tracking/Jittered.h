//
//  Jittered.h
//  light_tracking
//
//  Created by wan andy on 14-9-28.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Jittered__
#define __light_tracking__Jittered__

#include "Sampler.h"

class Jittered: public Sampler{
public:
    virtual void generate_samples();
    Jittered(int sample = 64);
};


#endif /* defined(__light_tracking__Jittered__) */
