//
//  Pinhole.h
//  light_tracking
//
//  Created by wan andy on 14-9-29.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Pinhole__
#define __light_tracking__Pinhole__

#include "Camera.h"

class Pinhole: public Camera{
public:
    Pinhole();
    void set_view_distance(float dist);
    void set_zoom(float zo);
    Vector3D ray_direction(const Point2D& p) const;
    virtual void render_scene(World& w);
private:
    float d;
    float zoom;
};

#endif /* defined(__light_tracking__Pinhole__) */
