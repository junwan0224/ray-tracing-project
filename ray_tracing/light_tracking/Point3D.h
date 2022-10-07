//
//  Point3D.h
//  light_tracking
//
//  Created by wan andy on 14-8-21.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_Point3D_h
#define light_tracking_Point3D_h

class Vector3D;

class Point3D{
public:
    Point3D(double xx=0, double yy=0, double zz=0): x(xx), y(yy), z(zz){};
    Point3D(const Point3D& point): x(point.x), y(point.y), z(point.z){};
    Point3D& operator = (const Point3D& point);
    Point3D& operator = (const Vector3D& vec);
public:
    double x, y, z;
};

Point3D operator * (const Point3D& p, double mul);
Point3D operator + (const Point3D& p1, const Point3D& p2);

#endif
