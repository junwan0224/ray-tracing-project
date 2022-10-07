//
//  GlossySpecular.cpp
//  light_tracking
//
//  Created by wan andy on 14-11-29.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "GlossySpecular.h"
#include "Vector3D.h"
#include "Constant.h"
#include "ConstantColor.h"

GlossySpecular::GlossySpecular (Texture* c, float k, float e){
    ks = k;
    exp = e;
    cs = c;
}

GlossySpecular::GlossySpecular (RGBColor c, float k, float e){
    ks = k;
    exp = e;
    cs = new ConstantColor (c);
}

Texture* GlossySpecular::set_cs (Texture* newcd){
    if (cs){
        delete cs;
        cs = nullptr;
    }
    cs = newcd;
    return newcd;
}

Texture* GlossySpecular::get_cs (){
    return cs;
}

RGBColor GlossySpecular::f (const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const{
    RGBColor l;
    float ndotwi = sr.normal * wi;
    Vector3D r (-wi + 2.0 * sr.normal * ndotwi);
    float rdotwo = r * wo / r.norm() / wo.norm();
    if (rdotwo > 0)
        l = ks * cs -> get_color(sr) * pow(rdotwo, exp);
    return l;
}

RGBColor GlossySpecular::sample_f (const ShadeRec& sr,
                               Vector3D& wi, const Vector3D& wo) const{
    return cs -> get_color(sr);
}

RGBColor GlossySpecular::rho (const ShadeRec& sr, const Vector3D& wo) const{
    return cs -> get_color(sr);
}