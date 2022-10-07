//
//  Texture.h
//  light_tracking
//
//  Created by wan andy on 15-1-18.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_Texture_h
#define light_tracking_Texture_h

#include "RGBColor.h"
#include "ShadeRec.h"

class Texture {
public:
    virtual RGBColor get_color (const ShadeRec& sr) const  = 0;
    virtual ~Texture() {};
};

#endif
