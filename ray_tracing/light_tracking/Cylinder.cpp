//
//  Cylinder.cpp
//  light_tracking
//
//  Created by wan andy on 15-1-21.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#include "Cylinder.h"
#include "ShadeRec.h"
#include <cmath>

bool Cylinder::hit (const Ray& ray, double &tmin, ShadeRec& sr) const{
    double t = 0;
    double tempx = ray.o.x - center.x;
    double tempz = ray.o.z - center.z;
    double a = ray.d.x * ray.d.x + ray.d.z * ray.d.z;
    double b = 2.0 * ( tempx * ray.d.x + tempz * ray.d.z );
    double c = tempx * tempx + tempz * tempz -radius*radius;
    double disc = b*b-4.0*a*c;
    if (disc < 0.0)
        return false;
    
    double e = sqrt(disc);
    double denom = 2.0*a;
    double up = center.y + halfheight;
    double down = center.y - halfheight;
    
    t = (-b-e)/denom;
    if (t > kEpsilon){
        double tempy = ray.o.y + ray.d.y * t;
        if ( tempy <= up && tempy >= down){
            tmin = t;
            sr.normal.x = (tempx+t*ray.d.x) / radius;
            sr.normal.z = (tempz+t*ray.d.z) / radius;
            sr.normal.y = 0;
            sr.local_hit_point.x = sr.normal.x;
            sr.local_hit_point.z = sr.normal.z;
            sr.local_hit_point.y = 0.5 + 0.5 * (tempy - center.y) / halfheight;
            return true;
        }
    }
    
    t = (-b+e)/denom;
    if (t > kEpsilon){
        double tempy = ray.o.y + ray.d.y * t;
        if ( tempy <= up && tempy >= down){
            if (ray.d.y < 0){
                tmin = (up - ray.o.y) / ray.d.y;
                sr.normal.x = 0;
                sr.normal.z = 0;
                sr.normal.y = 1;
                sr.local_hit_point.x = (tempx+tmin*ray.d.x) / radius;
                sr.local_hit_point.z = (tempz+tmin*ray.d.z) / radius;
                sr.local_hit_point.y = 1;
                return true;
            }
            else{
                tmin = (down - ray.o.y) / ray.d.y;
                sr.normal.x = 0;
                sr.normal.z = 0;
                sr.normal.y = -1;
                sr.local_hit_point.x = (tempx+tmin*ray.d.x) / radius;
                sr.local_hit_point.z = (tempy+tmin*ray.d.z) / radius;
                sr.local_hit_point.y = 0;
                return true;
            }
                
        }
    }
    
    return false;
}