//
//  Plane.cpp
//  light_tracking
//
//  Created by wan andy on 14-8-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Plane.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "Matte.h"

Plane::Plane(const Point3D& p, const Normal& n){
    point = p;
    normal = n / n.norm();
    u = Vector3D(1,0,0) - normal.x * normal;
    v = Vector3D(0,1,0) - normal.y * normal;
    Normal w = Vector3D(0,0,1) - normal.z * normal;
    if (u.x == 0 && u.y == 0 && u.z == 0)
        u = w;
    else if (v.x == 0 && v.y == 0 && v.z == 0)
        v = w;
    u /= u.norm();
    v /= v.norm();
    color = Color_SkyBlue;
    material_ptr = new Matte();
}

void Plane::set_point(const Point3D& p){
    point = p;
}

void Plane::set_normal(const Vector3D& n){
    normal = n / n.norm();
}

bool Plane::shadow_hit(const Ray& ray, float& tmin) const{
    double t = (point-ray.o)*normal/(ray.d*normal);
    if (t > kEpsilon){
        tmin = t;
        return true;
    }
    else
        return false;
}

bool Plane::hit (const Ray& ray, double& tmin, ShadeRec& sr) const{
    //float nor = ray.d.norm();
    double t = (point-ray.o) * normal/(ray.d *normal);
    if (t > kEpsilon){
        tmin = t;
        sr.normal = normal;
        Vector3D vec = ray.o + t*ray.d - point;
        sr.local_hit_point.x = u * vec;
        sr.local_hit_point.y = v * vec;
        sr.local_hit_point.z = 0;
        return true;
    }
    else
        return false;
}

double Plane::get_kEpsilon() const{
    return kEpsilon;
}