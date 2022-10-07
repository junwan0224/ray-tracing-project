//
//  PlaneMap.h
//  light_tracking
//
//  Created by wan andy on 15-1-20.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_PlaneMap_h
#define light_tracking_PlaneMap_h

#include "Mapping.h"

class PlaneMap: public Mapping {
public:
    PlaneMap (float s = 1.0): scale (s) {};
    void set_scale (float s){
        scale = s;
    }
    virtual bool get_pixel_coordinates (const Point3D& local_hit_point,
                                        const int hres, const int vres,
                                        int & row, int & column) const {
        int frow = local_hit_point.y / scale + hres / 2.0;
        int fcol = local_hit_point.x / scale + vres / 2.0;
        if (frow >= hres || frow < 0 || fcol >= vres || fcol < 0)
            return false;
        else{
            row = frow;
            column = fcol;
            return true;
        }
    }
private:
    float scale;
};

#endif
