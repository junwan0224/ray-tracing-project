//
//  Regular_Sampler.cpp
//  light_tracking
//
//  Created by wan andy on 14-9-27.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Regular_Sampler.h"
#include "Constant.h"

Regular_Sampler::Regular_Sampler(int sample){
    num_sets = 1;
    num_samples = sample;
    count = 0;
    jump = 0;
    vector<Point2D> temp(0);
    samples = temp;
    disk_samples = temp;
    vector<Point3D> temp1(0);
    hemisphere_samples = temp1;
    vector<int> temp2(0);
    shuffled_indices = temp2;
}

void Regular_Sampler::generate_samples(){
    int n = (int)sqrt(num_samples);
    for (int p = 0; p < n; p++){
        for (int q = 0; q < n; q++){
            Point2D sp( p/n, q/n );
            samples.push_back(sp);
        }
    }
}
