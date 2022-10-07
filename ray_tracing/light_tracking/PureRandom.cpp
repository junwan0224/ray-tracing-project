//
//  PureRandom.cpp
//  light_tracking
//
//  Created by wan andy on 14-9-28.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "PureRandom.h"
#include "Constant.h"

PureRandom::PureRandom(int sample){
    num_sets = 83;
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

void PureRandom::generate_samples(){
    int n = (int)sqrt(num_samples);
    double random1, random2;
    for (int i = 0; i < num_sets; i++){
        
        for (int p = 0; p < n; p++){
            for (int q = 0; q < n; q++){
                random1 = rand()/10000.0;
                random2 = rand()/10000.0;
                random1 -= (int)random1;
                random2 -= (int)random2;
                Point2D sp( random1, random2 );
                samples.push_back(sp);
            }
        }
        
    }
}
