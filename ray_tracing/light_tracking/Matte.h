//
//  Matte.h
//  light_tracking
//
//  Created by wan andy on 14-11-26.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Matte__
#define __light_tracking__Matte__

#include "Material.h"
#include "Lambertian.h"

class Matte: public Material {
public:
    Matte ();
    void set_ka (const float k);
    void set_kd (const float k);
    void set_cd (const RGBColor& c);
    void set_cd (Texture* c);
    virtual RGBColor shade (ShadeRec& sr);
private:
    Lambertian* ambient_brdf;
    Lambertian* diffuse_brdf;
};

#endif /* defined(__light_tracking__Matte__) */
