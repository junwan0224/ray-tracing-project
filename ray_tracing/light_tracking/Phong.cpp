//
//  Phong.cpp
//  light_tracking
//
//  Created by wan andy on 14-11-29.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Phong.h"
#include "World.h"
#include "Light.h"
#include "Lambertian.h"
#include "GlossySpecular.h"
#include "ConstantColor.h"
#include "iostream"
using std::cout;
using std::endl;

Phong::Phong (){
    ambient_brdf = new Lambertian ();
    diffuse_brdf = new Lambertian ();
    specular_brdf = new GlossySpecular ();
}

void Phong::set_ka (const float k){
    ambient_brdf -> set_kd(k);
}

void Phong::set_kd (const float k){
    diffuse_brdf -> set_kd(k);
}

void Phong::set_ks (const float k){
    specular_brdf -> set_ks(k);
}

void Phong::set_expg (const float e){
    specular_brdf -> set_exp(e);
}

void Phong::set_cd (const RGBColor& c){
    Texture* color = new ConstantColor (c);
    diffuse_brdf -> set_cd(color);
    ambient_brdf -> set_cd(color);
    specular_brdf -> set_cs(color);
}

void Phong::set_cd (Texture* c){
    diffuse_brdf -> set_cd(c);
    ambient_brdf -> set_cd(c);
    specular_brdf -> set_cs(c);
}

RGBColor Phong::shade(ShadeRec& sr){
    Vector3D wo = -sr.ray.d;
    RGBColor l = ambient_brdf -> rho(sr, wo) * sr.w.ambient_ptr->L(sr);
    int num_lights = (int) sr.w.light_list.size();
    
    for (int i = 0; i < num_lights; i++){
        Vector3D wi = sr.w.light_list[i] -> get_direction(sr);
        float ndotwi = sr.normal * wi;
        if (ndotwi > 0.0){
            bool in_shadow;
            if (sr.w.light_list[i] -> casts_shadows()){
                Ray shadowRay (sr.hit_point, wi);
                double length = sr.w.light_list[i] -> get_length(sr);
                in_shadow = sr.w.light_list[i]->in_shadow(shadowRay, sr, length);
            }
            if (!in_shadow)
                l += ( diffuse_brdf->f(sr, wo, wi) + specular_brdf->f(sr, wo, wi) )
                    * sr.w.light_list[i]->L(sr) * ndotwi;
        }
    }
    return l;
}
