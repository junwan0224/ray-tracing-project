//
//  TriangleSurface.h
//  light_tracking
//
//  Created by wan andy on 15-1-23.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__TriangleSurface__
#define __light_tracking__TriangleSurface__

#include "TriangleSurface.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "GeometricObject.h"

class TriangleSurface: public GeometricObject{
public:
    Normal normal;
    double space;
    Point3D p1;
    Point3D p2;
    Point3D p3;
public:
    Point3D center;
public:
    TriangleSurface(const Point3D& p11, const Point3D& p22, const Point3D& p33);
    Normal get_normal () {return normal;};
    double maxx ();
    double minx ();
    double maxy ();
    double miny ();
    double maxz ();
    double minz ();
    virtual bool shadow_hit(const Ray& ray, float& t) const;
    virtual bool hit(const Ray& ray, double& t, ShadeRec& sr) const;
    virtual double get_kEpsilon() const;
    constexpr static double kEpsilon = 0.000025;
};

#endif /* defined(__light_tracking__TriangleSurface__) */
