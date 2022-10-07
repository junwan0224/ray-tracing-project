//
//  Point2D.cpp
//  light_tracking
//
//  Created by wan andy on 14-9-27.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Point2D.h"

Point2D& Point2D::operator = (const Point2D& point){
    x = point.x;
    y = point.y;
    return *this;
}
