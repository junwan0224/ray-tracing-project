//
//  Lambertian.cpp
//  light_tracking
//
//  Created by wan andy on 14-11-25.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Lambertian.h"
#include "Vector3D.h"
#include "ShadeRec.h"
#include "Jittered.h"
#include "ConstantColor.h"
#include <cassert>

Lambertian::Lambertian (Texture* c, float k){
    kd = k;
    cd = c;
    sample_ptr = new Jittered ();
}

Lambertian::Lambertian (RGBColor c, float k){
    kd = k;
    cd = new ConstantColor (c);
    sample_ptr = new Jittered ();
}

Texture* Lambertian::set_cd (Texture* newcd){
    if (cd){
        delete cd;
        cd = nullptr;
    }
    cd = newcd;
    return newcd;
}

Texture* Lambertian::get_cd (){
    return cd;
}

RGBColor Lambertian::f (const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const{
    return (kd * cd -> get_color(sr) * invPI);
}

RGBColor Lambertian::sample_f (const ShadeRec& sr,
                               Vector3D& wi, const Vector3D& wo) const{
    return cd -> get_color(sr);
}

RGBColor Lambertian::rho (const ShadeRec& sr, const Vector3D& wo) const{
    return kd * cd -> get_color(sr);
}

