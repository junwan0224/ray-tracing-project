//
//  PointLight.h
//  light_tracking
//
//  Created by wan andy on 14-10-7.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__PointLight__
#define __light_tracking__PointLight__

#include "Light.h"

class PointLight: public Light{
public:
    PointLight(const Point3D& locat = Point3D(0,0,0)): Light(), ls(1.0), color(Color_White), location(locat) {};
    void set_loc(int x, int y, int z) {
        location.x = x;
        location.y = y;
        location.z = z;
    };
    void set_ls(float nls) {ls = nls;};
    void set_color(const RGBColor& c) {color = c;};
    virtual Vector3D get_direction(ShadeRec& sr);
    virtual float get_length(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr);
    virtual bool casts_shadows () const {return true;};
private:
    float ls;
    RGBColor color;
    Point3D location;
};

#endif /* defined(__light_tracking__PointLight__) */
