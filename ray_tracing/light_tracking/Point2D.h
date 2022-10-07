//
//  Point2D.h
//  light_tracking
//
//  Created by wan andy on 14-9-27.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Point2D__
#define __light_tracking__Point2D__

class Point2D{
public:
    Point2D(double xx=0, double yy=0): x(xx), y(yy){};
    Point2D(const Point2D& point): x(point.x), y(point.y){};
    Point2D& operator = (const Point2D& point);
public:
    double x, y;
};

#endif /* defined(__light_tracking__Point2D__) */
