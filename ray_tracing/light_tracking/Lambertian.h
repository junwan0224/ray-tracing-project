//
//  Lambertian.h
//  light_tracking
//
//  Created by wan andy on 14-11-25.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_Lambertian_h
#define light_tracking_Lambertian_h

#include "BRDF.h"
#include "Constant.h"
#include "Texture.h"

class Lambertian: public BRDF {
public:
    Lambertian (Texture* c, float k = 1.0);
    Lambertian (RGBColor c = RGBColor(Color_White), float k = 1.0);
    float set_kd (float k) {
        return kd = k;
    };
    float get_kd () {
        return kd;
    }
    Texture* set_cd (Texture* newcd);
    Texture* get_cd ();
    virtual RGBColor f (const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const;
    virtual RGBColor sample_f (const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const;
    virtual RGBColor rho (const ShadeRec& sr, const Vector3D& wo) const;
private:
    float kd;
    Texture* cd;
};

#endif
