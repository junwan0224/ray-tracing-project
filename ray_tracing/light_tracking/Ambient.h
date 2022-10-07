//
//  Ambient.h
//  light_tracking
//
//  Created by wan andy on 14-10-7.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Ambient__
#define __light_tracking__Ambient__

#include "Light.h"

class Ambient: public Light{
public:
    Ambient (): Light(), ls(1.0), color(Color_White) {};
    virtual Vector3D get_direction(ShadeRec& sr);
    virtual float get_length(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr);
    virtual bool in_shadow (const Ray& ray, const ShadeRec& sr) const {return false;};
    virtual bool casts_shadows() const {return false;};
private:
    float ls;
    RGBColor color;
};

#endif /* defined(__light_tracking__Ambient__) */
