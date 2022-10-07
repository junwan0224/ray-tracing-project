//
//  Tracer.h
//  light_tracking
//
//  Created by wan andy on 14-8-26.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_Tracer_h
#define light_tracking_Tracer_h

#include "RGBColor.h"
#include "Ray.h"

class World;

class Tracer{
public:
    Tracer():world_ptr() {};
    Tracer(World* w_ptr): world_ptr(w_ptr) {};
    //virtual RGBColor tracer_ray(const Ray& ray, const int depth, float& tmin) const;
    virtual RGBColor tracer_ray(const Ray& ray, bool & success, const int depth = 0) const;
protected:
    World* world_ptr;
};


#endif
