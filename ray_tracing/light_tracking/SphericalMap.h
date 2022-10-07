//
//  SphericalMap.h
//  light_tracking
//
//  Created by wan andy on 15-1-20.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__SphericalMap__
#define __light_tracking__SphericalMap__

#include "Mapping.h"
#include "Constant.h"
#include <cassert>

class SphericalMap: public Mapping{
public:
    virtual bool get_pixel_coordinates (const Point3D& local_hit_point,
                            const int hres, const int vres,
                            int & row, int & column) const {
        float theta = acos (local_hit_point.y);
        float phi = -atan2 (local_hit_point.x, local_hit_point.z);
        if (phi < 0.0)
            phi += TwoPI;
        float u = phi * invTwoPI;
        float v = theta * invPI;
        row = (int) (hres - 1) * v;
        column = (int) (vres - 1) * u;
        return true;
    }
};

#endif /* defined(__light_tracking__SphericalMap__) */
