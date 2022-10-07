//
//  Cylinder.h
//  light_tracking
//
//  Created by wan andy on 15-1-21.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Cylinder__
#define __light_tracking__Cylinder__

#include "GeometricObject.h"

class Cylinder: public GeometricObject {
public:
    Cylinder (float h, float r, Point3D c = Point3D (0,0,0)){
        halfheight = h;
        radius = r;
        center = c;
    }
    void set_height (float h){
        halfheight = h;
    }
    void set_radius (float r){
        radius = r;
    }
    void set_center (Point3D c){
        center = c;
    }
    virtual bool shadow_hit (const Ray& ray, float &tmin) const {
        return true;
    }
    virtual double get_kEpsilon() const {
        return kEpsilon;
    }
    virtual bool hit (const Ray& ray, double &tmin, ShadeRec& str) const;
private:
    float halfheight;
    float radius;
    Point3D center;
    constexpr static double kEpsilon = 0.000025;
};

#endif /* defined(__light_tracking__Cylinder__) */
