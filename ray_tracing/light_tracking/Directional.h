//
//  Directional.h
//  light_tracking
//
//  Created by wan andy on 14-10-7.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Directional__
#define __light_tracking__Directional__

#include "Light.h"

class Directional: public Light{
public:
    Directional(const Vector3D& dir): Light(), ls(1.0), color(Color_White){
        if (dir.norm2() == 1)
            direction = dir;
        else if (dir.norm2() == 0)
            direction = dir;
        else
            direction = dir / dir.norm();
    };
    void set_ls(float nls) {ls = nls;};
    void set_color(const RGBColor& c) {color = c;};
    void set_direction(const Vector3D& dir) {direction = dir;};
    virtual Vector3D get_direction(ShadeRec& sr);
    virtual float get_length(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr);
    virtual bool casts_shadows() const {return true;};
private:
    float ls;
    RGBColor color;
    Vector3D direction;
};

#endif /* defined(__light_tracking__Directional__) */
