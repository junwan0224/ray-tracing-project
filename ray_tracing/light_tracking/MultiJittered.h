//
//  MultiJittered.h
//  light_tracking
//
//  Created by wan andy on 14-9-28.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__MultiJittered__
#define __light_tracking__MultiJittered__

#include "Sampler.h"

class MultiJittered: public Sampler{
public:
    virtual void generate_samples();
    MultiJittered(int sample = 64);
};

#endif /* defined(__light_tracking__MultiJittered__) */
