//
//  Plane.h
//  light_tracking
//
//  Created by wan andy on 14-8-25.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_Plane_h
#define light_tracking_Plane_h

#include "Point3D.h"
#include "Vector3D.h"
#include "GeometricObject.h"

class Ray;
class Material;

class Plane: public GeometricObject{
    Point3D point;
    Normal normal;
    Normal u;
    Normal v;
public:
    Plane();
    Plane(const Point3D& p, const Normal& n);
    void set_point(const Point3D& p);
    void set_normal(const Vector3D& n);
    virtual bool shadow_hit(const Ray& ray, float& t) const;
    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual double get_kEpsilon() const;
    constexpr static double kEpsilon = 0.000025;
};

#endif
