//
//  Ray.cpp
//  light_tracking
//
//  Created by wan andy on 14-8-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Ray.h"
#include <cassert>

float Ray::dist (const Point3D& loc) const{
    if (d.x != 0)
        return (loc.x - o.x) / d.x;
    else if (d.y != 0)
        return (loc.y - o.y) / d.y;
    else if (d.z != 0)
        return (loc.z - o.z) / d.z;
    else
        assert(false);
}

Ray& Ray::operator = (const Ray& ray){
    o = ray.o;
    d = ray.d;
    return *this;
}