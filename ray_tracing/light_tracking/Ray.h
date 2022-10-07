//
//  Ray.h
//  light_tracking
//
//  Created by wan andy on 14-8-22.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_Ray_h
#define light_tracking_Ray_h

#include "Point3D.h"
#include "Vector3D.h"

class Ray{
public:
    Ray (): o(), d() {};
    Ray (const Point3D& origin, const Vector3D& dir): o(origin), d(dir) {};
    Ray (const Ray& ray): o(ray.o), d(ray.d) {};
    Ray& operator = (const Ray& ray);
    float dist (const Point3D& loc) const;
public:
    Point3D o;
    Vector3D d;
};

#endif
