//
//  Directional.cpp
//  light_tracking
//
//  Created by wan andy on 14-10-7.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Directional.h"

Vector3D Directional::get_direction(ShadeRec& sr){
    return direction;
}

float Directional::get_length(ShadeRec& sr){
    return infty;
}

RGBColor Directional::L(ShadeRec& sr){
    return ls*color;
}
