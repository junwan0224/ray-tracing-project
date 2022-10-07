//
//  CylinderMap.h
//  light_tracking
//
//  Created by wan andy on 15-1-23.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_CylinderMap_h
#define light_tracking_CylinderMap_h

#include "Mapping.h"
#include "Constant.h"

using std::cout;
using std::endl;

class CylinderMap: public Mapping {
public:
    CylinderMap () {};
    virtual bool get_pixel_coordinates (const Point3D& local_hit_point,
                                        const int hres, const int vres,
                                        int & row, int & column) const {
        if ( local_hit_point.z * local_hit_point.z + local_hit_point.x * local_hit_point.x < 1 )
            return false;
        double theta = atan2 (local_hit_point.x, -local_hit_point.z);
        row = ( 1 - local_hit_point.y) * (hres - 1);
        column = (vres - 1) * ( 0.5 + theta / PI);
        return true;
    }
};

#endif
