//
//  Sampler.cpp
//  light_tracking
//
//  Created by wan andy on 14-9-27.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include <algorithm>
#include <vector>
#include "Sampler.h"
#include "Point2D.h"
#include "Constant.h"

using std::cout;
using std::endl;


void Sampler::recreate_samples(){
    shuffled_indices.clear();
    samples.clear();
    count = 0;
    jump = 0;
    generate_samples();
}

void Sampler::setup_shuffled_indices(){
    vector<int> indices(0);
    for (int i = 0; i < num_samples; i++)
        indices.push_back(i);
    
    for (int i = 0; i < num_sets; i++){
        random_shuffle(indices.begin(), indices.end());
        for (int j = 0; j < num_samples; j++)
            shuffled_indices.push_back(indices[j]);
    }
}

Point2D Sampler::sample_unit_square(){
    if (count % num_samples == 0)
        jump = (rand() % num_sets) * num_samples;
    return ( samples[ jump +
                     shuffled_indices[jump + (count++) % num_samples] ]);
}

int Sampler::get_num_samples(){
    return num_samples;
}

void Sampler::map_samples_to_unit_disk(){
    int size = (int)samples.size();
    float r, phi;
    Point2D sp;
    disk_samples.reserve(size);
    for (int j = 0; j < size; j++){
        sp.x = 2.0*samples[j].x - 1.0;
        sp.y = 2.0*samples[j].y - 1.0;
        if (sp.x > -sp.y){
            if (sp.x > sp.y){
                r = sp.x;
                phi = sp.y / sp.x;
            }
            else{
                r = sp.y;
                phi = 2 - sp.x / sp.y;
            }
        }
        else{
            if (sp.x < sp.y){
                r = -sp.x;
                phi = 4 + sp.y / sp.x;
            }
            else{
                r = -sp.y;
                if (sp.y != 0.0)
                    phi = 6 - sp.x / sp.y;
                else
                    phi = 0.0;
            }
        }
        
        phi *= PI / 4;
        
        disk_samples[j].x = r * cos(phi);
        disk_samples[j].y = r * sin(phi);
    }
}

Point2D Sampler::sample_unit_disk(){
    if (count % num_samples == 0)
        jump = (rand() % num_sets) * num_samples;
    return ( disk_samples[ jump +
                     shuffled_indices[jump + (count++) % num_samples] ]);
}

void Sampler::map_samples_to_hemisphere(const float e){
    int size = (int) samples.size();
    hemisphere_samples.reserve(num_samples*num_sets);
    float cos_phi, sin_phi, cos_theta, sin_theta;
    float px, py, pz;
    float e_inv = 1.0 / (e+1.0);
    for (int i = 0; i < size; i++){
        cos_phi = cos(TwoPI*samples[i].x);
        sin_phi = sin(TwoPI*samples[i].x);
        cos_theta = pow((1.0 - samples[i].y), e_inv);
        sin_theta = sqrt(1 - cos_theta*cos_theta);
        px = sin_theta * cos_phi;
        py = sin_theta * sin_phi;
        pz = cos_theta;
        hemisphere_samples.push_back(Point3D(px, py, pz));
    }
}

Point3D Sampler::sample_unit_hemisphere(){
    if (count % num_samples == 0)
        jump = (rand() % num_sets) * num_samples;
    return ( hemisphere_samples[ jump +
                          shuffled_indices[jump + (count++) % num_samples] ]);
}

//Sampler::~Sampler() {};

