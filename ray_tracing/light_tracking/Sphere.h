//
//  Sphere.h
//  light_tracking
//
//  Created by wan andy on 14-8-26.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_Sphere_h
#define light_tracking_Sphere_h

#include "Point3D.h"
#include "GeometricObject.h"

class Material;

class Sphere: public GeometricObject{
public:
    Point3D center;
    double radius;
public:
    void set_center(const Point3D& cen);
    void set_radius(double r);
    Sphere(double r = 1);
    Sphere(const Point3D& c, double r);
    virtual bool shadow_hit (const Ray& ray, float& tmin) const;
    virtual bool hit (const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual double get_kEpsilon() const;
    bool inSphere (const Point3D& point) const;
    constexpr static double kEpsilon = 0.000025;
};

#endif
