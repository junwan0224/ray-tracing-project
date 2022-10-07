//
//  Point3D.cpp
//  light_tracking
//
//  Created by wan andy on 14-8-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Point3D.h"
#include "Vector3D.h"

Point3D operator * (const Point3D& p, double mul){
    return Point3D(p.x * mul, p.y * mul, p.z * mul);
}

Point3D operator + (const Point3D& p1, const Point3D& p2){
    return Point3D (p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
}

Point3D& Point3D::operator = (const Point3D& point){
    x = point.x;
    y = point.y;
    z = point.z;
    return *this;
}

Point3D& Point3D::operator = (const Vector3D& vec){
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}