//
//  ViewPlane.cpp
//  light_tracking
//
//  Created by wan andy on 14-8-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Constant.h"
#include "ViewPlane.h"
#include "MultiJittered.h"
#include "Regular_Sampler.h"
#include "IncludeCImg.h"
using namespace cimg_library;

void ViewPlane::set_sampler(Sampler* sp){
    if (sample_ptr){
        delete sample_ptr;
        sample_ptr = NULL;
    }
    
    num_samples = sp->get_num_samples();
    sample_ptr = sp;
}

void ViewPlane::set_samples(const int n){
    num_samples = n;
    if (sample_ptr){
        delete sample_ptr;
        sample_ptr = NULL;
    }
    if (num_samples > 1)
        sample_ptr = new MultiJittered(num_samples);
    else
        sample_ptr = new Regular_Sampler(1);
}

void ViewPlane::display() const{
    CImg<unsigned char> img(hres,vres,1,3);
    RGBColor color;
    int h = hres - 1;
    int v = vres - 1;
    cimg_forXY(img, x, y){
        color = max_to_one( pixel[h - x][v - y] );
        if (gamma != 0)
            color = (color^inv_gamma)*255;
        img(x,y,0,0) = color.r;
        img(x,y,0,1) = color.g;
        img(x,y,0,2) = color.b;
    }
    img.save("image.jpg");
}
