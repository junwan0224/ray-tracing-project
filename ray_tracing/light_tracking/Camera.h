//
//  Camera.h
//  light_tracking
//
//  Created by wan andy on 14-9-29.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Camera__
#define __light_tracking__Camera__

#include "World.h"

class Camera{
public:
    void set_eye(const Point3D& e);
    void set_lootat(const Point3D& look);
    void set_up(const Vector3D& u);
    void set_exposure_time(float time);
    //void set_roll_angle(float angle);
    void compute_uvw();
    virtual void render_scene(World& w) = 0;
protected:
    Point3D eye;
    Point3D lookat;
    Vector3D up;
    Vector3D u, v, w;
    float exposure_time;
};

#endif /* defined(__light_tracking__Camera__) */
