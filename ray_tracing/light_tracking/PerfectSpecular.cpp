//
//  PerfectSpecular.cpp
//  light_tracking
//
//  Created by wan andy on 14-11-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "PerfectSpecular.h"
#include "ConstantColor.h"

PerfectSpecular::PerfectSpecular (Texture* c, float k){
    kr = k;
    cr = c;
}

PerfectSpecular::PerfectSpecular (RGBColor c, float k){
    kr = k;
    cr = new ConstantColor (c);
}

Texture* PerfectSpecular::set_cr (Texture* newcd){
    if (cr){
        delete cr;
        cr = nullptr;
    }
    cr = newcd;
    return newcd;
}

Texture* PerfectSpecular::get_cr (){
    return cr;
}

RGBColor PerfectSpecular::f (const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const{
    return RGBColor(Color_Black);
}

RGBColor PerfectSpecular::sample_f (const ShadeRec& sr,
                                   Vector3D& wi, const Vector3D& wo) const{
    float ndotwo = sr.normal * wo;
    wi = -wo + 2.0 * sr.normal * ndotwo;
    wi /= wi.norm();
    return kr * cr -> get_color(sr) / (sr.normal*wi);
}

RGBColor PerfectSpecular::rho (const ShadeRec& sr, const Vector3D& wo) const{
    return cr -> get_color(sr);
}