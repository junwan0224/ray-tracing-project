//
//  Sphere.cpp
//  light_tracking
//
//  Created by wan andy on 14-8-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Sphere.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "Matte.h"
#include <cmath>
using std::sqrt;

Sphere::Sphere(double r): radius(r), center() {
    color = *new RGBColor(Color_Red);
    material_ptr = new Matte();
};

Sphere::Sphere(const Point3D& c, double r): radius(r), center(c) {
    color = *new RGBColor(Color_Red);
    material_ptr = new Matte();
};

void Sphere::set_center(const Point3D& cen){
    center = cen;
}

void Sphere::set_radius(double r){
    radius = r;
}

bool Sphere::hit(const Ray& ray, double& tmin, ShadeRec& sr) const{
    double t = 0;
    Vector3D temp = ray.o-center;
    double a = ray.d.norm2();
    double b = 2.0*temp*ray.d;
    double c = temp.norm2()-radius*radius;
    double disc = b*b-4.0*a*c;
    if (disc < 0.0)
        return false;
    
    double e = sqrt(disc);
    double denom = 2.0*a;
    t = (-b-e)/denom;
    if (t > kEpsilon){
        tmin = t;
        sr.normal = (temp+t*ray.d)/radius;
        sr.local_hit_point = sr.normal;
        return true;
    }
    
    t = (-b+e)/denom;
    if (t > kEpsilon){
        tmin = t;
        sr.normal = (temp+t*ray.d)/radius;
        sr.local_hit_point = ray.o+t*ray.d;
        return true;
    }
    
    return false;
}

bool Sphere::shadow_hit(const Ray& ray, float& tmin) const{
    double t = 0;
    Vector3D temp = ray.o-center;
    double a = ray.d.norm2();
    double b = 2.0*temp*ray.d;
    double c = temp.norm2()-radius*radius;
    double disc = b*b-4.0*a*c;
    if (disc < 0.0)
        return false;
    
    double e = sqrt(disc);
    double denom = 2.0*a;
    t = (-b-e)/denom;
    if (t > kEpsilon){
        tmin = t;
        return true;
    }
    
    t = (-b+e)/denom;
    if (t > kEpsilon){
        tmin = t;
        return true;
    }
    
    return false;
}

double Sphere::get_kEpsilon() const{
    return kEpsilon;
}

bool Sphere::inSphere(const Point3D& point) const{
    Vector3D vec (point, center);
    return (vec.norm2() <= radius*radius);
}