//
//  Reflective.cpp
//  light_tracking
//
//  Created by wan andy on 14-11-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Reflective.h"
#include "World.h"
#include "Tracer.h"
#include "ConstantColor.h"

Reflective::Reflective (): Phong(){
    reflective_brdf = new PerfectSpecular();
}

void Reflective::set_kr (const float k){
    reflective_brdf -> set_kr(k);
}

void Reflective::set_cr (const RGBColor& c){
    Texture* color = new ConstantColor (c);
    reflective_brdf -> set_cr(color);
}

void Reflective::set_cr (Texture* c){
    reflective_brdf -> set_cr(c);
}

RGBColor Reflective::shade (ShadeRec& sr){
    RGBColor L (Phong::shade(sr));
    Vector3D wo = -sr.ray.d;
    Vector3D wi;
    RGBColor fr =  reflective_brdf -> sample_f(sr, wi, wo);
    Ray reflected_ray (sr.hit_point, wi);
    bool temp = false;
    L += fr * sr.w.tracer_ptr -> tracer_ray(reflected_ray, temp, sr.depth + 1) * (sr.normal * wi);
    return L;
}