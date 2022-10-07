//
//  Matte.cpp
//  light_tracking
//
//  Created by wan andy on 14-11-26.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Matte.h"
#include "World.h"
#include "Light.h"
#include "RGBColor.h"
#include "ConstantColor.h"

Matte::Matte (): Material(){
    ambient_brdf = new Lambertian();
    diffuse_brdf = new Lambertian();
}

void Matte::set_ka (const float k){
    ambient_brdf -> set_kd(k);
}

void Matte::set_kd (const float k){
    diffuse_brdf -> set_kd(k);
}

void Matte::set_cd (Texture* c){
    ambient_brdf -> set_cd(c);
    diffuse_brdf -> set_cd(c);
}

void Matte::set_cd (const RGBColor& c){
    Texture* color = new ConstantColor (c);
    ambient_brdf -> set_cd(color);
    diffuse_brdf -> set_cd(color);
}

RGBColor Matte::shade(ShadeRec& sr){
    Vector3D wo = -sr.ray.d;
    RGBColor L = ambient_brdf -> rho (sr, wo) * sr.w.ambient_ptr->L(sr);
    int numLights = (int)sr.w.light_list.size();
    
    for (int i = 0; i < numLights; i++){
        Vector3D wi = sr.w.light_list[i]->get_direction(sr);
        float ndotwi = sr.normal * wi;
        if (ndotwi > 0.0)
            L += diffuse_brdf -> f(sr, wo, wi) * sr.w.light_list[i] -> L(sr) * ndotwi;
    }
    return L;
}

