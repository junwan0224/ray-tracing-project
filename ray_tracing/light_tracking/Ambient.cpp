//
//  Ambient.cpp
//  light_tracking
//
//  Created by wan andy on 14-10-7.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Ambient.h"

//useless function
Vector3D Ambient::get_direction(ShadeRec& sr){
    return (Vector3D ());
}

float Ambient::get_length(ShadeRec& sr){
    return infty;
}

RGBColor Ambient::L(ShadeRec& sr){
    return (color * ls);
}

