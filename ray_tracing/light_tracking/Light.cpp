//
//  Light.cpp
//  light_tracking
//
//  Created by wan andy on 14-11-29.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Light.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "World.h"
#include "iostream"
using std::cout;
using std::endl;

bool Light::in_shadow (const Ray& ray, const ShadeRec& sr, double length) const{
    float t;
    int num_objects = (int)sr.w.object_list.size();
    for (int i = 0; i < num_objects; i++)
        if ( sr.w.object_list[i] -> shadow_hit(ray, t) &&
            t > sr.w.object_list[i] -> get_kEpsilon() &&
            t * t < length)
            return true;
    return false;
}
