//
//  GridMap.h
//  light_tracking
//
//  Created by wan andy on 15-1-24.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_GridMap_h
#define light_tracking_GridMap_h

#include "Mapping.h"

class GridMap: public Mapping {
public:
    GridMap (float s) : scale (s) {};
    void set_scale (float s){
        scale = s;
    }
    virtual bool get_pixel_coordinates (const Point3D& local_hit_point,
                                        const int hres, const int vres,
                                        int & row, int & column) const {
        row = ( (int)(local_hit_point.y / scale) % hres + hres ) % hres;
        column = ( (int)(local_hit_point.x / scale) % vres + vres ) % vres;
        return true;
    }
private:
    float scale;
};

#endif
