//
//  Pinhole.cpp
//  light_tracking
//
//  Created by wan andy on 14-9-29.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Pinhole.h"
#include "World.h"
#include "Tracer.h"
#include "Constant.h"

Pinhole::Pinhole(){
    d = zoom = exposure_time = 0;
    Point3D temp;
    Vector3D ttemp;
    lookat = eye = temp;
    u = v = w = up = ttemp;
}

void Pinhole::set_view_distance(float dist){
    d = dist;
}

void Pinhole::set_zoom(float zo){
    zoom = zo;
}

void Pinhole::render_scene(World& w){
    ViewPlane& vp = w.vp;
    Ray ray;
    Point2D sp, pp;
    
    vp.pixel_size /= zoom;
    ray.o = eye;
    
    for (int i = 0; i < vp.hres; i++){
        for (int j = 0; j < vp.vres; j++){
            
            for (int n = 0; n < vp.num_samples; n++){
                sp = vp.sample_ptr->sample_unit_square();
                pp.x = vp.pixel_size*( i - 0.5*vp.hres + sp.x );
                pp.y = vp.pixel_size*( j - 0.5*vp.vres + sp.y );
                ray.d = ray_direction(pp);
                bool temp = false;
                vp.pixel[i][j] += (w.tracer_ptr)->tracer_ray(ray, temp);
            }
            vp.pixel[i][j] /= vp.num_samples;
            
        }
    }
}

Vector3D Pinhole::ray_direction(const Point2D& p) const{
    Vector3D dir = p.x*u + p.y*v - d*w;
    dir.normalize();
    return dir;
}
