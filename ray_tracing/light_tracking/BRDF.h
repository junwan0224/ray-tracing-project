//
//  BRDF.h
//  light_tracking
//
//  Created by wan andy on 14-11-25.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_BRDF_h
#define light_tracking_BRDF_h

#include "RGBColor.h"
#include "ShadeRec.h"
#include "Sampler.h"

class BRDF {
public:
    BRDF () {sample_ptr = nullptr;};
    virtual RGBColor f (const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const = 0;
    virtual RGBColor sample_f (const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const = 0;
    virtual RGBColor rho (const ShadeRec& sr, const Vector3D& wo) const = 0;
protected:
    Sampler* sample_ptr;
};

#endif
