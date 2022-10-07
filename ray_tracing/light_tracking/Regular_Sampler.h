//
//  Regular_Sampler.h
//  light_tracking
//
//  Created by wan andy on 14-9-27.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Regular_Sampler__
#define __light_tracking__Regular_Sampler__

#include "Sampler.h"

class Regular_Sampler: public Sampler{
public:
    virtual void generate_samples();
    Regular_Sampler(int sample = 64);
};

#endif /* defined(__light_tracking__Regular_Sampler__) */
