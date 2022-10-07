//
//  GeometricObject.h
//  light_tracking
//
//  Created by wan andy on 14-8-22.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_GeometricObject_h
#define light_tracking_GeometricObject_h

#include "RGBColor.h"
#include "ray.h"

class Material;
class ShadeRec;

class GeometricObject{
public:
    virtual bool shadow_hit (const Ray& ray, float &tmin) const = 0;
    virtual bool hit (const Ray& ray, double &tmin, ShadeRec& str) const = 0;
    virtual double get_kEpsilon() const = 0;
    RGBColor get_color() const {
        return color;
    };
    Material* get_material() const {
        return material_ptr;
    };
    void set_material(Material* ptr) {
        material_ptr = ptr;
    };
protected:
    RGBColor color;
    Material* material_ptr;
};


#endif
