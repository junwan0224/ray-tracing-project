//
//  PointLight.cpp
//  light_tracking
//
//  Created by wan andy on 14-10-7.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "ShadeRec.h"
#include "PointLight.h"

Vector3D PointLight::get_direction(ShadeRec& sr){
    return ( (location - sr.hit_point).normalize() );
}

float PointLight::get_length(ShadeRec& sr) {
    return ((location - sr.hit_point).norm2());
}

RGBColor PointLight::L(ShadeRec& sr){
    return (ls * color);
}
