//
//  GlossySpecular.h
//  light_tracking
//
//  Created by wan andy on 14-11-29.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__GlossySpecular__
#define __light_tracking__GlossySpecular__

#include "BRDF.h"
#include "Texture.h"
#include "MultiJittered.h"

class GlossySpecular: public BRDF {
public:
    GlossySpecular (Texture* c, float k = 1.0, float e = 4);
    GlossySpecular (RGBColor c = RGBColor(Color_Red), float k = 1.0, float e = 4);
    Texture* set_cs (Texture* newcd);
    Texture* get_cs ();
    float set_ks (float k) {
        return ks = k;
    };
    float get_ks () {
        return ks;
    }
    float set_exp (float e) {
        return exp = e;
    };
    float get_exp () {
        return exp;
    }
    void set_samples (const int num_samples, const float exp){
        if (sampler_ptr){
            delete sampler_ptr;
            sampler_ptr = nullptr;
        }
        sampler_ptr = new MultiJittered (num_samples);
        sampler_ptr -> map_samples_to_hemisphere(exp);
    }
    virtual RGBColor f (const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const;
    virtual RGBColor sample_f (const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const;
    virtual RGBColor rho (const ShadeRec& sr, const Vector3D& wo) const;
private:
    float ks;
    float exp;
    Texture* cs;
    Sampler* sampler_ptr;
};

#endif /* defined(__light_tracking__GlossySpecular__) */
