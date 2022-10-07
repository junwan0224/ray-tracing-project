//
//  ViewPlane.h
//  light_tracking
//
//  Created by wan andy on 14-8-26.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_ViewPlane_h
#define light_tracking_ViewPlane_h

#include <vector>
#include "RGBColor.h"
#include "Sampler.h"
using std::vector;

class ViewPlane{
public:
    int hres;
    int vres;
    float pixel_size;
    float gamma;
    float inv_gamma;
    int num_samples;
    int max_depth;
    Sampler* sample_ptr;
    vector< vector<RGBColor> > pixel;
    void set_sampler(Sampler* sp);
    void set_samples(const int n);
    void display() const;
};
#endif
