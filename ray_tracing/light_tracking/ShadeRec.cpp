//
//  ShadeRec.cpp
//  light_tracking
//
//  Created by wan andy on 14-8-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "ShadeRec.h"
#include "World.h"

ShadeRec::ShadeRec(World& wr)
    :hit_an_object(false), material_ptr(nullptr),
    hit_point(), local_hit_point(), normal(),
    ray(), depth(0), dir(), w(wr)
{}

ShadeRec::ShadeRec(const ShadeRec& sr): w(sr.w){
    hit_an_object = sr.hit_an_object;
    material_ptr = sr.material_ptr;
    hit_point = sr.hit_point;
    local_hit_point = sr.local_hit_point;
    normal = sr.normal;
    ray = sr.ray;
    depth = sr.depth;
    dir = sr.dir;
    w = sr.w;
}

ShadeRec& ShadeRec::operator = (const ShadeRec& sr){
    hit_an_object = sr.hit_an_object;
    material_ptr = sr.material_ptr;
    hit_point = sr.hit_point;
    local_hit_point = sr.local_hit_point;
    normal = sr.normal;
    ray = sr.ray;
    depth = sr.depth;
    dir = sr.dir;
    w = sr.w;
    return *this;
}