//
//  Sampler.h
//  light_tracking
//
//  Created by wan andy on 14-9-27.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_Sampler_h
#define light_tracking_Sampler_h

#include <vector>
#include "Point2D.h"
#include "Point3D.h"
using std::vector;

class Sampler{
public:
    virtual void generate_samples() = 0;
    virtual ~Sampler() {};
    void recreate_samples();
    void setup_shuffled_indices();
    int get_num_samples();
    Point2D sample_unit_square();
    
    void map_samples_to_unit_disk();
    Point2D sample_unit_disk();
    
    void map_samples_to_hemisphere(const float e);
    Point3D sample_unit_hemisphere();
protected:
    int num_samples;
    int num_sets;
    vector<Point2D> samples;
    vector<Point2D> disk_samples;
    vector<Point3D> hemisphere_samples;
    vector<int> shuffled_indices;
    unsigned long count;
    int jump;
};

#endif
