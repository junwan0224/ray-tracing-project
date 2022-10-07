//
//  Light.h
//  light_tracking
//
//  Created by wan andy on 14-10-7.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Light__
#define __light_tracking__Light__

#include "Vector3D.h"
#include "RGBColor.h"
#include "Ray.h"
#include <limits>
#include <iostream>
class ShadeRec;

#define infty std::numeric_limits<float>::infinity()

class Light{
public:
    Light() {shadows = true;};
    virtual bool in_shadow (const Ray& ray, const ShadeRec& sr, double length) const;
    virtual Vector3D get_direction(ShadeRec& sr) = 0;
    virtual float get_length(ShadeRec& sr) = 0;
    virtual RGBColor L(ShadeRec& sr) = 0;
    virtual bool casts_shadows () const = 0;
protected:
    bool shadows;
};

#endif /* defined(__light_tracking__Light__) */
