//
//  MultiJittered.cpp
//  light_tracking
//
//  Created by wan andy on 14-9-28.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "MultiJittered.h"
#include "Constant.h"

MultiJittered::MultiJittered(int sample){
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

void MultiJittered::generate_samples(){
    int n = (int)sqrt(num_samples);
    double random1, random2, temp;
    int target;
    for (int i = 0; i < num_sets; i++){
        
        for (int p = 0; p < n; p++){
            for (int q = 0; q < n; q++){
                random1 = rand()/10000.0;
                random2 = rand()/10000.0;
                random1 -= (int)random1;
                random2 -= (int)random2;
                Point2D sp( (n*p + q + random1)/(n*n), (n*q + p + random2)/(n*n) );
                samples.push_back(sp);
            }
        }
        
        for (int p = 0; p < n; p++){
            for (int q = 0; q < n; q++){
                target = rand() % n + p*n + i*num_samples;
                temp = samples[q + p*n + i*num_samples].y;
                samples[q + p*n + i*num_samples].y = samples[target].y;
                samples[target].y = temp;
            }
        }
        
        for (int q = 0; q < n; q++){
            for (int p = 0; p < n; p++){
                target = (rand() % n)*n + q + i*num_samples;
                temp = samples[q + p*n + i*num_samples].x;
                samples[q + p*n + i*num_samples].x = samples[target].x;
                samples[target].x = temp;
            }
        }
        
    }
}