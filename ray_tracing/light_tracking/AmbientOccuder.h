//
//  AmbientOccuder.h
//  light_tracking
//
//  Created by wan andy on 14-11-29.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__AmbientOccuder__
#define __light_tracking__AmbientOccuder__

#include "Light.h"

class Sampler;

class AmbientOccluder: public Light {
public:
    AmbientOccluder(): u(), v(), w(), color(), min_amount(), ls(1.0){
        sampler_ptr = nullptr;
    }
    void set_min (RGBColor c){
        min_amount = c;
    }
    void set_color (RGBColor c){
        color = c;
    }
    void set_ls (float l){
        ls = l;
    }
    void set_sampler (Sampler* s_ptr);
    virtual bool casts_shadows () const {return true;};
    virtual Vector3D get_direction (ShadeRec& sr);
    virtual float get_length(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr);
private:
    float ls;
    RGBColor color, min_amount;
    Vector3D u, v, w;
    Sampler* sampler_ptr;
};

#endif /* defined(__light_tracking__AmbientOccuder__) */
