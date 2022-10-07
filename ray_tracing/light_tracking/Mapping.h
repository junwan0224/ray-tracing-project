//
//  Mapping.h
//  light_tracking
//
//  Created by wan andy on 15-1-18.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Mapping__
#define __light_tracking__Mapping__

#include "Point3D.h"

class Mapping {
public:
    virtual bool get_pixel_coordinates (const Point3D& local_hit_point,
                                        const int hres, const int vres,
                                        int & row, int & column) const = 0;
    virtual ~ Mapping() {};
};

#endif /* defined(__light_tracking__Mapping__) */
