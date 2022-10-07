//
//  Vector3D.cpp
//  light_tracking
//
//  Created by wan andy on 14-8-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Vector3D.h"
#include "Constant.h"
#include <cassert>
using std::sqrt;

double Vector3D::norm() const{
    return sqrt(x*x+y*y+z*z);
}

double Vector3D::norm2() const{
    return (x*x+y*y+z*z);
}

bool Vector3D::isNormal() const{
    return (x*x+y*y+z*z == 1);
}

Vector3D& Vector3D::normalize(){
    double norm = sqrt(x*x+y*y+z*z);
    assert( norm > 0.0000001 );
    x /= norm;
    y /= norm;
    z /= norm;
    return *this;
}

Vector3D& Vector3D::operator = (const Vector3D& vector){
    x = vector.x;
    y = vector.y;
    z = vector.z;
    return *this;
}

Vector3D& Vector3D::operator += (const Vector3D& vector){
    x += vector.x;
    y += vector.y;
    z += vector.z;
    return *this;
}

Vector3D& Vector3D::operator -= (const Vector3D& vector){
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
    return *this;
}

Vector3D& Vector3D::operator *= (double mul){
    x *= mul;
    y *= mul;
    z *= mul;
    return *this;
}

Vector3D& Vector3D::operator /= (double mul){
    x /= mul;
    y /= mul;
    z /= mul;
    return *this;
}

Vector3D operator - (const Vector3D& vec){
    Vector3D outVector (-vec.x, -vec.y, -vec.z);
    return outVector;
}

Vector3D operator + (const Vector3D& vector1, const Vector3D& vector2){
    Vector3D outVector (vector1.x+vector2.x, vector1.y+vector2.y, vector1.z+vector2.z);
    return outVector;
}

Vector3D operator - (const Vector3D& vector1, const Vector3D& vector2){
    Vector3D outVector (vector1.x-vector2.x, vector1.y-vector2.y, vector1.z-vector2.z);
    return outVector;
}

double operator * (const Vector3D& vector1, const Vector3D& vector2){
    return (vector1.x*vector2.x + vector1.y*vector2.y + vector1.z*vector2.z);
}

Vector3D operator ^ (const Vector3D& vector1, const Vector3D& vector2){
    double x = vector1.y*vector2.z - vector1.z*vector2.y;
    double y = vector1.z*vector2.x - vector1.x*vector2.z;
    double z = vector1.x*vector2.y - vector1.y*vector2.x;
    return Vector3D (x,y,z);
}

Point3D operator + (const Point3D& point, const Vector3D& vector){
    Point3D outPoint (vector.x+point.x, vector.y+point.y, vector.z+point.z);
    return outPoint;
}

Point3D operator + (const Vector3D& vector, const Point3D& point){
    Point3D outPoint (vector.x+point.x, vector.y+point.y, vector.z+point.z);
    return outPoint;
}

Vector3D operator * (double mul, const Vector3D& vector){
    Vector3D outVector (vector.x*mul, vector.y*mul, vector.z*mul);
    return outVector;
}

Vector3D operator * (const Vector3D& vector, double mul){
    Vector3D outVector(vector.x*mul, vector.y*mul, vector.z*mul);
    return outVector;
}

Vector3D operator / (const Vector3D& vector, double mul){
    Vector3D outVector(vector.x/mul, vector.y/mul, vector.z/mul);
    return outVector;
}

Vector3D operator - (const Point3D& point1, const Point3D& point2){
    Vector3D outp (point2, point1);
    return outp;
}