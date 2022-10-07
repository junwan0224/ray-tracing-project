//
//  Material.h
//  light_tracking
//
//  Created by wan andy on 14-11-26.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Material__
#define __light_tracking__Material__

#include "RGBColor.h"
#include "ShadeRec.h"

class Material {
public:
    Material() {};
    virtual RGBColor shade (ShadeRec& sr) {
        return RGBColor(Color_Black);
    };
    virtual RGBColor area_light_shade (ShadeRec& sr) {
        return RGBColor(Color_Black);
    };
    virtual RGBColor path_shade (ShadeRec& sr) {
        return RGBColor(Color_Black);
    };
};

#endif /* defined(__light_tracking__Material__) */
