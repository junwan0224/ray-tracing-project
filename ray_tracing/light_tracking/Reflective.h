//
//  Reflective.h
//  light_tracking
//
//  Created by wan andy on 14-11-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Reflective__
#define __light_tracking__Reflective__

#include "Phong.h"
#include "PerfectSpecular.h"

class Reflective: public Phong {
public:
    Reflective ();
    void set_kr (const float k);
    void set_cr (const RGBColor& c);
    void set_cr (Texture* c);
    virtual RGBColor shade (ShadeRec& sr);
private:
    PerfectSpecular* reflective_brdf;
};

#endif /* defined(__light_tracking__Reflective__) */
