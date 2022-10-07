//
//  AmbientOccuder.cpp
//  light_tracking
//
//  Created by wan andy on 14-11-29.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "AmbientOccuder.h"
#include "World.h"

void AmbientOccluder::set_sampler(Sampler* s_ptr){
    if (sampler_ptr){
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    sampler_ptr = s_ptr;
    sampler_ptr->map_samples_to_hemisphere(1);
}

Vector3D AmbientOccluder::get_direction(ShadeRec& sr){
    Point3D sp = sampler_ptr -> sample_unit_hemisphere();
    return (sp.x * u + sp.y * v + sp.z * w);
}

float AmbientOccluder::get_length(ShadeRec& sr){
    return infty;
}

RGBColor AmbientOccluder::L(ShadeRec& sr){
    w = sr.normal;
    v = w ^ Vector3D(0.0072, 1.0, 0.0034);
    v.normalize();
    u = v ^ w;
    Ray shadow_ray;
    shadow_ray.o = sr.hit_point;
    shadow_ray.d = get_direction(sr);
    double length = get_length(sr);
    if (in_shadow(shadow_ray, sr, length))
        return min_amount * ls * color;
    else
        return (ls * color);
}
