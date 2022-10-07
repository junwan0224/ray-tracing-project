//
//  TriangleSurface.cpp
//  light_tracking
//
//  Created by wan andy on 15-1-23.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#include "TriangleSurface.h"
#include "ShadeRec.h"
#include "Constant.h"
#include <cassert>

using namespace std;

TriangleSurface::TriangleSurface(const Point3D& p11, const Point3D& p22, const Point3D& p33): p1 (p11), p2 (p22), p3 (p33) {
    center.x = (p11.x + p22.x + p33.x) / 3;
    center.y = (p11.y + p22.y + p33.y) / 3;
    center.z = (p11.z + p22.z + p33.z) / 3;
    Vector3D v1 = p2 - p1;
    Vector3D v2 = p3 - p2;
    normal = v1 ^ v2;
    normal /= normal.norm();
    space = (v1 ^ v2).norm();
};

bool TriangleSurface::shadow_hit(const Ray& ray, float& t) const{
    return true;
}

bool TriangleSurface::hit(const Ray& ray, double& tmin, ShadeRec& sr) const{
    double t = (p1-ray.o) * normal/(ray.d *normal);
    if (t > kEpsilon){
        tmin = t;
        sr.normal = normal;
        Point3D reach = ray.o + t * ray.d;
        Vector3D v1 = p1 - reach;
        Vector3D v2 = p2 - reach;
        Vector3D v3 = p3 - reach;
        double s1 = (v1 ^ v2) * normal;
        double s2 = (v2 ^ v3) * normal;
        if (s1 > 0 && s2 > 0 && s1 + s2 < space)
            return true;
        else
            return false;
    }
    else
        return false;
}

double TriangleSurface::get_kEpsilon() const{
    return kEpsilon;
}

double TriangleSurface::maxx (){
    double x = (p1.x > p2.x ? p1.x : p2.x);
    return (x > p3.x ? x : p3.x);
}

double TriangleSurface::minx (){
    double x = (p1.x < p2.x ? p1.x : p2.x);
    return (x < p3.x ? x : p3.x);
}

double TriangleSurface::maxy (){
    double y = (p1.y > p2.y ? p1.y : p2.y);
    return (y > p3.y ? y : p3.y);
}

double TriangleSurface::miny (){
    double y = (p1.y < p2.y ? p1.y : p2.y);
    return (y < p3.y ? y : p3.y);
}

double TriangleSurface::maxz (){
    double z = (p1.z > p2.z ? p1.z : p2.z);
    return (z > p3.z ? z : p3.z);
}

double TriangleSurface::minz (){
    double z = (p1.z < p2.z ? p1.z : p2.z);
    return (z < p3.z ? z : p3.z);
}
