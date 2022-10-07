//
//  PerfectSpecular.h
//  light_tracking
//
//  Created by wan andy on 14-11-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__PerfectSpecular__
#define __light_tracking__PerfectSpecular__

#include "BRDF.h"
#include "Texture.h"

class PerfectSpecular: public BRDF {
public:
    PerfectSpecular (Texture* c, float k = 1.0);
    PerfectSpecular (RGBColor c = RGBColor (Color_Red), float k = 1.0);
    Texture* set_cr (Texture* newcd);
    Texture* get_cr ();
    float set_kr (float k) {
        return kr = k;
    };
    float get_kr () {
        return kr;
    }
    virtual RGBColor f (const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const;
    virtual RGBColor sample_f (const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const;
    virtual RGBColor rho (const ShadeRec& sr, const Vector3D& wo) const;
private:
    float kr;
    Texture* cr;
};

#endif /* defined(__light_tracking__PerfectSpecular__) */
