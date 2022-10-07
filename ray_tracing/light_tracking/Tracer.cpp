//
//  Tracer.cpp
//  light_tracking
//
//  Created by wan andy on 14-8-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "ShadeRec.h"
#include "Ray.h"
#include "World.h"
#include "Tracer.h"
#include "Material.h"
#include "iostream"
#include <vector>

using std::cout;
using std::endl;

RGBColor Tracer::tracer_ray(const Ray& ray, bool & success, const int depth) const{
    if (depth > world_ptr -> vp.max_depth){
        success = true;
        return RGBColor(Color_Black);
    }
    else{
        ShadeRec sr(world_ptr -> hit_objects(ray));
        if (sr.hit_an_object){
            sr.depth = depth;
            sr.ray = ray;
            success = true;
            return sr.material_ptr->shade(sr);
        }
        else{
            success = false;
            return world_ptr -> background_color;
        }
    }
}