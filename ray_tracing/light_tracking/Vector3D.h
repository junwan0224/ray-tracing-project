//
//  Vector3D.h
//  light_tracking
//
//  Created by wan andy on 14-8-21.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_Vector3D_h
#define light_tracking_Vector3D_h

#include "Point3D.h"

class Vector3D{
public:
    Vector3D(double xx=0, double yy=0, double zz=1): x(xx), y(yy), z(zz) {};
    Vector3D(const Point3D& point1, const Point3D& point2): x(point2.x - point1.x), y(point2.y - point1.y), z(point2.z - point1.z) {};
    double norm() const;
    double norm2() const;
    bool isNormal() const;
    Vector3D& normalize();
    Vector3D& operator = (const Vector3D& vector);
    Vector3D& operator += (const Vector3D& vector);
    Vector3D& operator -= (const Vector3D& vector);
    Vector3D& operator *= (double mul);
    Vector3D& operator /= (double mul);
public:
    double x, y, z;
};

Vector3D operator - (const Vector3D& vector1);
Vector3D operator + (const Vector3D& vector1, const Vector3D& vector2);
Vector3D operator - (const Vector3D& vector1, const Vector3D& vector2);
Vector3D operator ^ (const Vector3D& vector1, const Vector3D& vector2);
double operator * (const Vector3D& vector1, const Vector3D& vector2);
Vector3D operator * (double mul, const Vector3D& vector);
Vector3D operator * (const Vector3D& vector, double mul);
Vector3D operator / (const Vector3D& vector, double mul);
Point3D operator + (const Point3D& point, const Vector3D& vector);
Point3D operator + (const Vector3D& vector, const Point3D& point);
Vector3D operator - (const Point3D& point1, const Point3D& point2);

typedef Vector3D Normal;

#endif
