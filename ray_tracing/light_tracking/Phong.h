//
//  Phong.h
//  light_tracking
//
//  Created by wan andy on 14-11-29.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Phong__
#define __light_tracking__Phong__

#include "Material.h"
#include "Texture.h"

class Lambertian;
class GlossySpecular;

class Phong: public Material {
public:
    Phong ();
    void set_ka (const float k);
    void set_kd (const float k);
    void set_ks (const float k);
    void set_expg (const float e);
    void set_cd (const RGBColor& c);
    void set_cd (Texture* c);
    virtual RGBColor shade (ShadeRec& s);
protected:
    Lambertian* ambient_brdf;
    Lambertian* diffuse_brdf;
    GlossySpecular* specular_brdf;
};

#endif /* defined(__light_tracking__Phong__) */
