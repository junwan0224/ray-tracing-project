//
//  ShadeRec.h
//  light_tracking
//
//  Created by wan andy on 14-8-22.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_ShadeRec_h
#define light_tracking_ShadeRec_h

#include "Point3D.h"
#include "Vector3D.h"
#include "RGBColor.h"
#include "Ray.h"

class World;
class Material;

class ShadeRec{
public:
    bool hit_an_object;
    Material* material_ptr;
    Point3D hit_point;
    Point3D local_hit_point;
    Normal normal;
    //RGBColor color;
    Ray ray;
    int depth;
    Vector3D dir;
    
    World& w;
    
    ShadeRec(World& wr);
    ShadeRec(const ShadeRec& sr);
    ShadeRec& operator = (const ShadeRec& rhs);
};

#endif
